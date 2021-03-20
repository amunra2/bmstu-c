#include"../inc/func.h"
#include"../inc/memwork.h"


int read_struct(FILE *f, product_t *products_inf, int *num_products)
{
    size_t len = 0;
    char *line = NULL;
    int check_read = getline(&line, &len, f);

    if (check_read == WRONG_WORD)
    {
        free(line);
        return ERR_READ_WORD;
    }
    else if (NULL == line)
    {
        return FILE_END;
    }

    products_inf[*num_products].name = line;

    LOG_DEBUG("%s", products_inf[*num_products].product);

    int check_mis = fscanf(f, "%d\n", &products_inf[*num_products].price);


    if (check_mis == ERR_FSCANF)
    {
        LOG_INFO("%s", "out");
        *num_products += 1;
        return WRONG_NUM;
    }
    else if (check_mis == EOF)
    {
        return FILE_END;
    }
    else if (products_inf[*num_products].price <= 0)
    {
        *num_products += 1;
        return NEGATIVE_PRICE;
    }

    *num_products += 1;

    return OK_READ_STRUCT;
}


int check_empty(FILE *f)
{
    if (fseek(f, 0, SEEK_END) != 0)
    {
        return ERR_FILE_CLEAR;
    }

    size_t current_size = ftell(f);

    if (current_size <= 0)
    {
        return ERR_FILE_CLEAR;
    }

    return fseek(f, 0, SEEK_SET);
}


int read_file(FILE *f, product_t **products_inf, int *num_products)
{
    LOG_INFO("%s", "Before clear");

    if (check_empty(f) != OK_FILE)
    {
        LOG_INFO("%s", "File is clear");
        return ERR_FILE_CLEAR;
    }

    LOG_INFO("%s", "After clear");

    int num;
    int check_mis = fscanf(f, "%d\n", &num);

    if ((check_mis != OK_NUM_OF_STRUCTS) || (num < NO_PRODUCTS))
    {
        return ERR_WRONG_NUM_PRODUCTS;
    }

    product_t *products_tmp = calloc(num * sizeof(product_t), sizeof(product_t));

    int rc = OK_STRUCT_READ;

    do
    {
        LOG_INFO("%s", "Ok read struct");
        rc = read_struct(f, products_tmp, num_products);
    } while (rc == OK_STRUCT_READ);

    if (rc == WRONG_NUM)
    {
        free_structs(products_tmp, *num_products);
        return WRONG_NUM;
    }
    else if (rc == WRONG_PRODUCT_NAME)
    {
        free_structs(products_tmp, *num_products);
        return WRONG_PRODUCT_NAME;
    }
    else if (rc == NEGATIVE_PRICE)
    {
        free_structs(products_tmp, *num_products);
        return NEGATIVE_PRICE;
    }

    if (num != *num_products)
    {
        free_structs(products_tmp, *num_products);
        return WRONG_NUM_STRUCTURES;
    }

    *products_inf = products_tmp;

    return OK_READING;
}


void print_product(product_t product)
{
    printf("%s", product.name);
    printf("%d\n", product.price);
}

int my_strlen(char *string)
{
    int i = 0;
    while (string[i++] != '\0')
    {
        ;
    }

    return i;
}


int copy_struct(product_t *struct1, product_t *struct2)
{
    char *tmp = strdup(struct1->name);

    if (!tmp)
    {
        return ERR_ALLOCATE_MEMORY;
    }

    struct2->name = tmp;
    struct2->price = struct1->price;

    return OK_COPY;
}


int filter_arr(product_t *products_inf, int *num_products, int price_limit, product_t **filtered_arr)
{
    if (price_limit <= 0)
    {
        return WRONG_PRICE;
    }

    int filtered_elems = 0;

    for (int i = 0; i < *num_products; i++)
    {
        if (price_limit > products_inf[i].price)
        {
            filtered_elems++;
        }
    }

    product_t *filtered_tmp = calloc(filtered_elems * sizeof(product_t), sizeof(product_t));

    if (!filtered_tmp)
    {
        free_structs(products_inf, *num_products);
        return ERR_ALLOCATE_MEMORY;
    }

    int k = 0;

    for (int i = 0; i < *num_products; i++)
    {
        if (price_limit > products_inf[i].price)
        {
            if (copy_struct(&products_inf[i], &filtered_tmp[k++]) != NO_MISTAKES)
            {
                return ERR_COPY_STRUCT;
            }
        }
    }

    free_structs(products_inf, *num_products);
    *filtered_arr = filtered_tmp;
    *num_products = filtered_elems;       

    return OK_FILTER;
}


void print_arr(product_t *prod_inf, int num_products)
{
    for (int i = 0; i < num_products; i++)
    {
        print_product(prod_inf[i]);
    }    
}


int parse_args(int argc, char *argv[], char **filename, int *limit_price)
{
    if (argc != AMOUNT_ARGS)
    {
        LOG_ERROR("ERR_NO_ARGS, code = %d", ERR_NO_ARGS);
        return ERR_NO_ARGS;
    }

    *filename = argv[1];

    int rc = sscanf(argv[2], "%d", limit_price);

    if (rc == ERR_READ_PRICE)
    {
        return ERR_WHILE_READING_PRICE;
    }

    if (*limit_price <= 0)
    {
        return WRONG_PRICE;
    }

    return OK_PARSE;
}
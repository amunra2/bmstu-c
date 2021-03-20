#include"func.h"


int read_struct(FILE *f, product_t *products_inf, int *num_products)
{
    char *check_first_field = fgets(products_inf[*num_products].product, LEN, f);
    
    if (check_first_field == NULL)
    {
        return FILE_END;
    }
    else if (check_first_field == ERR_FGETS)
    {
        return UNRIGHT_PRODUCT_NAME;
    }

    int check_mis = fscanf(f, "%d\n", &products_inf[*num_products].price);

    if (check_mis == ERR_FSCANF)
    {
        return UNRIGHT_NUM;
    }
    else if (check_mis == EOF)
    {
        return FILE_END;
    }
    else if (products_inf[*num_products].price <= 0)
    {
        return NEGATIVE_PRICE;
    }

    *num_products += 1;
    return OK_READ_STRUCT;
}


int check_clear(FILE *f)
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


int read_file(FILE *f, product_t *products_inf, int *num_products)
{
    if (check_clear(f) != OK_FILE)
    {
        return ERR_FILE_CLEAR;
    }

    int num;
    int check_mis = fscanf(f, "%d\n", &num);

    if ((check_mis != 1) || (num < NO_PRODUCTS) || (num > MAX_TASK_PRODUCTS))
    {
        return ERR_UNRIGHT_NUM_PRODUCTS;
    }

    int rc = OK_STRUCT_READ;

    do
    {
        rc = read_struct(f, products_inf, num_products);
    } while (rc == OK_STRUCT_READ);

    if (rc == UNRIGHT_NUM)
    {
        return UNRIGHT_NUM;
    }
    else if (rc == UNRIGHT_PRODUCT_NAME)
    {
        return UNRIGHT_PRODUCT_NAME;
    }
    else if (rc == NEGATIVE_PRICE)
    {
        return NEGATIVE_PRICE;
    }

    if (num != *num_products)
    {
        return UNRIGHT_NUM_STRUCTURES;
    }

    return OK_READING;
}


void print_product(product_t productt)
{
    printf("%s", productt.product);
    printf("%d\n", productt.price);
}


int print_under_price(product_t *products_inf, int num_products, int price_limit)
{
    if (price_limit <= 0)
    {
        return UNRIGHT_PRICE;
    }

    for (int i = 0; i < num_products; i++)
    {
        if (price_limit > products_inf[i].price)
        {
            print_product(products_inf[i]);
        }
    }
    return OK_PRINT;    
}
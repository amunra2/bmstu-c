#include"../inc/func.h"
#include"../inc/memwork.h"


int main(int argc, char *argv[])
{
    LOG_DEBUG("argc = %d", argc);
    setbuf(stdout, NULL);

    char *filename = NULL;
    int price_limit;

    int rc = parse_args(argc, argv, &filename, &price_limit);

    if (rc != NO_MISTAKES)
    {
        return rc;
    }

    LOG_DEBUG("argc = %d", argc);

    product_t *products_inf = NULL;

    FILE *f = fopen(filename, "r");

    if (f == NULL)
    {
        return ERR_FILE_OPEN;
    }

    int num_products = 0;
    
    rc = read_file(f, &products_inf, &num_products);

    LOG_DEBUG("%d", products_inf[0].price);

    if (fclose(f) != OK)
    {
        free_structs(products_inf, num_products);
        return ERR_FILE_CLOSE;
    }

    LOG_INFO("%s", "After read");

    if (rc != OK)
    {
        return rc;
    }

    LOG_INFO("%s", "Before print");
    
    product_t *filtered_arr = NULL;

    rc = filter_arr(products_inf, &num_products, price_limit, &filtered_arr);

    if (rc != OK)
    {
        free_structs(filtered_arr, num_products);
        return WRONG_PRICE;
    }

    print_arr(filtered_arr, num_products);

    LOG_INFO("%s", "After print");

    free_structs(filtered_arr, num_products);

    return OK;
}
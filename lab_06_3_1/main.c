#include"func.h"


int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);

    if (argc != AMOUNT_ARGS)
    {
        return ERR_NO_ARGS;
    }

    product_t products_inf[MAX_PRODUCTS];
    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
    {
        return ERR_FILE_OPEN;
    }

    int num_products = 0;
    int price_limit;

    int rc = sscanf(argv[2], "%d", &price_limit);

    if (rc == ERR_READ_PRICE)
    {
        return ERR_WHILE_READING_PRICE;
    }
    
    rc = read_file(f, products_inf, &num_products);

    if (fclose(f) != OK)
    {
        return ERR_FILE_CLOSE;
    }

    if (rc != OK)
    {
        return rc;
    }
    
    rc = print_under_price(products_inf, num_products, price_limit);

    if (rc == UNRIGHT_PRICE)
    {
        return UNRIGHT_PRICE;
    }

    return OK;
}
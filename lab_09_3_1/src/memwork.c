#include"../inc/memwork.h"


void free_structs(product_t *prod_inf, int len)
{
    for (int i = 0; i < len; i++)
    {
        free(prod_inf[i].name);
    }

    free(prod_inf);
}
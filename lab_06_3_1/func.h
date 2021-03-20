#include<stdio.h>
#include<stdlib.h>

#ifndef FUNC_H
#define FUNC_H

#define MAX_PRODUCTS 15000
#define MAX_TASK_PRODUCTS 15
#define NO_PRODUCTS 0
#define LEN 25
#define ERR_FSCANF 0
#define ERR_FGETS 0
#define OK_READ_STRUCT 0
#define OK_READING 0
#define OK_FILE 0
#define OK_PRINT 0
#define OK 0
#define FILE_END 1
#define AMOUNT_ARGS 3
#define OK_STRUCT_READ 0
#define ERR_READ_PRICE 0

#define ERR_FILE_CLEAR -1
#define UNRIGHT_NUM -2
#define UNRIGHT_PRICE -3
#define ERR_FILE_OPEN -4
#define ERR_NO_ARGS -5
#define ERR_UNRIGHT_NUM_PRODUCTS -6
#define UNRIGHT_NUM_STRUCTURES -7
#define UNRIGHT_PRODUCT_NAME -8
#define NEGATIVE_PRICE -9
#define ERR_FILE_CLOSE -10
#define ERR_WHILE_READING_PRICE -11


typedef struct
{
    char product[LEN + 1];
    int price;
} product_t;

int read_file(FILE *f, product_t *products_inf, int *num_products);

void print_struct(product_t *products_inf, int num_products);

int print_under_price(product_t *products_inf, int num_products, int price_limit);


#endif




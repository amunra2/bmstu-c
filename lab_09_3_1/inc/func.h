#define _GNU_SOURCE
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"macrologger.h"

#ifndef FUNC_H
#define FUNC_H

#define NO_PRODUCTS 0
#define LEN 25
#define ERR_FSCANF 0
#define ERR_FGETS 0
#define OK_READ_STRUCT 0
#define OK_READING 0
#define OK_FILE 0
#define OK_PRINT 0
#define OK_DELETE 0
#define OK_FILTER 0
#define OK_COPY 0
#define OK 0

#define FILE_END 1
#define AMOUNT_ARGS 3
#define OK_STRUCT_READ 0
#define ERR_READ_PRICE 0
#define WRONG_WORD -1
#define OK_PARSE 0
#define NO_MISTAKES 0
#define OK_NUM_OF_STRUCTS 1
#define ERR_FILE_CLEAR -1
#define WRONG_NUM -2
#define WRONG_PRICE -3
#define ERR_FILE_OPEN -4
#define ERR_NO_ARGS -5
#define ERR_WRONG_NUM_PRODUCTS -6
#define WRONG_NUM_STRUCTURES -7
#define WRONG_PRODUCT_NAME -8
#define NEGATIVE_PRICE -9
#define ERR_FILE_CLOSE -10
#define ERR_WHILE_READING_PRICE -11
#define ERR_READ_WORD -12
#define ERR_STRCPY -13
#define ERR_COPY_STRUCT -14


typedef struct
{
    char *name;
    int price;
} product_t;

int read_file(FILE *f, product_t **products_inf, int *num_products);

void print_struct(product_t *products_inf, int num_products);

void print_arr(product_t *prod_inf, int num_products);

int parse_args(int argc, char *argv[], char **filename, int *limit_price);

int filter_arr(product_t *products_inf, int *num_products, int price_limit, product_t **filtered_arr);

#endif




#include<check.h>
#include<stdio.h>
#include"../inc/func.h"
#include"../inc/memwork.h"

#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#define NO_MISTAKES 0

#define ERR_NOT_EQUAL_LENGTHS -1
#define ERR_ARRS_DIFFERENT -2
#define OK_COMPARE 0

#define MAX_WORD 50


int compare_arrs(product_t *arr1, int len1, product_t  *arr2, int len2);

Suite *read_suite(Suite *s);

#endif
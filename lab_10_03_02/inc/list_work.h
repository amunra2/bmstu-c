#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"../inc/macrologger.h"
#include"../inc/struct.h"
#include"../inc/read_print.h"


#ifndef LIST_WORK_H
#define LIST_WORK_H


#define NO_MISTAKES 0
#define NO_PRIME 0
#define PRIME 1
#define SEEK 1

#define OK_READ_NUM 1

#define OK_TRANSLATE 0
#define OK_PRINT_NUM 0
#define OK_PUSH_NODE 0
#define OK_POP 0
#define OK_MULTI 0
#define OK_DIV 0
#define OK_SQUARE 0

#define ERR_WRONG_NUM -3
#define ERR_ALLOCATE_MEMORY -4
#define ERR_TRANSLATE_NUM -5
#define ERR_ZERO_DIVISION -6
#define ERR_DIVISION -7
#define ERR_IMP_TRANSALATE -8
#define ERR_NO_PRIME_NUMS_LEFT_IN_INT -9
#define ERR_PUSH_NODE -10

int print_num(void);

int mult_nums(void);

int div_nums(void);

int square_num(void);

int translate_num(node_t **list, int num);

int multiply(node_t *list_a, node_t *list_b);

int division(node_t **res, int a, int b);

void free_list(node_t *list);
#endif
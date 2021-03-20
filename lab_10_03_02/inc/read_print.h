#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../inc/macrologger.h"
#include"../inc/struct.h"

#define WRONG_WORD -1
#define EQUAL 0
#define OUT 1
#define MUL 2
#define SQR 3
#define DIV 4
#define NO_TYPE 0

#define OK_READ_TYPE 0
#define OK_PRINT_LIST 0

#define ERR_READ_TYPE -1
#define ERR_WRONG_TYPE -2
#define ERR_LIST_EMPTY -3

#ifndef READ_PRINT_H
#define READ_PRINT_H


int read_type(int *type);

int print_list(node_t *list);




#endif
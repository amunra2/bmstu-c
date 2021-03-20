#include<stdio.h>
#include<stdlib.h>
#include"macrologger.h"
#include"struct.h"


#ifndef FUNC_H
#define FUNC_H

#define NO_MISTAKES 0

#define OK 0
#define OK_NODE 0

#define ERR_ARGS -1
#define ERR_NO_FILE -2
#define ERR_FILE_EMPTY -3
#define ERR_NODE -4
#define ERR_SYM -5
#define ERR_LIST_EMPTY -6

int read(FILE *f_in, node_t **list);

int print_list(node_t *list);

void free_list(node_t *list);

int print_list_file(FILE *f_out, node_t *list);

int reverse(node_t **list);

#endif

#include<stdio.h>
#include<stdlib.h>
#include"../inc/struct.h"
#include"../inc/macrologger.h"


#ifndef LIST_WORK_H
#define LIST_WORK_H

#define NO_MISTAKES 0

#define OK_PUSH_NODE 0
#define OK_SEEK 0
#define OK_NUM 1
#define OK_READ 0
#define OK_FILE 0
#define OK_LIST_CREATE 0
#define OK_WRITE_NUM 1
#define OK_WRITE 0
#define OK_PRINT_LIST 0

#define ERR_ALLOCATE_MEMORY -5
#define ERR_FILE_CLEAR -6
#define ERR_READ_NUM -7
#define ERR_NO_FILE -8
#define ERR_FILE_EMPTY -9
#define ERR_PUSH_NODE -10
#define ERR_LIST_EMPTY -11
#define ERR_WRITE_FILE -12
#define ERR_CLOSING_FILE -13
#define ERR_WRONG_AMOUNT_ELEMS -14


int fill_list(char *file_name, node_t **list, arr_t *arr);

int print_list(node_t *list);

void free_list(node_t *list);

void *pop_front(node_t **head);

void *pop_back(node_t **head);

node_t *reverse(node_t *head);

node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

int comparator(const void *a, const void* b);

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

int push_node_front(node_t **list, void *num);

int push_node_back(node_t **list, void *num);

int write_file_list(char *file_out_name, node_t *list);

#endif
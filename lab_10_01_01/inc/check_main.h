#include<check.h>
#include<stdio.h>
#include<assert.h>
#include"../inc/struct.h"
#include"../inc/list_work.h"
#include"../inc/macrologger.h"

#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#define NO_MISTAKES 0

#define OK_COMPARE 0
#define OK_MAKE_LIST 0

#define ERR_LISTS_DIFFERENT -1

#define MAX_WORD 50


int compare_lists(node_t *list1, node_t *list2);

int make_list(node_t **list, int *arr, int len);

Suite *pop_suite(Suite *s);

Suite *reverse_suite(Suite *s);

Suite *sort_suite(Suite *s);

#endif
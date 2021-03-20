#include<stdio.h>
#include<stdlib.h>
#include"../inc/struct.h"
#include"../inc/list_work.h"
#include"../inc/macrologger.h"

#ifndef TASK_H
#define TASK_H

#define OK_TASK 0
#define NO_MISTAKES 0
#define OK_PARSE_ARGS 0
#define OK_SWAP 0

#define ERR_UNRIGHT_ARGS -1
#define ERR_STRCPY -2
#define ERR_REVERSE_LIST -3
#define ERR_SORT_LIST -4

int execute_task(char *file_in_name, char *file_out_name);

int parse_args(int argc, char *argv[], char *file_in_name, char *file_out_name);


#endif
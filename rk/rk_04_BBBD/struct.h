#include<stdio.h>

#ifndef STRUCT_H
#define STRUCT_H

typedef struct node_r
{
    char data;

    struct node_r *next;
} node_t;


#endif
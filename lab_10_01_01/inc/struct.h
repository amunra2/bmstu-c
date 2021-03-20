#ifndef STRUCT_H
#define STRUCT_H

typedef struct node_r
{
    void *data;

    struct node_r *next;
} node_t;


typedef struct arr_r
{
    int *data;
    int len;
} arr_t;

#endif
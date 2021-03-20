#include<stdio.h>
#include<stdlib.h>
#ifndef ARRAY_H

#define ARRAY_H

#define MIN(a, b) (a > b ? b : a)
#define MAX(a, b) (a > b ? a : b)

#define MIN_ELEMS 3
#define OK_FILTER 0
#define OK_SIZE 0
#define YES 1
#define NO 0


#define ERR_THE_SAME_ELEMENTS -20
#define ERR_UNRIGHT_SIZE -21
#define ERR_NOT_ENOUGH_ELEMS_IN_ARRAY -22
#define ERR_NO_ELEMS -23
#define ERR_UNRIGHNT_INPUT -24
#define ERR_MEMORY_ALLOCATE -25

int key(int *pb_src, int *pe_src, int **pb_dst, int **pe_dst);

void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));

int compare(const void *p1, const void *p2);

int *find_min(int *pb_src, int *pe_src);

int *find_max(int *pb_src, int *pe_src);


#endif
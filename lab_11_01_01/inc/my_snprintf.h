#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<limits.h>
#include"../inc/macrologger.h"


#ifndef MY_SNPRINTF
#define MY_SNPRINTF

#define INT_LEN 20
#define UINT_LEN 20

#define BUF_LEN 100

#define HEXIDEMICAL 'x'
#define STRING 's'
#define CHAR 'c'
#define SHORT 'h'
#define INT 'd' 

#define OK 0

int translate_int(int data, char *str);

int translate_sixteen(unsigned int data, char *str);

int my_snprintf(char *str, size_t size, char *format, ...);

#endif

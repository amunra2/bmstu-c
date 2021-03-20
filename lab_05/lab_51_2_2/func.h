#ifndef FUNC_H
#define FUNC_H

#define NOT_ENOUGH_ARGUMENTS -1;
#define FILE_EXIST_ERR -2;
#define FILE_CLEAR_ERR -3;
#define OK 0;

double average(FILE *f, int *k);
double dispersia(FILE *f, int k, double avg);

#endif
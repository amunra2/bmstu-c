#include<stdio.h>
#include"func.h"


double average(FILE *f, int *k)
{
    double num, avg = 0;
    *k = 0;

    while (fscanf(f, "%lf", &num) == 1)
    {
        avg += num;
        *k += 1;
    }
    avg = avg / *k;
    return avg;
}


double dispersia(FILE *f, int k, double avg)
{
    double disp = 0, num;
    while (fscanf(f, "%lf", &num) == 1)
    {
        disp += ((num - avg) * (num - avg));
    }
    disp = disp / k;
    return disp;
}
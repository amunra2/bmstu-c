#include<stdio.h>
#include"func.h"


int process(FILE *f, int *count)
{
    int next_num, curr_num, prev_num, num, k = 1;

    *count = 0;

    if (fscanf(f, "%d", &prev_num) != 1)
    {
        return INPUT_IS_CLEAR;
    }
    fscanf(f, "%d", &curr_num);
    k++;

    while (fscanf(f, "%d", &num) == 1)
    {
        k++;
        next_num = num;
        if ((next_num < curr_num) && (prev_num < curr_num))
        {
            *count += 1;
        }
        prev_num = curr_num;
        curr_num = next_num;
    }

    if (k < 3)
    {
        return NOT_ENOUGH_NUMS;
    }

    return PROCESS_OK;
}
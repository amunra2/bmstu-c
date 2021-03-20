#include<stdio.h>
#include"func.h"



int main(int argc, char *argv[])
{
    FILE *f;

    if (argc != 2)
    {
        puts("Not enough arguments");
        return NOT_ENOUGH_ARGUMENTS;
    }

//  char in = argv[1];

    f = fopen(argv[1], "r");

    if (f == NULL)
    {
        puts("File does not exist");
        return FILE_EXIST_ERR;
    }

    float check;

    if (fscanf(f, "%f", &check) != 1)
    {
        puts("File is clear or first symbol is literal");
        return FILE_CLEAR_ERR;
    }

    fclose(f);
    f = fopen(argv[1], "r");

    int k;
    double avg = average(f, &k);

    fclose(f);
    f = fopen(argv[1], "r");
    double disp = dispersia(f, k, avg);

    printf("%lf", disp);

    fclose(f);
    return OK;
}
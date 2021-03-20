#include<stdio.h>
#include<string.h>
#include"func.h"



int main(int argc, char *argv[])
{
    FILE *f;

    if ((argc != 3) && (argc != 4))
    {
        puts("Not enough arguments");
        return NOT_ENOUGH_ARGUMENTS;
    }

    if (strcmp(argv[1], "c") == 0)
    {
        f = fopen(argv[3], "wb");
        create_bin(f, argv[2]);
        fclose(f);
        return OK;
    }

    if (strcmp(argv[1], "p") == 0)
    {
        f = fopen(argv[2], "rb");

        if (f == NULL)
        {
            puts("File does not exist");
            fclose(f);
            return FILE_EXIST_ERR;
        }

        int check_clear, check;

        if (fread(&check_clear, sizeof(int), 1, f) != 1)
        {
            puts("File is clear");
            fclose(f);
            return FILE_CLEAR_ERR;
        }
        fclose(f);
        f = fopen(argv[2], "rb");

        check = print_bin(f);
        if (check < 0)
        {
            fclose(f);
            return PRINTING_FAIL;
        }

        fclose(f);
    }
    
    if (strcmp(argv[1], "s") == 0)
    {
        f = fopen(argv[2], "r+b");

        if (f == NULL)
        {
            puts("File does not exist");
            fclose(f);
            return FILE_EXIST_ERR;
        }

        int check_clear;

        if (fread(&check_clear, sizeof(int), 1, f) != 1)
        {
            puts("File is clear");
            fclose(f);
            return FILE_CLEAR_ERR;
        }
        fclose(f);
        f = fopen(argv[2], "r+b");

        int check = sort_bin(f);

        if (check < 0)
        {
            fclose(f);
            return SORTING_FAIL;
        }
        fclose(f);
    }

    return OK;
}
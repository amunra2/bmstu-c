#include<stdio.h>
#include<string.h>
#include"func.h"


int main(int argc, char *argv[])
{
    FILE *f;
    FILE *h;

    if ((argc == 3) && (strcmp(argv[1], "sb") == 0))
    {
        f = fopen(argv[2], "r+b");

        if (f == NULL)
        {
            puts("File does not exist");
            return FILE_EXIST_ERR;
        }

        int check = sort_students(f);

        if (check < 0)
        {
            puts("Sorting fail");
            return SORTING_FAIL;
        }

        int rc = fclose(f);

        if (rc != 0)
        {
            return CLOSE_ERR;
        }
        return OK;
    }
    else if ((argc == 5) && (strcmp(argv[1], "fb") == 0))
    {
        f = fopen(argv[2], "rb");

        if (f == NULL)
        {
            puts("File does not exist");
            return FILE_EXIST_ERR;
        }

        h = fopen(argv[3], "wb");

        int check = find_students(f, h, argv[4]);

        if (check < 0)
        {
            puts("Finding fail");
            return FINDING_FAIL;
        }
        int rc = 0;
        rc += fclose(f);
        rc += fclose(h);

        if (rc != 0)
        {
            return CLOSE_ERR;
        }
        return OK;
    }
    else if ((argc == 3) && (strcmp(argv[1], "db") == 0))
    {
        f = fopen(argv[2], "r+b");

        if (f == NULL)
        {
            puts("File does not exist");
            return FILE_EXIST_ERR;
        }

        int check = delete_students(f);

        if (check < 0)
        {
            puts("Deleting fail");
            return DELETING_FAIL;
        }
        return OK;
    }
    else
    {
        return NOT_ENOUGH_ARGUMENTS;
    }
}


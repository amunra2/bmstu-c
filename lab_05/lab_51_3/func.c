#include<stdio.h>
#include<stdlib.h>
#include"func.h"



void create_bin(FILE *f, char *count_str)
{
    int num, count;
    sscanf(count_str, "%i", &count);

    while (count > 0)
    {
        num = rand();
        fwrite(&num, sizeof(int), 1, f);
        count--;
    }
}


int get_number_by_pos(FILE *f, size_t place)
{
    int num;
    fseek(f, place * sizeof(int), SEEK_SET);
    fread(&num, sizeof(int), 1, f);

    return num;
}


void put_number_by_pos(FILE *f, size_t place, int num)
{
    fseek(f, place * sizeof(int), SEEK_SET);
    fwrite(&num, sizeof(int), 1, f);
}


int size_of_file(FILE *f, size_t *size)
{
    if (fseek(f, 0, SEEK_END) != 0)
    {
        return MISTAKE_SIZE;
    }

    long current_size = ftell(f);

    if (current_size < 0)
    {
        return MISTAKE_SIZE;
    }

    *size = current_size;

    fseek(f, 0, SEEK_SET);
    return SIZE_OK;
}


void qsorting(FILE *f, size_t left, size_t right)
{
    size_t i = left, j = right;
    int pivot, tmp, num;
    size_t pos = left + (right - left) / 2;

    pivot = get_number_by_pos(f, pos);


    do
    {
        while (get_number_by_pos(f, i) < pivot)
        {
            i++;
        }

        while (get_number_by_pos(f, j) > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            if (get_number_by_pos(f, i) > get_number_by_pos(f, j))
            {
                tmp = get_number_by_pos(f, i);
                num = get_number_by_pos(f, j);
                put_number_by_pos(f, i, num);
                put_number_by_pos(f, j, tmp);
            }

            i++;

            if (j > 0)
            {
                j--;
            }
        }
    } while (i <= j);

    if (i < right)
    {
        qsorting(f, i, right);
    }

    if (j > left)
    {
        qsorting(f, left, j);
    }
}


int sort_bin(FILE *f)
{
    size_t left = 0, size;
    int check = size_of_file(f, &size);

    if ((check < 0) || (size % 4 != 0))
    {
        return MISTAKE_SIZE;
    }

    size_t right = size / sizeof(int) - 1;
    qsorting(f, left, right);

    return SORT_OK;
}


int print_bin(FILE *f)
{
    int num, rc;
    size_t size;

    rc = size_of_file(f, &size);

    if ((rc == MISTAKE_SIZE) || (size % 4 != 0))
    {
        return MISTAKE_SIZE;
    }
    for (size_t i = 0; i < size / sizeof(int); i++)
    {
        fread(&num, sizeof(int), 1, f);

        printf("%d ", num);
    }
    return PRINT_OK;
}
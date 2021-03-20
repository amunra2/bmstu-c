#include"../inc/sort_key.h"
#include"../inc/macrologger.h"


int *find_min(int *pb_src, int *pe_src)
{
    int *tmp = pb_src;
    int *el_min = pb_src;

    while (tmp < pe_src)
    {
        if (*tmp < *el_min)
        {
            el_min = tmp;
        }

        tmp++;
    }

    return el_min;
}


int *find_max(int *pb_src, int *pe_src)
{
    int *tmp = pb_src;
    int *el_max = pb_src;

    while (tmp < pe_src)
    {
        if (*tmp > *el_max)
        {
            el_max = tmp;
        }

        tmp++;
    }

    return el_max;
}


int check_size(int *pb_src, int *pe_src)
{
    int *tmp = pb_src;
    int count = 0;

    while (tmp < pe_src)
    {
        count++;
        tmp++;
    }

    if (count < MIN_ELEMS)
    {
        return ERR_NOT_ENOUGH_ELEMS_IN_ARRAY;
    }

    return OK_SIZE;
}


int key(int *pb_src, int *pe_src, int **pb_dst, int **pe_dst)
{
    int rc = check_size(pb_src, pe_src);

    if ((pb_src == NULL) || (pe_src == NULL) || (pb_src >= pe_src))
    {
        LOG_ERROR("Null pointer, code: %d", ERR_UNRIGHNT_INPUT);
        return ERR_UNRIGHNT_INPUT;
    }

    if (rc != OK_SIZE)
    {
        LOG_ERROR("Not enough elements in array, code %d", ERR_UNRIGHT_SIZE);
        return ERR_UNRIGHT_SIZE;
    }

    int *el_max = NULL;
    int *el_min = NULL;

    el_min = find_min(pb_src, pe_src);

    LOG_DEBUG("Min elem in array : %d", *el_min);

    el_max = find_max(pb_src, pe_src);

    LOG_DEBUG("Max elem in array : %d", *el_max);

    if (el_min == el_max)
    {
        LOG_ERROR("Max and min are the same, code %d", ERR_THE_SAME_ELEMENTS);
        return ERR_THE_SAME_ELEMENTS;
    }
    
    int *tmp_p = *pb_dst;

    int *pb = MIN(el_min, el_max);
    int *pe = MAX(el_min, el_max);


    while (pb++ < pe - 1)
    {
        *tmp_p = *pb;
        LOG_DEBUG("elm = %d", *tmp_p);
        tmp_p++;
    }

    *pe_dst = tmp_p;
    return OK_FILTER;
}


int compare(const void *p1, const void *p2)
{
    return *((int *) p1) - *((int *) p2);
}

void swap(char *el_1, char *el_2, size_t size)
{
    char tmp;

    while (size-- > 0)
    {
        tmp = *el_1;
        *el_1 = *el_2;
        *el_2 = tmp;

        el_1++;
        el_2++;
    }
}


void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *))
{
    char *tmp_begin = base;
    char *tmp_end = tmp_begin + size * (num - 1);

    char *begin_index = tmp_begin + size;
    char *zero_place = tmp_begin;

    char *rem_elm = tmp_end;

    do
    {
        for (char *elm = tmp_end; elm > zero_place; elm -= size)
        {
            if (compare(elm - size, elm) > 0)
            {
                swap(elm - size, elm, size);
                rem_elm = elm;
            }
        }

        tmp_begin = rem_elm;

        for (char *elm = begin_index; elm < tmp_end; elm += size)
        {
            if (compare(elm, elm + size) > 0)
            {
                swap(elm, elm + size, size);
                rem_elm = elm + size;
            }
        }

        tmp_end = rem_elm;
    } while (tmp_begin < tmp_end);
}


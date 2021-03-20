#include<stdio.h>
#include<limits.h>

#define NO_PRIME 0
#define PRIME 1


int check_prime(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return NO_PRIME;
        }
    }

    return PRIME;
}


int get_new_prime_num(int last_num)
{
    int count = 0;

    while (count++ < INT_MAX)
    {
        if (check_prime(++last_num))
        {
            return last_num;
        }
    }

    return last_num;
}


void fill_arr_prime_nums(int *arr, int size)
{
    int last_num = 1;

    for (int i = 0; i < size; i++)
    {
        last_num = get_new_prime_num(last_num);

        arr[i] = last_num;
    }
}


int add_after_even_nums(int *src, int *dst, int len_src, int len_dst, int num)
{
    int req_len = 0;

    for (int i = 0; i < len_src; i++)
    {
        if (src[i] % 2 == 0)
        {
            if (req_len + 2 <= len_dst)
            {
                dst[req_len] = src[i];
                dst[req_len + 1] = num;
            }

            req_len += 2;
        }
        else
        {
            if (req_len + 1 <= len_dst)
            {
                dst[req_len] = src[i];
            }

            req_len++;
        }
    }

    return req_len;
}

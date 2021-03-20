#include<stdio.h>
#include"my_strcspn.h"


size_t my_strcspn(const char *str, const char *sym)
{
    int flag = 0;
    size_t rem, i;
    for (i = 0; str[i] != '\0'; i++)
    {
        for (size_t j = 0; sym[j] != '\0'; j++)
        {
            if (str[i] == sym[j])
            {
                flag = 1;
                rem = i;
                break;
            }
        }

        if (flag == 1)
        {
            break;
        }
    }

    if (flag == 0)
    {
        return i;
    }
    return rem;
}
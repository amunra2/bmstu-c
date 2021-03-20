#include<stdio.h>
#include<math.h>
#include"../inc/matrix_work.h"

#define OK 0
#define NO_MISTAKES 0

int main(void)
{
    int rc = matrix_work();

    if (rc != NO_MISTAKES)
    {
        return rc;
    }

    return OK;
}
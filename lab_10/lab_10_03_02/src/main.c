#include"../inc/main_inc.h"


int main(void)
{
    int type = 0;

    int rc = read_type(&type);

    if (rc != NO_MISTAKES)
    {
        return rc;
    }

    LOG_DEBUG("%d", type);

    if (type == OUT)
    {
        rc = print_num();

        if (rc != NO_MISTAKES)
        {
            return rc;
        }
    }
    else if (type == MUL)
    {
        rc = mult_nums();

        if (rc != NO_MISTAKES)
        {
            return rc;
        }
    }
    else if (type == DIV)
    {
        rc = div_nums();

        if (rc != NO_MISTAKES)
        {
            return rc;
        }
    }
    else if (type == SQR)
    {
        rc = square_num();

        if (rc != NO_MISTAKES)
        {
            return rc;
        }        
    }
    
    return OK;
}
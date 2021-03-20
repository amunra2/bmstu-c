#include"../inc/my_snprintf.h"


void reverse_string(char *str, int ind)
{
    for (int i = 0; i < ind / 2; i++)
    {
        char tmp = str[i];
        str[i] = str[ind - i - 1];
        str[ind - i - 1] = tmp;
    }
}


int translate_int(int data, char *str)
{
    int ind = 0;

    if (data == 0)
    {
        str[ind++] = '0';
    }

    while (data != 0)
    {
        char ch = data % 10 + '0';

        data /= 10;

        str[ind++] = ch;
    }

    reverse_string(str, ind);

    if (ind != 0)
    {
        str[ind] = '\0';
    }

    return ind;
}


int translate_sixteen(unsigned int data, char *str)
{   
    int ind = 0;

    if (data == 0)
    {
        str[ind++] = '0';
    }

    while (data != 0)
    {
        int num = data % 16;

        if (num < 10)
        {
            str[ind++] = num + '0';
        }
        else
        {
            char ch = 'a';

            for (int i = 10; i < num; i++)
            {
                ch++;
            }

            str[ind++] = ch;
        }

        data /= 16;
    }

    reverse_string(str, ind);

    if (ind != 0)
    {
        str[ind] = '\0';
    }

    return ind;
}


int parse_short_int(int data, int size_limit, int *ind, char *str)
{
    int count = 0;

    if (data < 0)
    {
        if (size_limit > *ind)
        {
            str[(*ind)++] = '-';
        }

        count++;

        data *= -1;
    }

    char data_int[INT_LEN];

    LOG_DEBUG("%d", data);

    int len = translate_int(data, data_int);

    LOG_DEBUG("str = %s", data_int);

    int i = 0;

    while (i < len)
    {
        if (size_limit > *ind)
        {
            str[(*ind)++] = data_int[i];
        }

        count++;
        i++;
    }  

    return count;  
}


int parse_char(char sym, int size_limit, int *ind, char *str)
{
    int count = 0;
    
    if (size_limit > *ind)
    {
        str[(*ind)++] = sym;
    }

    count++;

    return count;
}


int parse_string(char *src, int size_limit, int *ind, char *str)
{
    int i = 0;

    while (src[i] != '\0')
    {
        if (size_limit > *ind)
        {
            str[(*ind)++] = src[i];
        }

        i++;
    }

    return i;
}


int parse_hexademical_num(unsigned int data, int size_limit, int *ind, char *str)
{
    char data_uint[UINT_LEN];

    int len = translate_sixteen(data, data_uint);

    int i = 0;

    while (i < len)
    {
        if (size_limit > *ind)
        {
            str[(*ind)++] = data_uint[i];
        }

        i++;
    }

    return i;
}


int my_snprintf(char *str, size_t size, char *format, ...)
{
    va_list vl;

    int ind = 0, format_count = 0;

    va_start(vl, format);

    while (*format != '\0')
    {
        LOG_DEBUG("form = %c", *format);

        if (*format == '%')
        {
            format++;

            if ((*format == SHORT) && (*(format + 1) == INT))
            {
                int data = va_arg(vl, int);

                format_count += parse_short_int(data, size, &ind, str);

                format += 2;
            }
            else if (*format == CHAR)
            {
                char sym = va_arg(vl, int);

                format_count += parse_char(sym, size, &ind, str);

                format++;
            }
            else if (*format == STRING)
            {
                char *data = va_arg(vl, char*);

                LOG_DEBUG("%s", data);

                format_count += parse_string(data, size, &ind, str);

                format++;
            }
            else if (*format == HEXIDEMICAL)
            {
                unsigned int data = va_arg(vl, unsigned int);

                format_count += parse_hexademical_num(data, size, &ind, str);

                format++;
            }
            else if (*format == '%')
            {
                if (size > ind)
                {
                    str[ind++] = *format;
                }

                format_count++;
                format++;
            }
        }
        else
        {
            if (size > ind)
            {
                str[ind++] = *format;
            }

            format_count++;
            format++;
        }
    }

    if ((size == ind) && (size != 0))
    {
        str[ind - 1] = '\0';
    }
    else if (size > 0)
    {
        str[ind] = '\0';
    }

    va_end(vl);

    return format_count;
}

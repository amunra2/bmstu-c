#include<stdio.h>
#include<string.h>
#include"func.h"

int input_string(char *str)
{
    int c, i = 0;
    
    while ((c = getchar()) != '\n')
    {
        if (c == EOF)
        {
            return UNRIGHT_STRING_INPUT;
        }
        str[i++] = c;
    }
    str[i] = '\0';
    return i;
}


void print_results(char line_one[][WORD_LENGTH + 1],
char line_two[][WORD_LENGTH + 1], const int words_one, const int words_two)
{
    printf("Result:\n");
    int check;
    for (int i = 0; i < words_one; i++)
    {
        check = check_line(line_one, line_two, words_two, i);

        if (check == WORD_IN_LINE_TWO)
        {
            check = repeated_word_in_first_line(line_one, i);
            if (check == PRINT)
            {
                printf("%s yes \n", line_one[i]);
            }
        }
        else
        {
            check = repeated_word_in_first_line(line_one, i);
            if (check == PRINT)
            {
                printf("%s no \n", line_one[i]);
            }
        }
    }
}
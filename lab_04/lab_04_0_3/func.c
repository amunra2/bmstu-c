#include<stdio.h>
#include<string.h>
#include"func.h"


int read_string_and_create_string(char *str, char words_array[][WORD_LENGTH + 1],
char *punct_sym)
{
    int i = 0, word_len;
    char *check = fgets(str, LINE_LENGTH + 1, stdin);

    if (check == NULL)
    {
        return UNRIGHT_STRING_INPUT;
    }

    if (strlen(str) >= LINE_LENGTH)
    {
        return STRING_TOO_LONG;
    }
    char *p = strtok(str, punct_sym);

    while (p != NULL)
    {
        word_len = strlen(p);

        if (word_len >= WORD_LENGTH)
        {
            return WORD_TOO_LONG;
        }

        strcpy(&words_array[i][0], p);
        words_array[i][strlen(p)] = '\0';
        p = strtok(NULL, punct_sym);

        i++;
    }

    if (i <= WORDS_CHECK)
    {
        return STRING_HAS_NO_WORDS;
    }
    return i;
}


void delete_literal(char *str, const int i)
{
    char k;
    for (int j = i; j < strlen(str) - 1; j++)
    {
        k = str[j];
        str[j] = str[j + 1];
        str[j + 1] = k;
    }
    str[strlen(str) - 1] = '\0';
}


void delete_repeats(char *str)
{
    for (int i = 1; str[i] != '\0'; i++)
    {
        if (str[0] == str[i])
        {
            delete_literal(str, i);
            
            if (str[0] == str[i])
            {
                i--;
            }
        }
    }
}


void check_words(char words_array[][WORD_LENGTH + 1], const int words)
{
    for (int i = 0; i < words; i++)
    {
        delete_repeats(words_array[i]);
    }
}


int create_new_string(char *new_str, char words_array[][WORD_LENGTH + 1], const int words)
{
    check_words(words_array, words);

    int check = 0, len, flag = 0, k = words - 1;
    for (int i = words - 1; i >= 0; i--)
    {
        check = strcmp(words_array[i], words_array[words - 1]);

        if (check != EQUAL_WORDS)
        {
            if (flag == 0)
            {
                strcpy(new_str, words_array[i]);
                
                len = strlen(new_str);

                new_str[len] = ' ';
                new_str[len + 1] = '\0';
                flag = 1;
            }
            else
            {
                strcat(new_str, words_array[i]);
                len = strlen(new_str);

                new_str[len] = ' ';
                new_str[len + 1] = '\0';
            }
        }
        else if (check == EQUAL_WORDS)
        {
            k--;
        }
    }
    
    if (k == NO_WORDS)
    {
        return NO_WORDS;
    }
    else
    {
        return NEW_STRING_IS_OK;
    }
}




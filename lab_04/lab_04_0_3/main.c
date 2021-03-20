#include<stdio.h>
#include<string.h>
#include"func.h"


int main()
{
    char str[LINE_LENGTH + 1], punct_sym[] = ",;:-.?! \n";
    char new_str[LINE_LENGTH + 1], words_array[LINE_LENGTH + 1][WORD_LENGTH + 1];
    int check;

    check = read_string_and_create_string(str, words_array, punct_sym);

    if (check == STRING_HAS_NO_WORDS)
    {
        printf("String has no words");
        return STRING_HAS_NO_WORDS;
    }
    else if (check == STRING_TOO_LONG)
    {
        printf("String too long");
        return STRING_TOO_LONG;
    }
    else if (check == WORD_TOO_LONG)
    {
        printf("Word too long");
        return WORD_TOO_LONG;
    }
    else if (check == UNRIGHT_STRING_INPUT)
    {
        printf("Unright string input");
        return UNRIGHT_STRING_INPUT;
    }

    check = create_new_string(new_str, words_array, check);

    if (check == NO_WORDS)
    {
        printf("New string has no words");
        return NEW_STRING_HAS_NO_WORDS;
    }
    
    printf("Result: %s\n", new_str);
    return OK;
}
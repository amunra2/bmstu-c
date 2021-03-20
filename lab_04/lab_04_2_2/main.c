#include<stdio.h>
#include"func.h"


int main()
{
    char line_of_words_one[MAX_WORDS][WORD_LENGTH + 1], line_of_words_two[MAX_WORDS][WORD_LENGTH + 1];
    char str_one[LINE_LENGTH], str_two[LINE_LENGTH];
    int word_one, word_two, len_1, len_2;

    len_1 = input_string(str_one);
    len_2 = input_string(str_two);

    if ((len_1 <= 0) || (len_2 <= 0) || (len_1 >= LINE_LENGTH) || (len_2 >= LINE_LENGTH))
    {
        printf("Unright string input");
        return UNRIGHT_STRING_INPUT;
    }

    word_one = words_from_line(str_one, line_of_words_one);
    word_two = words_from_line(str_two, line_of_words_two);

    if ((word_one == WORD_TOO_LONG) || (word_two == WORD_TOO_LONG))
    {
        printf("Word is too long");
        return WORD_LEN_ERROR;
    }

    if ((word_one == STRING_HAS_NO_WORDS) || (word_two == STRING_HAS_NO_WORDS))
    {
        printf("String has no words");
        return STRING_HAS_NO_WORDS_ERROR;
    }

    print_results(line_of_words_one, line_of_words_two, word_one, word_two);

    return OK;
}
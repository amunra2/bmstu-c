#include"func.h"

int check_symbol(char sym)
{
    char punct_sym[LINE_LENGTH + 1] = ",;:-.?! ";
    for (int i = 0; punct_sym[i] != '\0'; i++)
    {
        if (sym == punct_sym[i])
        {
            return UNRIGHT_SYMBOL;
        }
    }
    return RIGHT_SYMBOL;    
}


int words_from_line(char *str, char words[][WORD_LENGTH + 1])
{
    int w = 0, k = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (check_symbol(str[i]) == RIGHT_SYMBOL)
        {
            if (k > WORD_LENGTH)
            {
                return WORD_TOO_LONG;
            }
            words[w][k] = str[i];
            k++;
        }
        else
        {
            if (k != 0)
            {
                words[w][k] = '\0';
                w++;
                k = 0;
            }
        }
    }

    if (k != 0)
    {
        words[w][k] = '\0';
    }
    else
    {
        w--;
    }

    if ((w == 0) && (k == 0))
    {
        return STRING_HAS_NO_WORDS;
    }
    return w + 1;
}


int compare_words(char line_one[][WORD_LENGTH + 1], 
char line_two[][WORD_LENGTH + 1], const int num_one, const int num_two)
{
    int k = 0;
    for (int i = 0; line_one[num_one][i] != '\0'; i++)
    {
        k++;
        if (line_one[num_one][i] != line_two[num_two][i])
        {
            return DIFFERENT_WORDS;
        }
    }
    if (line_two[num_two][k] != '\0')
    {
        return DIFFERENT_WORDS;
    }
    return EQUAL_WORDS;
}


int check_line(char line_one[][WORD_LENGTH + 1], 
char line_two[][WORD_LENGTH + 1], const int word_two, const int first_line_num_word)
{
    int check, flag = 0;
    for (int j = 0; j < word_two; j++)
    {
        check = compare_words(line_one, line_two, first_line_num_word, j);

        if (check == EQUAL_WORDS)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        return WORD_IN_LINE_TWO;
    }
    else
    {
        return WORD_NOT_IN_LINE_TWO;
    }
}

int repeated_word_in_first_line(char line_one[][WORD_LENGTH + 1], const int first_line_num_word)
{
    int check;
    for (int j = 0; j < first_line_num_word; j++)
    {
        check = compare_words(line_one, line_one, first_line_num_word, j);
        if (check == EQUAL_WORDS)
        {
            return DO_NOT_PRINT;
        }
    }
    return PRINT;
}


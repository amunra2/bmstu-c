#ifndef FUNC_H
#define FUNC_H
#define LINE_LENGTH 256
#define WORD_LENGTH 16
#define MAX_WORDS 150
#define UNRIGHT_SYMBOL 1
#define RIGHT_SYMBOL 0
#define EQUAL_WORDS 0
#define DIFFERENT_WORDS 1

#define UNRIGHT_STRING_INPUT -1
#define WORD_IN_LINE_TWO 0
#define WORD_NOT_IN_LINE_TWO 1
#define DO_NOT_PRINT 1
#define PRINT 0
#define OK 0
#define WORD_TOO_LONG -1
#define WORD_LEN_ERROR 3
#define NO_WORDS 0
#define STRING_HAS_NO_WORDS -2
#define STRING_HAS_NO_WORDS_ERROR 4

int input_string(char *str);

int check_symbol(char sym);

int words_from_line(char *str, char words[][WORD_LENGTH + 1]);

int compare_words(char line_one[][WORD_LENGTH + 1], 
char line_two[][WORD_LENGTH + 1], const int num_one, const int num_two);

int check_line(char line_one[][WORD_LENGTH + 1], 
char line_two[][WORD_LENGTH + 1], const int word_two, const int first_line_num_word);

int repeated_word_in_first_line(char line_one[][WORD_LENGTH + 1], const int first_line_num_word);

void print_results(char line_one[][WORD_LENGTH + 1],
char line_two[][WORD_LENGTH + 1], const int words_one, const int words_two);

#endif
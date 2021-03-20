#ifndef FUNC_H
#define FUNC_H
#define OK 0
#define LINE_LENGTH 256
#define WORD_LENGTH 16
#define MAX_WORDS 150
#define WORDS_CHECK 1
#define EQUAL_WORDS 0
#define NO_WORDS_IN_NEW_STRING 1
#define NO_WORDS -1
#define NEW_STRING_IS_OK 0

#define UNRIGHT_STRING_INPUT -1
#define STRING_HAS_NO_WORDS -2
#define WORD_TOO_LONG -3
#define STRING_TOO_LONG -4
#define NEW_STRING_HAS_NO_WORDS -5

int read_string_and_create_string(char *str, char words_array[][WORD_LENGTH + 1],
char *punct_sym);

void delete_literal(char *str, const int i);

void delete_repeats(char *str);

void check_words(char words_array[][WORD_LENGTH + 1], const int words);

int create_new_string(char *new_str, char words_array[][WORD_LENGTH + 1], const int words);

#endif
#ifndef FUNC_H
#define FUNC_H

#define NOT_ENOUGH_ARGUMENTS 53
#define SORTING_FAIL -1
#define FILE_CLEAR_ERR -2
#define FILE_EXIST_ERR -3
#define FINDING_FAIL -4
#define DELETING_FAIL -5

#define FILE_FILL_ERR -1
#define MISTAKE_SIZE -1
#define LEN_ERR -2
#define SIZE_OK 0
#define OK 0
#define OK_SORT 0
#define OK_FIND 0
#define SUBSTR_RIGHT 0
#define NOTHING_TO_DELETE -1
#define NOBODY_WAS_FOUND -3
#define OK_DEL 0
#define EPS 1e-7

#define FILE_FUNC_ERR -2
#define OK_CHECK 0
#define FILE_ERR -1
#define CHECK_FILE_ERR -3
#define CLOSE_ERR -5


#define MARKS 4
#define SURNAME_LEN 25
#define NAME_LEN 10


typedef struct
{
    char surname[SURNAME_LEN + 1];
    char name[NAME_LEN + 1];
    unsigned int marks[MARKS];
} student_t;


int size_of_file(FILE *f, size_t *size);

int sort_students(FILE *f);
void func_sort(FILE *f, size_t size);
void print_bin(FILE *f);

int find_students(FILE *f, FILE *h, char *substr);

int delete_students(FILE *f);
double find_average(FILE *f, size_t size);
double avg_student(student_t student);


#endif
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include<sys/types.h>
#include"func.h"


int check_structures(FILE *f, student_t student, size_t size)
{
    int check_file = 0;

    for (size_t i = 0; i < size; i++)
    {
        check_file = fread(&student, sizeof(student_t), 1, f);

        if (check_file != 1)
        {
            return FILE_ERR;
        }
    }
    return OK_CHECK;
}


student_t get_student_by_pos(FILE *f, size_t place)
{
    student_t get_student;
    fseek(f, place * sizeof(student_t), SEEK_SET);
    fread(&get_student, sizeof(student_t), 1, f);

    return get_student;
}


void put_student_by_pos(FILE *f, size_t place, student_t put_student)
{
    fseek(f, place * sizeof(student_t), SEEK_SET);
    fwrite(&put_student, sizeof(student_t), 1, f);
}


int size_of_file(FILE *f, size_t *size)
{
    if (fseek(f, 0, SEEK_END) != 0)
    {
        return MISTAKE_SIZE;
    }

    size_t current_size = ftell(f);

    if (current_size < 0)
    {
        return MISTAKE_SIZE;
    }

    *size = current_size;

    fseek(f, 0, SEEK_SET);
    return SIZE_OK;
}


void func_sort(FILE *f, size_t size)
{
    student_t curr_student, next_student;
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = i + 1; j < size; ++j)
        {
            curr_student = get_student_by_pos(f, i);
            next_student = get_student_by_pos(f, j);

            if (strcmp(curr_student.surname, next_student.surname) > 0)
            {
                put_student_by_pos(f, j, curr_student);
                put_student_by_pos(f, i, next_student);
            }
            else if (strcmp(curr_student.surname, next_student.surname) == 0)
            {
                if (strcmp(curr_student.name, next_student.name) > 0)
                {
                    put_student_by_pos(f, i, next_student);
                    put_student_by_pos(f, j, curr_student);
                }
            }
        }
    }
}


void print_bin(FILE *f)
{
    size_t size = 0;
    size_of_file(f, &size);

    size = size / sizeof(student_t);

    student_t student;
    memset(&student, 0, sizeof(student_t));
    for (size_t i = 0; i < size; i++)
    {
        fread(&student, sizeof(student), 1, f);

        printf("%s ", student.surname);
        printf("%s\n", student.name);

        for (int j = 0; j < MARKS; j++)
        {
            printf("%u ", student.marks[j]);
        }
        puts("\n");
    }
}


int sort_students(FILE *f)
{
    size_t size = 0;
    int check_size = size_of_file(f, &size);

    if ((check_size < 0) || (size % sizeof(student_t) != 0) || (size == 0))
    {
        return FILE_FILL_ERR;
    }
    student_t student;

    int check_file = check_structures(f, student, size / sizeof(student_t));

    if (check_file != 0)
    {
        return CHECK_FILE_ERR;
    }

    size_t n = size / sizeof(student_t);

    func_sort(f, n);

    print_bin(f);

    return OK_SORT;
}


int find_students(FILE *f, FILE *h, char *substr)
{
    size_t size = 0;
    int check_size = size_of_file(f, &size);

    if ((check_size < 0) || (size % sizeof(student_t) != 0) || (size == 0))
    {
        return FILE_FILL_ERR;
    }
    student_t student;

    int check_file = check_structures(f, student, size / sizeof(student_t));

    if (check_file != 0)
    {
        return CHECK_FILE_ERR;
    }

    size_t i = 0, j = 0, n = size / sizeof(student_t);

    size_t len = strlen(substr);

    if (len <= 0)
    {
        return LEN_ERR;
    }

    while (i < n)
    {
        student = get_student_by_pos(f, i);

        if (strncmp(student.surname, substr, len) == SUBSTR_RIGHT)
        {
            put_student_by_pos(h, j, student);
            j++;
        }
        i++;
    }

    if (j == 0)
    {
        return NOBODY_WAS_FOUND;
    }
    return OK_FIND;
}


double avg_student(student_t student)
{
    double sum = 0;

    for (int i = 0; i < MARKS; i++)
    {
        sum += student.marks[i];
    }

    return sum / MARKS;
}


double find_average(FILE *f, size_t size)
{
    size_t i = 0;
    double avg = 0;

    student_t student;
    memset(&student, 0, sizeof(student_t));

    while (i < size)
    {
        student = get_student_by_pos(f, i);
        avg += avg_student(student);
        i++;
    }

    avg /= size;
    return avg;
}


int delete_students(FILE *f)
{
    size_t size = 0;
    int check_size = size_of_file(f, &size);

    if ((check_size < 0) || (size % sizeof(student_t) != 0) || (size <= 0))
    {
        return FILE_FILL_ERR;
    }
    student_t student;

    int check_file = check_structures(f, student, size / sizeof(student_t));

    if (check_file != 0)
    {
        return CHECK_FILE_ERR;
    }

    size_t i = 0, j = 0, n = size / sizeof(student_t);
    double curr_avg, avg = find_average(f, n);

    memset(&student, 0, sizeof(student_t));

    while (i < n)
    {
        student = get_student_by_pos(f, i);
        curr_avg = avg_student(student);
        if ((curr_avg > avg) || (fabs(curr_avg - avg) < EPS))
        {
            put_student_by_pos(f, j, student);
            j++;
        }
        i++;
    }

    if (j == 0)
    {
        return NOTHING_TO_DELETE;
    }
    int rc = 0;

    rc += fflush(f);
    rc += ftruncate(fileno(f), j * sizeof(student_t));
    rc += fclose(f);

    if (rc != 0)
    {
        return FILE_FUNC_ERR;
    }
    return OK_DEL;
}







#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"../inc/struct.h"
#include"../inc/macrologger.h"
#include"../inc/memory_work.h"


#ifndef PARSE_MATRIX_H

#define PARSE_MATRIX_H

#define OK_PARSE_MATRIX 0
#define OK_CHANGE_MATRIX 0
#define OK_DELETE_ROW 0
#define OK_DELETE_COL 0
#define OK_ADD_ROW 0
#define OK_ADD_COL 0

#define NO_MISTAKES 0

#define ROW_INDEX 0
#define COL_INDEX 1


int square_matrix(matrix_t *matrix);

int change_matrix_square(matrix_t *matrix, int size);

#endif
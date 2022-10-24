#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>


#define MAX_RANDOM 1e11
#define inf 0


typedef double element;

typedef struct matrix {
	int n;
	int m;
	element **data;

	bool initialized;
} matrix;

matrix matrix_make(int n, int m);

matrix matrix_ones    (int n, int m);
matrix matrix_zeros   (int n, int m);
matrix matrix_rand    (int n, int m);
matrix matrix_eye     (int n, int m);

matrix matrix_add_elementwise     (matrix *m1, matrix *m2);
matrix matrix_sub_elementwise     (matrix *m1, matrix *m2);
matrix matrix_mul_elementwise     (matrix *m1, matrix *m2);
matrix matrix_div_elementwise     (matrix *m1, matrix *m2);

element *matrix_diag              (matrix *m1);
element matrix_tr                 (matrix *m1);
element matrix_determinant        (matrix *m1);

matrix _matrix_cofactors     (matrix *m1, int skipi, int skipj);

matrix matrix_multiply       (matrix *m1, matrix *m2);

matrix matrix_adjunct        (matrix *m1);
matrix matrix_transpose      (matrix *m1);
matrix matrix_inverse        (matrix *m1);
matrix matrix_diagonal       (matrix *m1);
matrix matrix_orthogonal     (matrix *m1);

matrix matrix_apply       (element (*pf) (element ), matrix *m1);

matrix matrix_add_scalar     (matrix *m1, element e);
matrix matrix_sub_scalar     (matrix *m1, element e);
matrix matrix_mul_scalar     (matrix *m1, element e);
matrix matrix_div_scalar     (matrix *m1, element e);

bool check_equal_dimensions  (matrix *m1, matrix *m2);
bool check_dot_dimensions    (matrix *m1, matrix *m2);

bool check_square            (matrix *m1);

void   matrix_free(matrix *a);
void   matrix_fill(matrix *a);
void   matrix_disp(matrix *a);

#endif


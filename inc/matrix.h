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

matrix make_matrix(int n, int m);

matrix ones_matrix    (int n, int m);
matrix zeros_matrix   (int n, int m);
matrix rand_matrix    (int n, int m);
matrix eye_matrix     (int n, int m);

matrix add_matrix_elementwise     (matrix *m1, matrix *m2);
matrix sub_matrix_elementwise     (matrix *m1, matrix *m2);
matrix mul_matrix_elementwise     (matrix *m1, matrix *m2);
matrix div_matrix_elementwise     (matrix *m1, matrix *m2);

element *diag_matrix              (matrix *m1);
element tr_matrix                 (matrix *m1);
element determinant_matrix        (matrix *m1);

matrix _cofactors_matrix     (matrix *m1, int skipi, int skipj);

matrix multiply_matrix       (matrix *m1, matrix *m2);

matrix adjunct_matrix        (matrix *m1);
matrix transpose_matrix      (matrix *m1);
matrix inverse_matrix        (matrix *m1);
matrix diagonal_matrix       (matrix *m1);
matrix orthogonal_matrix     (matrix *m1);

matrix apply_on_matrix       (element (*pf) (element ), matrix *m1);

matrix add_matrix_scalar     (matrix *m1, element e);
matrix sub_matrix_scalar     (matrix *m1, element e);
matrix mul_matrix_scalar     (matrix *m1, element e);
matrix div_matrix_scalar     (matrix *m1, element e);

bool check_equal_dimensions  (matrix *m1, matrix *m2);
bool check_dot_dimensions    (matrix *m1, matrix *m2);

bool check_square            (matrix *m1);

void   free_matrix(matrix *a);
void   fill_matrix(matrix *a);
void   disp_matrix(matrix *a);

#endif


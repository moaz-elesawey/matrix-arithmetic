#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"
#include "tests.h"


int main(int argc, char **argv) {
	
	matrix m;

	m = make_matrix(4, 4);

	fill_matrix(&m);
	disp_matrix(&m);

	matrix o = ones_matrix(3, 3);
	disp_matrix(&o);

	matrix z = zeros_matrix(3, 3);
	disp_matrix(&z);

	matrix r = rand_matrix(3, 3);
	disp_matrix(&r);

	matrix I = eye_matrix(3, 3);
	disp_matrix(&I);

	matrix p = multiply_matrix(&r, &I);
	disp_matrix(&p);

	matrix t = transpose_matrix(&p);
	disp_matrix(&t);

	matrix a = apply_on_matrix(&exp, &I);
	disp_matrix(&a);

	test_multiply();

	element T = determinant_matrix(&m);
	disp_matrix(&m);
	printf("det(f) = %f\n", T);

	matrix adj_m = adjunct_matrix(&m);
	disp_matrix(&adj_m);

	matrix inv_m = inverse_matrix(&m);
	disp_matrix(&inv_m);

	free_matrix(&adj_m);
	free_matrix(&inv_m);
	free_matrix(&m);
	free_matrix(&o);
	free_matrix(&z);
	free_matrix(&r);
	free_matrix(&I);
	free_matrix(&p);
	free_matrix(&t);
	free_matrix(&a);

	return EXIT_SUCCESS;
}


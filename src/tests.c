#include "tests.h"

void test_multiply()
{
	matrix m1 = make_matrix(2, 1);
	fill_matrix(&m1);
	matrix m2 = make_matrix(1, 3);
	fill_matrix(&m2);

	matrix p = multiply_matrix(&m1, &m2);
	disp_matrix(&p);

	free_matrix(&m1);
	free_matrix(&m2);
	free_matrix(&p);

	return ;
}

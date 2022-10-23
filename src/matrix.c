#include "matrix.h"


matrix make_matrix(int n, int m)
{
	matrix a;
	a.n = n; a.m = m;

	a.data = (double **) calloc(n * m, sizeof(element));
	for(int i=0; i<n; i++)
		a.data[i] = (double *) calloc(m, sizeof(element));

	a.initialized = true;

	return a;
}

void free_matrix(matrix *a)
{
	if(!(a->initialized))
		return ;

	for(int i=0; i<a->n; i++)
		free(a->data[i]);

	free(a->data);

	return ;
}

void fill_matrix(matrix *a)
{
	for(int i=0; i<a->n; i++)
	{
		for(int j=0; j<a->m; j++)
		{
			scanf("%le", &(a->data[i][j]));
		}
	}

	return ;
}

void disp_matrix(matrix *a)
{
	for(int i=0; i<a->n; i++)
	{
		printf("|");
		for(int j=0; j<a->m; j++)
		{
			printf("%9.4f,", a->data[i][j]);
		}
		printf("|\n");
	}
	printf("\n");

	return ;
}


matrix ones_matrix(int n, int m)
{
	matrix a = make_matrix(n, m);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			a.data[i][j] = 1.0;
	}

	return a;
}

matrix zeros_matrix(int n, int m)
{
	matrix a = make_matrix(n, m);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			a.data[i][j] = 0.0;
	}

	return a;
}

matrix rand_matrix(int n, int m)
{
	time_t t;
	matrix a = make_matrix(n, m);

	srand((unsigned) time(&t));
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			a.data[i][j] = rand() / MAX_RANDOM;
	}

	return a;
}

matrix eye_matrix(int n, int m)
{
	matrix a = make_matrix(n, m);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			a.data[i][j] = 0.0;

			if(i == j)
				a.data[i][j] = 1.0;
		}
	}

	return a;
}

bool check_equal_dimensions  (matrix *m1, matrix *m2)
{
	return ((m1->n == m2->n) && (m1->m == m2->m));
}

bool check_dot_dimensions  (matrix *m1, matrix *m2)
{
	return (m1->m == m2->n);
}

matrix add_matrix_elementwise (matrix *m1, matrix *m2)
{
	if(!check_equal_dimensions(m1, m2))
		exit(EXIT_FAILURE);

	matrix out = make_matrix(m1->n, m1->m);

	for(int i=0; i<m1->n; i++)
	{
		for(int j=0; j<m1->m; j++)
			out.data[i][j] = m1->data[i][j] + m2->data[i][j];
	}

	return out;
}

matrix sub_matrix_elementwise(matrix *m1, matrix *m2)
{
	if(!check_equal_dimensions(m1, m2))
		exit(EXIT_FAILURE);

	matrix out = make_matrix(m1->n, m1->m);

	for(int i=0; i<m1->n; i++)
	{
		for(int j=0; j<m1->m; j++)
			out.data[i][j] = m1->data[i][j] - m2->data[i][j];
	}

	return out;
}

matrix mul_matrix_elementwise(matrix *m1, matrix *m2)
{
	if(!check_equal_dimensions(m1, m2))
		exit(EXIT_FAILURE);

	matrix out = make_matrix(m1->n, m1->m);

	for(int i=0; i<m1->n; i++)
	{
		for(int j=0; j<m1->m; j++)
			out.data[i][j] = m1->data[i][j] * m2->data[i][j];
	}

	return out;
}

matrix div_matrix_elementwise(matrix *m1, matrix *m2)
{
	if(!check_equal_dimensions(m1, m2))
		exit(EXIT_FAILURE);

	matrix out = make_matrix(m1->n, m1->m);

	for(int i=0; i<m1->n; i++)
	{
		for(int j=0; j<m1->m; j++)
			if(m2->data[i][j] == 0)
				out.data[i][j] = inf;
			else
				out.data[i][j] = m1->data[i][j] + m2->data[i][j];
	}

	return out;
}


matrix add_matrix_scalar (matrix *m1, element e)
{
	matrix out = make_matrix(m1->n, m1->m);

	for(int i=0; i<m1->n; i++)
	{
		for(int j=0; j<m1->m; j++)
			out.data[i][j] = m1->data[i][j] + e;
	}

	return out;
}

matrix sub_matrix_scalar(matrix *m1, element e)
{
	matrix out = make_matrix(m1->n, m1->m);

	for(int i=0; i<m1->n; i++)
	{
		for(int j=0; j<m1->m; j++)
			out.data[i][j] = m1->data[i][j] - e;
	}

	return out;
}

matrix mul_matrix_scalar(matrix *m1, element e)
{
	matrix out = make_matrix(m1->n, m1->m);

	for(int i=0; i<m1->n; i++)
	{
		for(int j=0; j<m1->m; j++)
			out.data[i][j] = m1->data[i][j] * e;
	}

	return out;
}

matrix div_matrix_scalar(matrix *m1, element e)
{
	matrix out = make_matrix(m1->n, m1->m);

	for(int i=0; i<m1->n; i++)
	{
		for(int j=0; j<m1->m; j++)
			if(e == 0)
				out.data[i][j] = inf;
			else
				out.data[i][j] = m1->data[i][j] + e;
	}

	return out;
}

matrix multiply_matrix(matrix *m1, matrix *m2)
{
	if(!check_dot_dimensions(m1, m2))
		exit(EXIT_FAILURE);
	
	matrix out = make_matrix(m1->n, m2->m);

	for(int k=0; k<m1->m; k++)
	{
		for(int i=0; i<m1->n; i++)
		{
			for(int j=0; j<m2->m; j++)
			{
				out.data[i][j] += (m1->data[i][k] * m2->data[k][j]);
			}
		}
	}

	return out;
}


bool check_square(matrix *m1)
{
	return (m1->n == m1->m);
}

element *diag_matrix(matrix *m1)
{
	if(!check_square(m1))
		exit(EXIT_FAILURE);

	element *diag = (element *) calloc(m1->n, sizeof(element));

	for(int i=0; i<m1->n; i++)
		diag[i] = m1->data[i][i];

	return diag;
}

element tr_matrix(matrix *m1)
{
	if(!check_square(m1))
		exit(EXIT_FAILURE);

	element tr = 0.0;

	for(int i=0; i<m1->n; i++)
		tr += m1->data[i][i];

	return tr;
}

matrix _cofactors_matrix(matrix *m1, int skipi, int skipj)
{
	matrix out = make_matrix(m1->n, m1->m);

	int i = 0, j = 0;

	for(int r=0; r<m1->n; r++)
	{
		for(int c=0; c<m1->m; c++)
		{
			if(r != skipi && c != skipj)
			{
				out.data[i][j++] = m1->data[r][c];

				if(j == (m1->n)-1)
				{
					j = 0;
					i++;
				}
			}
		}
	}

	out.n--;
	out.m--;

	return out;
}

element determinant_matrix(matrix *m1)
{
	int sign = 1;

	element det = 0;

	if (m1->n == 2)
		return m1->data[0][0]*m1->data[1][1] - m1->data[1][0]*m1->data[0][1];

	matrix c;

	for(int f=0; f<m1->n; f++)
	{
		c = _cofactors_matrix(m1, 0, f);
		det += sign * m1->data[0][f] * determinant_matrix(&c);

		sign = -sign;
	}

	free_matrix(&c);

	return det;
}

matrix adjunct_matrix(matrix *m1)
{
	matrix out = make_matrix(m1->n, m1->m);

	matrix factor;

	for(int r=0; r<m1->n; r++)
	{
		for(int c=0; c<m1->m; c++)
		{
			factor = _cofactors_matrix(m1, r, c);
			out.data[r][c] = pow(-1, r+c) * determinant_matrix(&factor);
		}
	}

	free_matrix(&factor);

	matrix trans_out = transpose_matrix(&out);
	free_matrix(&out);

	return trans_out;
}

matrix transpose_matrix(matrix *m1)
{
	if(!check_square(m1))
		exit(EXIT_FAILURE);

	matrix out = make_matrix(m1->n, m1->n);

	for(int i=0; i<m1->n; i++)
	{
		for(int j=0; j<m1->m; j++)
		{
			out.data[i][j] = m1->data[j][i];
		}
	}

	return out;
}
matrix inverse_matrix(matrix *m1)
{
	if(!check_square(m1))
		exit(EXIT_FAILURE);

	matrix out = make_matrix(m1->n, m1->n);

	element det = determinant_matrix(m1);
	matrix adj_m = adjunct_matrix(m1);

	matrix inv = mul_matrix_scalar(&adj_m, 1.0/det);

	free_matrix(&adj_m);
	free_matrix(&out);

	return inv;
}

matrix diagonal_matrix(matrix *m1)
{
	if(!check_square(m1))
		exit(EXIT_FAILURE);

	matrix out = make_matrix(m1->n, m1->n);

	for(int i=0; i<m1->n; i++)
	{
		for(int j=0; j<m1->m; j++)
		{
			out.data[i][j] = m1->data[j][i];
		}
	}

	return out;
}

matrix orthogonal_matrix(matrix *m1)
{
	if(!check_square(m1))
		exit(EXIT_FAILURE);

	matrix out = make_matrix(m1->n, m1->n);

	for(int i=0; i<m1->n; i++)
	{
		for(int j=0; j<m1->m; j++)
		{
			out.data[i][j] = m1->data[j][i];
		}
	}

	return out;
}

matrix apply_on_matrix(element (*pf) (element ), matrix *m1)
{
	matrix out = make_matrix(m1->n, m1->n);

	for(int i=0; i<m1->n; i++)
	{
		for(int j=0; j<m1->m; j++)
		{
			out.data[i][j] = pf(m1->data[i][j]);
		}
	}

	return out;
}



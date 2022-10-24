# matric arithmetic
matrix arithmetic is a collection of operations (e.g inv, det, adj, etc...) built in c from scratch.

## Build
```sh
$ cd matrix
$ make all
```

## Install
add the compiled library path to the **LD_LBRARY_PATH** in `linux`
```sh
$ export LD_LIBRARY_PATH=<repo-path>/matrix/lib
```

## Example
copy or write the following code into `main.c` in the same directory of the repo.

```c
#include "matrix.h"

int main(int argc, char *argv)
{
	// create a matrix with 3x3
	matrix m = matrix_make(3, 3);

	// fill the matrix form command line
	matrix_fill(&m);

	// display the matrix m
	matrix_disp(&m);

	// calculate inverse of the matrix
	matrix inv = matrix_inverse(&m)

	// dislplay matrix inv
	matrix_disp(&inv);

	// free the memeory form the matrecies
	matrix_free(&m);
	matrix_free(&inv);
}
```

run this to build and run the example code.
```sh
$ gcc -g -Wall -Werror main.c -Lmatrix/lib -Imatrix/inc -o main -lmatrix -lc -lm
$ ./main
```



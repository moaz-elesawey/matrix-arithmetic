
all: main

main: main.c
	gcc -g -Wall -Werror main.c -Lmatrix/lib -Imatrix/inc -o main -lmatrix -lc -lm

clean:
	rm main


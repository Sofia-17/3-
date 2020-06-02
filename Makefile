t: main.o input.o solver.o Makefile
	gcc -o t main.o input.o solver.o
main.o: main.c fun.h Makefile
	gcc -c main.c
input.o: input.c fun.h Makefile
	gcc -c input.c
solver.o: solver.c fun.h Makefile
	gcc -c solver.c
clean:
	rm t main.o input.o solver.o
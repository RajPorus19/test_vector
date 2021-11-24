# clean before recompiling everything
all : clean myprog
	./myprog

myprog : main.o vector.o
	gcc vector.o main.o -o myprog
vector.o : vector.c vector.h
	gcc vector.c -Wall -Wextra -c -o vector.o
main.o :
	gcc main.c -Wall -Wextra -c -o main.o

clean :
	rm -f *.o
	rm -f myprog

# clean before recompiling everything
all : clean myprog
	./myprog

test:
	make
	valgrind ./myprog

myprog : test_vector.o vector.o
	gcc vector.o test_vector.o -o myprog
vector.o : vector.c vector.h
	gcc vector.c -Wall -Wextra -c -o vector.o
test_vector.o :
	gcc test_vector.c -Wall -Wextra -c -o test_vector.o

clean :
	rm -f *.o
	rm -f myprog

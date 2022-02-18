# clean before recompiling everything
all : clean test_vector
	./test_vector

main: test_vector

test:
	make
	valgrind ./test_vector

vector.o : vector.c vector.h
	gcc vector.c -Wall -Wextra -c -o vector.o
test_vector.o :
	gcc test_vector.c -Wall -Wextra -c -o test_vector.o
test_vector: test_vector.o vector.o
	gcc vector.o test_vector.o -o test_vector

clean :
	rm -f *.o
	rm -f test_vector

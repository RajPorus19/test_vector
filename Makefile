# clean before recompiling everything
all : main 
	./test_random
	./test_vector

test:
	make
	valgrind ./test_random
	valgrind ./test_vector

main: test_vector.o test_random.o vector.o random.o
	gcc vector.o test_vector.o -o test_vector
	gcc random.o test_random.o -o test_random
vector.o : vector.c vector.h
	gcc vector.c -Wall -Wextra -c -o vector.o
random.o : random.c random.h
	gcc random.c -Wall -Wextra -c -o random.o
test_vector.o :
	gcc test_vector.c -Wall -Wextra -c -o test_vector.o
test_random.o :
	gcc test_random.c -Wall -Wextra -c -o test_random.o

clean :
	rm -f *.o
	rm -f test_vector test_random

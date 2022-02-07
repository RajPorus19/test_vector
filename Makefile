# clean before recompiling everything
all : clean main 
	./test_random
	./test_vector

test:
	make
	valgrind ./test_random
	valgrind ./test_vector

main: test_vector.o test_random.o vector.o random.o bench_vector.o
	gcc vector.o test_vector.o -o test_vector
	gcc random.o test_random.o -o test_random
	gcc bench_vector.o vector.o random.o -g -o bench_vector

vector.o : vector.c vector.h
	gcc vector.c -Wall -Wextra -c -o vector.o
random.o : random.c random.h
	gcc random.c -Wall -Wextra -c -o random.o
test_vector.o :
	gcc test_vector.c -Wall -Wextra -c -o test_vector.o
test_random.o :
	gcc test_random.c -Wall -Wextra -c -o test_random.o
bench_vector.o : bench_vector.c
	gcc -Wall -Wextra -g -c bench_vector.c

clean :
	rm -f *.o
	rm -f test_vector test_random

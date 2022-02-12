# clean before recompiling everything
all : clean main 
	./test_random
	./test_vector

test:
	make
	valgrind ./test_random
	valgrind ./test_vector

main: test_vector.o test_random.o vector.o random.o bench_vector.o my_struct.o test_my_struct.o
	gcc vector.o test_vector.o -o test_vector
	gcc random.o test_random.o -o test_random
	gcc bench_vector.o vector.o random.o -g -o bench_vector
	gcc my_struct.o test_my_struct.o -o test_my_struct

vector.o : vector.c vector.h
	gcc vector.c -Wall -Wextra -c -o vector.o
random.o : random.c random.h
	gcc random.c -Wall -Wextra -c -o random.o
my_struct.o : my_struct.c my_struct.h
	gcc my_struct.c -Wall -Wextra -c -o my_struct.o

test_vector.o :
	gcc test_vector.c -Wall -Wextra -c -o test_vector.o
test_random.o :
	gcc test_random.c -Wall -Wextra -c -o test_random.o
test_my_struct.o :
	gcc test_my_struct.c -Wall -Wextra -c -o test_my_struct.o

bench_vector.o : bench_vector.c
	gcc -Wall -Wextra -g -c bench_vector.c

clean :
	rm -f *.o
	rm -f test_vector test_random bench_vector test_my_struct

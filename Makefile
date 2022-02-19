# clean before recompiling everything
main: clean test_vector test_random bench_vector test_vector_v2 bench_vector_v2 test_my_struct

all : main
	./test_vector
	./test_random
	./bench_vector 10 10
	./test_vector_v2
	./bench_vector_v2 10 10
	./test_my_struct

test: main
	valgrind ./test_vector
	valgrind ./test_random
	valgrind ./test_vector_v2
	valgrind ./test_my_struct

bench: main
	time valgrind ./bench_vector 10 10
	time valgrind ./bench_vector_v2 10 10

clean :
	rm -f *.o
	rm -f test_vector test_random bench_vector
	rm -f test_vector_v2 bench_vector_v2
	rm -f test_my_struct

# vector
vector.o : vector.c vector.h
	gcc vector.c -Wall -Wextra -c -o vector.o
test_vector.o :
	gcc test_vector.c -Wall -Wextra -c -o test_vector.o
test_vector: test_vector.o vector.o my_struct.o random.o
	gcc vector.o test_vector.o my_struct.o random.o -o test_vector

# random
random.o : random.c random.h
	gcc random.c -Wall -Wextra -c -o random.o
test_random.o :
	gcc test_random.c -Wall -Wextra -c -o test_random.o
test_random: test_random.o random.o
	gcc random.o test_random.o -o test_random

# bench_vector
bench_vector.o : bench_vector.c
	gcc -Wall -Wextra -g -c bench_vector.c
bench_vector : bench_vector.o vector.o random.o
	gcc bench_vector.o vector.o random.o -g -o bench_vector

# vector_v2
vector_v2.o : vector.c vector.h
	gcc -Wall -Wextra -g -c vector.c -D V2 -o vector_v2.o
test_vector_v2.o : test_vector.c
	gcc -Wall -Wextra -g -c test_vector.c -D V2 -o test_vector_v2.o
test_vector_v2 : test_vector_v2.o vector_v2.o
	gcc test_vector_v2.o vector_v2.o -g -o test_vector_v2

# bench_vector_v2
bench_vector_v2.o : bench_vector.c
	gcc -Wall -Wextra -g -c bench_vector.c -D V2 -o bench_vector_v2.o
bench_vector_v2 : bench_vector_v2.o vector_v2.o random.o
	gcc bench_vector_v2.o vector_v2.o random.o -g -o bench_vector_v2

# my_struct
my_struct.o : my_struct.c my_struct.h
	gcc my_struct.c -Wall -Wextra -c -o my_struct.o
test_my_struct.o :
	gcc test_my_struct.c -Wall -Wextra -c -o test_my_struct.o
test_my_struct: test_my_struct.o my_struct.o random.o
	gcc my_struct.o test_my_struct.o random.o -o test_my_struct
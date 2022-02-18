# clean before recompiling everything
main: clean test_vector test_random bench_vector test_vector_v2 bench_vector_v2

all : main
	./test_vector
	./test_random
	./bench_vector 10 10
	./test_vector_v2
	./bench_vector_v2 10 10

test: main
	valgrind ./test_vector
	valgrind ./test_random
	valgrind ./test_vector_v2

bench: main
	time valgrind ./bench_vector 10 10

clean :
	rm -f *.o
	rm -f test_vector test_random bench_vector
	rm -f test_vector_v2 bench_vector_v2

# vector
vector.o : vector.c vector.h
	gcc vector.c -Wall -Wextra -c -o vector.o
test_vector.o :
	gcc test_vector.c -Wall -Wextra -c -o test_vector.o
test_vector: test_vector.o vector.o
	gcc vector.o test_vector.o -o test_vector

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
all: binary_search

binary_search: main.o binary_search.o unity.o
	gcc -o binary_search binary_search.o main.o -std=c99 -Wall -Wextra -Wno-unused-result -Wpedantic -O0

binary_search.o: binary_search.c binary_search.h
	gcc -c binary_search.c -std=c99 -Wall -Wextra -Wno-unused-result -Wpedantic -O0

main.o: main.c binary_search.h unity.h unity_internals.h
	gcc -c main.c -std=c99 -Wall -Wextra -Wno-unused-result -Wpedantic -O0

unity.o: unity.c unity.h unity_internals.h
	gcc -c unity.c

clean:
	rm -f binary_search *.o

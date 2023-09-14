all: binary_search
	./binary_search

binary_search: main.o binary_search.o compare.o unity.o tests_down.o tests_top.o tests.o
	gcc -o binary_search binary_search.o main.o compare.o tests_down.o tests_top.o tests.o unity.o -std=c99 -Wall -Wextra -Wno-unused-result -Wpedantic -O0

binary_search.o: binary_search.c src/binary_search.h
	gcc -c binary_search.c -std=c99 -Wall -Wextra -Wno-unused-result -Wpedantic -O0

compare.o: src/compare.c src/binary_search.h
	gcc -c src/compare.c -std=c99 -Wall -Wextra -Wno-unused-result -Wpedantic -O0

main.o: src/main.c src/binary_search.h unity/unity.h unity/unity_internals.h
	gcc -c src/main.c -std=c99 -Wall -Wextra -Wno-unused-result -Wpedantic -O0

tests_down.o: src/tests_down.c src/binary_search.h unity/unity.h unity/unity_internals.h
	gcc -c src/tests_down.c -std=c99 -Wall -Wextra -Wno-unused-result -Wpedantic -O0

tests_top.o: src/tests_top.c src/binary_search.h unity/unity.h unity/unity_internals.h
	gcc -c src/tests_top.c -std=c99 -Wall -Wextra -Wno-unused-result -Wpedantic -O0

tests.o: src/tests.c src/binary_search.h unity/unity.h unity/unity_internals.h
	gcc -c src/tests.c -std=c99 -Wall -Wextra -Wno-unused-result -Wpedantic -O0

unity.o: unity/unity.c unity/unity.h unity/unity_internals.h
	gcc -c unity/unity.c

clean:
	rm -f binary_search *.o

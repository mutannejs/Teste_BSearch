all: binary_search
	./binary_search f

binary_search: main.o binary_search.o compare.o unity.o tests_floor.o tests_ceil.o tests.o
	@ gcc -o binary_search binary_search.o main.o compare.o tests_floor.o tests_ceil.o tests.o unity.o -std=c99 -Wall -Wextra -Wno-unused-result -Wpedantic -O0

binary_search.o: binary_search.c src/binary_search.h
	@ gcc -c binary_search.c -std=c99 -Wall -Wextra -Wno-unused-result -Wpedantic -O0

compare.o: src/compare.c src/binary_search.h
	@ gcc -c src/compare.c -std=c99 -Wall -Wextra -Wno-unused-result -Wpedantic -O0

main.o: src/main.c src/binary_search.h unity/unity.h unity/unity_internals.h
	@ gcc -c src/main.c -std=c99 -Wall -Wextra -Wno-unused-result -Wpedantic -O0

tests_floor.o: src/tests_floor.c src/binary_search.h unity/unity.h unity/unity_internals.h
	@ gcc -c src/tests_floor.c -std=c99 -Wall -Wextra -Wno-unused-result -Wpedantic -O0

tests_ceil.o: src/tests_ceil.c src/binary_search.h unity/unity.h unity/unity_internals.h
	@ gcc -c src/tests_ceil.c -std=c99 -Wall -Wextra -Wno-unused-result -Wpedantic -O0

tests.o: src/tests.c src/binary_search.h unity/unity.h unity/unity_internals.h
	@ gcc -c src/tests.c -std=c99 -Wall -Wextra -Wno-unused-result -Wpedantic -O0

unity.o: unity/unity.c unity/unity.h unity/unity_internals.h
	@ gcc -c unity/unity.c

clean:
	@ rm -f binary_search *.o

#include "binary_search.h"

void setUp() {}

void tearDown() {}

basics set_basics(int is_notfound) {

	basics b;

	lli primos[] = {3, 5, 7, 11, 13, 17, 19};

	for (int i = 0; i < 6; i++) {
		b.vector[i] = primos[i];
	}

	for (int i = 0; i < 7; i++) {
		if (!is_notfound)
			b.keys[i] = primos[i];
		else
			b.keys[i] = primos[i]-1;
	}

	for (int i = 0; i < 6; i++)
		b.path_retorned[i] = -1;

	return b;

}

void test_compare(int qtd, basics b, int len_path[], int path_expected[][3]) {

	lli *ret;

	for (int i = 0; i < qtd; i++) {
		ret = binary_search(&b.keys[i], b.vector, qtd, sizeof(lli), cmp, b.path_retorned, 0);
		TEST_ASSERT_EQUAL_INT(b.keys[i], *ret);
		TEST_ASSERT_EQUAL_INT_ARRAY(path_expected[i], b.path_retorned, len_path[i]);
	}

}

void test_top_empty() {

	basics b = set_basics(0);
	lli *ret;
	int qtd = 0;

	ret = binary_search(&b.keys[0], b.vector, qtd, sizeof(lli), cmp, b.path_retorned, 0);

	TEST_ASSERT_EACH_EQUAL_INT(-1, b.path_retorned, 1);
	TEST_ASSERT_NULL(ret);

}

void test_top_six() {

	basics b = set_basics(0);
	int qtd = 6;
	int len_path[] = {3, 2, 3, 1, 3, 2};
	int path_expected[6][3] = {
		{11, 5, 3},
		{11, 5},
		{11, 5, 7},
		{11},
		{11, 17, 13},
		{11, 17} };

	test_compare(qtd, b, len_path, path_expected);

}

#include "binary_search.h"

void setUp() {}

void tearDown() {}

void test_top_empty() {

	lli v[1] = {0};
	lli key = 2;
	int qtd = 0;
	int *path = malloc(sizeof(int)*1);
	path[0] = -1;

	lli *ret = binary_search(&key, &v, 0, sizeof(lli), cmp, path, 0);

	TEST_ASSERT_EACH_EQUAL_INT(-1, path, 1);
	TEST_ASSERT_NULL(ret);

}

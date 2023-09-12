#include "binary_search.h"

int main(int argc, char *argv[]) {

	int istop = 1;

	if (argc == 2 && !strcmp(argv[1], "0"))
		istop = 0;

	UNITY_BEGIN();

	RUN_TEST(test_empty);
	RUN_TEST(test_one);
	RUN_TEST(test_one_nopath);
	RUN_TEST(test_one_not_found);
	RUN_TEST(test_one_not_found_bef);
	RUN_TEST(test_one_not_found_next);

	if (istop == 1) {
		RUN_TEST(test_top_six);
	}

	return UNITY_END();

}

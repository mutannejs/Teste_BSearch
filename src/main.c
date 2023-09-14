#include "binary_search.h"

int main(int argc, char *argv[]) {

	int istop = 1;
	int notfound = 0;

	if (argc >= 2 && !strcmp(argv[1], "d"))
		istop = 0;

	if (argc >= 3) {
		if (!strcmp(argv[2], "-1"))
			notfound = -1;
		else if (!strcmp(argv[2], "1"))
			notfound = 1;
		else if (!strcmp(argv[2], "2"))
			notfound = 2;
	}

	printf("\nTestes:\n\n");

	UNITY_BEGIN();

	RUN_TEST(test_empty);
	RUN_TEST(test_one);
	RUN_TEST(test_one_nopath);
	RUN_TEST(test_one_not_found);
	RUN_TEST(test_one_not_found_bef);
	RUN_TEST(test_one_not_found_next);

	if (istop == 1) {
		RUN_TEST(test_top_four);
		RUN_TEST(test_top_five);
		RUN_TEST(test_top_six);
		RUN_TEST(test_top_seven);
		if (notfound == -1 || notfound == 2) {
			RUN_TEST(test_top_four_not_found_bef);
			RUN_TEST(test_top_five_not_found_bef);
			RUN_TEST(test_top_six_not_found_bef);
			RUN_TEST(test_top_seven_not_found_bef);
		}
		if (notfound == 0 || notfound == 2) {
			RUN_TEST(test_top_four_not_found);
			RUN_TEST(test_top_five_not_found);
			RUN_TEST(test_top_six_not_found);
			RUN_TEST(test_top_seven_not_found);
		}
		if (notfound == 1 || notfound == 2) {
			RUN_TEST(test_top_four_not_found_next);
			RUN_TEST(test_top_five_not_found_next);
			RUN_TEST(test_top_six_not_found_next);
			RUN_TEST(test_top_seven_not_found_next);
		}
	}

	return UNITY_END();

}

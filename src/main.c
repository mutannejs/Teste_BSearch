#include "binary_search.h"

int main(int argc, char *argv[]) {

	int isceil = 1; // arredondamento para cima?
	int notfound[] = {0, 0, 0}; // quais argumentos passar em notfound

	// trata os argumentos, para decidir quais testes realizar
	for (int i = 1; i < argc; i++) {
		int op = atoi(argv[i]);
		if (!strcmp(argv[i], "f")) {
			isceil = 0;
		}
		else if (strcmp(argv[i], "c")) {
			if (op == 2) {
				for (int j = 0; j < 3; j++)
					notfound[j] = 1;
			}
			else if (op > -2 && op < 2){
				notfound[op+1] = 1;
			}
		}
	}
	if (!notfound[0] && !notfound[1] && !notfound[2])
		notfound[1] = 1;

	printf("\nTestes:\n\n");

	UNITY_BEGIN();

	RUN_TEST(test_empty);
	RUN_TEST(test_one);
	RUN_TEST(test_one_nopath);
	
	if (notfound[1])
		RUN_TEST(test_one_not_found);
	if (notfound[0])
		RUN_TEST(test_one_not_found_bef);
	if (notfound[2])
		RUN_TEST(test_one_not_found_next);

	if (isceil == 1) {
		RUN_TEST(test_ceil_four);
		RUN_TEST(test_ceil_five);
		RUN_TEST(test_ceil_six);
		RUN_TEST(test_ceil_seven);
		if (notfound[1]) {
			RUN_TEST(test_ceil_four_not_found);
			RUN_TEST(test_ceil_five_not_found);
			RUN_TEST(test_ceil_six_not_found);
			RUN_TEST(test_ceil_seven_not_found);
		}
		if (notfound[0]) {
			RUN_TEST(test_ceil_four_not_found_bef);
			RUN_TEST(test_ceil_five_not_found_bef);
			RUN_TEST(test_ceil_six_not_found_bef);
			RUN_TEST(test_ceil_seven_not_found_bef);
		}
		if (notfound[2]) {
			RUN_TEST(test_ceil_four_not_found_next);
			RUN_TEST(test_ceil_five_not_found_next);
			RUN_TEST(test_ceil_six_not_found_next);
			RUN_TEST(test_ceil_seven_not_found_next);
		}
	}
	else {
		RUN_TEST(test_floor_four);
		RUN_TEST(test_floor_five);
		RUN_TEST(test_floor_six);
		RUN_TEST(test_floor_seven);
		if (notfound[1]) {
			RUN_TEST(test_floor_four_not_found);
			RUN_TEST(test_floor_five_not_found);
			RUN_TEST(test_floor_six_not_found);
			RUN_TEST(test_floor_seven_not_found);
		}
		if (notfound[0]) {
			RUN_TEST(test_floor_four_not_found_bef);
			RUN_TEST(test_floor_five_not_found_bef);
			RUN_TEST(test_floor_six_not_found_bef);
			RUN_TEST(test_floor_seven_not_found_bef);
		}
		if (notfound[2]) {
			RUN_TEST(test_floor_four_not_found_next);
			RUN_TEST(test_floor_five_not_found_next);
			RUN_TEST(test_floor_six_not_found_next);
			RUN_TEST(test_floor_seven_not_found_next);
		}
	}

	return UNITY_END();

}

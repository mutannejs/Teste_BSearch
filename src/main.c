#include "binary_search.h"

int main(int argc, char *argv[]) {

	int istop = 1; // arredondamento para cima?
	int notfound[] = {0, 0, 0}; // quais argumentos passar em notfound

	// trata os argumentos, para decidir quais testes realizar
	for (int i = 1; i < argc; i++) {
		int op = atoi(argv[i]);
		if (!strcmp(argv[i], "d")) {
			istop = 0;
		}
		else if (op == 2) {
			for (int j = 0; j < 3; j++)
				notfound[j] = 1;
		}
		else if (op > -2 && op < 2){
			notfound[op+1] = 1;
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

	if (istop == 1) {
		RUN_TEST(test_top_four);
		RUN_TEST(test_top_five);
		RUN_TEST(test_top_six);
		RUN_TEST(test_top_seven);
		if (notfound[1]) {
			RUN_TEST(test_top_four_not_found);
			RUN_TEST(test_top_five_not_found);
			RUN_TEST(test_top_six_not_found);
			RUN_TEST(test_top_seven_not_found);
		}
		if (notfound[0]) {
			RUN_TEST(test_top_four_not_found_bef);
			RUN_TEST(test_top_five_not_found_bef);
			RUN_TEST(test_top_six_not_found_bef);
			RUN_TEST(test_top_seven_not_found_bef);
		}
		if (notfound[2]) {
			RUN_TEST(test_top_four_not_found_next);
			RUN_TEST(test_top_five_not_found_next);
			RUN_TEST(test_top_six_not_found_next);
			RUN_TEST(test_top_seven_not_found_next);
		}
	}
	else {
		RUN_TEST(test_down_four);
		RUN_TEST(test_down_five);
		RUN_TEST(test_down_six);
		RUN_TEST(test_down_seven);
		if (notfound[1]) {
			RUN_TEST(test_down_four_not_found);
			RUN_TEST(test_down_five_not_found);
			RUN_TEST(test_down_six_not_found);
			RUN_TEST(test_down_seven_not_found);
		}
		if (notfound[0]) {
			RUN_TEST(test_down_four_not_found_bef);
			RUN_TEST(test_down_five_not_found_bef);
			RUN_TEST(test_down_six_not_found_bef);
			RUN_TEST(test_down_seven_not_found_bef);
		}
		if (notfound[2]) {
			RUN_TEST(test_down_four_not_found_next);
			RUN_TEST(test_down_five_not_found_next);
			RUN_TEST(test_down_six_not_found_next);
			RUN_TEST(test_down_seven_not_found_next);
		}
	}

	return UNITY_END();

}

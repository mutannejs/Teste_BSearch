#include "binary_search.h"

int cmp(const void *num1, const void *num2) {
	if ( (*((const lli *)num1)) > (*((const lli *)num2)) )
		return 1;
	if ( (*((const lli *)num1)) < (*((const lli *)num2)) )
		return -1;
	return 0;
}

int main(int argc, char *argv[]) {

	int istop = 1;

	if (argc == 2 && !strcmp(argv[1], "0"))
		istop = 0;

	UNITY_BEGIN();

	if (istop == 1) {
		RUN_TEST(test_top_empty);
	}

	return UNITY_END();

}

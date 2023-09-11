#include "binary_search.h"

int cmp(const void *num1, const void *num2) {
	if ( (*((const lli *)num1)) > (*((const lli *)num2)) )
		return 1;
	if ( (*((const lli *)num1)) < (*((const lli *)num2)) )
		return -1;
	return 0;
}

#include <stdio.h>
#include "include/primes.h"

int main(void)
{
	int* ps;
	primes(&ps, 5E5);

	printf("%d", ps[10000]);
	return 0;
}

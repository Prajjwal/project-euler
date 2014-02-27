#include <stdio.h>
#include <malloc.h>
#include "include/primes.h"

int main(void)
{
	int* ps;
	int i, count = primes(&ps, 2E6);
	long sum = 0;

	for (i = 0; i < count; ++i) {
		sum += ps[i];
	}

	printf("%ld", sum);

	free(ps);

	return 0;
}

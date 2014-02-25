#include <stdio.h>
#include <math.h>
#define N 2000001

int main(void)
{
	int i, j;
	long sum = 0;
	char sieve[N + 1] = { 0, 0 };

	for (i = 2; i < N; ++i) {
		sieve[i] = 1;
	}

	for (i = 2; i < sqrt(N); ++i) {
		if (sieve[i]) {
			for (j = i * i; j < N; j += i) {
				sieve[j] = 0;
			}
		}
	}

	for (i = 2; i < N; ++i) {
		if (sieve[i]) {
			sum += i;
		}
	}

	printf("%ld", sum);

	return 0;
}

#include <stdio.h>

int sum_proper_divisors(int);

int main(void)
{
	int i, s, sum = 0;

	for (i = 2; i < 10000; ++i) {
		s = sum_proper_divisors(i);

		if (s != i && sum_proper_divisors(s) == i) {
			sum += i;
		}
	}

	printf("%d", sum);

	return 0;
}

int sum_proper_divisors(int n)
{
	int i, sum = 0;

	for (i = n / 2; i > 0 ; --i) {
		if (n % i == 0) {
			sum += i;
		}
	}

	return sum;
}

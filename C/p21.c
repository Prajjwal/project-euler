#include <stdio.h>
#include <stdbool.h>

int sum_proper_divisors(int);
bool is_amicable(int);

int main(void)
{
	int i, sum = 0;

	for (i = 2; i < 10000; ++i) {
		if (is_amicable(i)) {
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

bool is_amicable(int n) {
	int s = sum_proper_divisors(n);

	return (s != n && sum_proper_divisors(s) == n);
}

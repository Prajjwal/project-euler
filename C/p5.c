#include <stdio.h>

int gcd(int, int);
long lcm(long, long);

int main(void)
{
	int i, nums[10] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	long ans = nums[0];

	for (i = 1; i < 10; ++i) {
		ans = lcm(ans, nums[i]);
	}

	printf("%ld", ans); /* 232792560 */

	return 0;
}

int gcd(int a, int b)
{
	/* Use the euclidean algorithm to compute gcd of two numbers.
	 * https://en.wikipedia.org/wiki/Euclidean_algorithm
	 * This implementation only works for positive inputs.
	 */

	while (a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}

	return a;
}

long lcm(long a, long b) {
	return (a * b) / gcd(a, b);
}

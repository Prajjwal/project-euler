#include <stdio.h>
#include <malloc.h>
#include "include/primes.h"

/* Idea:
 *
 * Any number can be written as a product of primes:
 *
 * N = (p1 ^ e1) * (p2 ^ e2) ... (pn ^ en)
 *
 * Eg.
 *
 * 28 = (2 ^ 2) * (7 ^ 1)
 *
 * The number of divisors of the number is given by the formula:
 *
 * D(n) = (e1 + 1) * (e2 + 1) ... * (en + 1)
 *
 * Eg
 *
 * D(28) = (2 + 1) * (1 + 1) = 3 * 2 = 6
 *
 * The first triangle number can thus be computed quickly by making use of
 * an array of primes(which can be generated efficiently using a sieve).
 * Generate triangle numbers in a loop & compute the exponent of each prime that
 * it is divisible by, ie, how many times a prime number divides it. Keep
 * multiplying that to a divisor count to get the total # of divisors.
 */

int divisor_count(int, int*);

int main(void)
{
	int* ps;
	int i = 1, n = 1;
	primes(&ps, 65500);

	while (divisor_count(n, ps) < 500) {
		++i;
		n += i;
	}

	printf("%d", n);

	free(ps);

	return 0;
}

/* Takes n, & an array of primes *ps. Returns the # of divisors of n.
 * ps should be pre-allocated & populated with enough primes.
 */
int divisor_count(int n, int *ps) {

	int i, power = 0, divisors = 1;

	for (i = 0; i < n; ++i) {
		power = 0;

		while (n % ps[i] == 0) {
			power += 1;
			n /= ps[i];
		}

		divisors *= (power + 1);
	}

	return divisors;
}

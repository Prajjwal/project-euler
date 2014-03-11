#include <stdio.h>
#include <malloc.h>
#include <math.h>

/* Compute primes below 'n' using eratosthenes sieve.
 * https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 *
 * sieve must be pre allocated enough memory to hold n chars.
 *
 * When this function exits, *sieve[i] = 1 if i is prime, and the number of
 * primes found is returned.
 */
int eratosthenes_sieve(char* sieve, int n)
{
	int i, j, count = 0;

	sieve[0] = 0;
	sieve[1] = 0;

	for (i = 2; i < n; ++i) {
		sieve[i] = 1;
	}

	for (i = 2; i < sqrt(n); ++i) {
		if (sieve[i]) {
			for (j = i * i; j < n; j += i) {
				sieve[j] = 0;
			}
		}
	}

	for (i = 2; i < n; ++i) {
		if (sieve[i]) {
			count++;
		}
	}

	return count;
}

/* Build a list of primes below 'n'.
 * Writes the primes to *ps & returns it's size.
 *
 * Allocates memory, don't forget to free(ps) later.
 */
int primes(int** ps, int n)
{
	int i, j, count;
	char* s = malloc(n);

	count = eratosthenes_sieve(s, n);

	*ps = malloc(count * sizeof(int));

	for (i = 2, j = 0; i < n; ++i) {
		if (s[i]) {
			(*ps)[j] = i;
			j++;
		}
	}

	free(s);

	return count;
}

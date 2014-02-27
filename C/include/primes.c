#include <stdio.h>
#include <malloc.h>
#include <math.h>

/* Compute primes below 'n' using eratosthenes sieve.
 * https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 *
 * When this function exits, *sieve[i] = 1 if i is prime.
 */
void eratosthenes_sieve(char** sieve, int n)
{
	int i, j;
	*sieve = (char *) malloc(n);
	char* s = *sieve;

	s[0] = 0;
	s[1] = 0;

	for (i = 2; i < n; ++i) {
		s[i] = 1;
	}

	for (i = 2; i < sqrt(n); ++i) {
		if (s[i]) {
			for (j = i * i; j < n; j += i) {
				s[j] = 0;
			}
		}
	}
}

/* Build a list of primes below 'n'.
 * Writes the primes to *ps & returns it's size.
 */
int primes(int** ps, int n)
{
	int i, j, count = 0;
	char* s;

	eratosthenes_sieve(&s, n);

	/* Calc no. of primes computed by eratosthenes_sieve() */
	for (i = 2; i < n; ++i) {
		if (s[i]) {
			count++;
		}
	}

	*ps = malloc(count * sizeof(int));
	int* p = *ps;

	for (i = 2, j = 0; i < n; ++i) {
		if (s[i]) {
			p[j] = i;
			j++;
		}
	}

	return count;
}

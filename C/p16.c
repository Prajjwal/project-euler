#include <stdio.h>
#include <malloc.h>
#include <gmp.h>

int main(void)
{
	int size, i, sum = 0;
	char *digits;
	mpz_t n;
	mpz_init(n);

	/* Set n = 2 ^ 1000 */
	mpz_ui_pow_ui(n, 2, 1000);

	size = mpz_sizeinbase(n, 10); /* # of digits */
	digits = malloc(size + 2); /* +2 chars for a sign + terminator. */
	mpz_get_str(digits, 10, n);

	for (i = 0; i < size; ++i) {
		sum += digits[i] - '0';
	}

	free(digits);
	mpz_clear(n);

	printf("%d", sum);

	return 0;
}

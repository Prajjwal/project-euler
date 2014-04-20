#include <stdio.h>
#include <gmp.h>
#include <malloc.h>

int main(void)
{
	int i, size;
	char *digits;
	mpz_t sum, e;
	mpz_init(sum);
	mpz_init(e);

	/* Compute sum of series. */
	for (i = 1; i < 1001; ++i) {
		mpz_ui_pow_ui(e, i, i);
		mpz_add(sum, sum, e);
	}

	/* Export sum as a string. */
	size = mpz_sizeinbase(sum, 10);
	digits = malloc(size + 2);
	mpz_get_str(digits, 10, sum);

	/* Print last 10 digits of the string. */
	i = size - 10;

	while (i < size) {
		putchar(digits[i]);
		++i;
	}

	free(digits);
	mpz_clear(sum);
	mpz_clear(e);

	return 0;
}

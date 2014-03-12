#include <stdio.h>
#include <malloc.h>
#include <gmp.h>

int main(void)
{
	int i = 0, sum = 0;
	mpz_t fac;
	char *digits;

	mpz_init(fac);
	mpz_fac_ui(fac, 100);

	digits = malloc(mpz_sizeinbase(fac, 10) + 2);
	mpz_get_str(digits, 10, fac);

	/* Reduce NULL terminated list of digits. */
	while (digits[i]) {
		sum += digits[i] - '0';
		i++;
	}

	free(digits);
	mpz_clear(fac);

	printf("%d", sum);

	return 0;
}

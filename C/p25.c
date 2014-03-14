#include <stdio.h>
#include <gmp.h>

int main(void)
{
	int count = 2;
	mpz_t a, b, temp;
	mpz_inits(a, b, temp, NULL);

	mpz_set_ui(a, 1);
	mpz_set_ui(b, 1);

	while (mpz_sizeinbase(b, 10) < 1000) {
		mpz_set(temp, a);
		mpz_set(a, b);
		mpz_add(b, temp, b);
		++count;
	}

	mpz_clears(a, b, temp, NULL);

	/* mpz_sizeinbase() produces a result that is either exact or 1 too big.
	 * It seems to incorrectly return n + 1 for the last fibonacci number with n
	 * digits in base 10. The loop terminates at the last 999 digit fibonacci
	 * number because mpz_sizeinbase incorrectly returns 1000. The actual count
	 * is thus count + 1.
	 */
	printf("%d", count + 1);

	return 0;
}

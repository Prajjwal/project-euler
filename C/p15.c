#include <stdio.h>
#include <gmp.h>

void factorial(unsigned long, mpz_t f);

int main(void)
{
	/* The number of paths from the origin to (a, b) is given by the binomial
	 * coefficient (a + b over b), which in this case is (40 over 20).
	 * This is equal to 40! / 20! * (40 - 20)!
	 */

	mpz_t x, y;
	mpz_init(x);
	mpz_init(y);

	factorial(40, x);
	factorial(20, y);

	mpz_mul(y, y, y);

	mpz_cdiv_q(x, x, y);

	mpz_out_str(stdout, 10, x);

	return 0;
}

/* Dump factorial of n into f. */
void factorial(unsigned long n, mpz_t f)
{
	mpz_set_ui(f, 1);

	while (n > 1) {
		mpz_mul_ui(f, f, n);
		--n;
	}
}

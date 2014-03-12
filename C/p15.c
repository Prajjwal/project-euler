#include <stdio.h>
#include <gmp.h>

int main(void)
{
	/* The number of paths from the origin to (a, b) is given by the binomial
	 * coefficient (a + b over b), which in this case is (40 over 20).
	 * This is equal to 40! / 20! * (40 - 20)!
	 */

	mpz_t x;
	mpz_init(x);

	mpz_bin_uiui(x, 40, 20);

	mpz_out_str(stdout, 10, x);

	mpz_clear(x);

	return 0;
}

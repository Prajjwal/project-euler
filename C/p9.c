#include <stdio.h>
#include <math.h>

int main(void)
{
	/* We know that c is given by:
	 *
	 * c = 1000 - a - b
	 *
	 * Also a < b < c, which means a & b can't be more than 500.
	 *
	 * This narrows our search space down dramatically, down to only those
	 * combinations of a, b, c where a < 500 and a < b < 1000 - a - b
	 *
	 * Brings it down to 82834 steps.
	 */

	int a, b, c;

	for (a = 1; a < 500; ++a) {
		for (b = a + 1; (c = 1000 - a - b) > b; ++b) {
			if (c * c == a * a + b * b) {
				printf("%d", a * b * c); /* 31875000 */
			}
		}
	}

	return 0;
}

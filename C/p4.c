#include <stdio.h>

int reverse(int);

int main(void)
{
	/* Let the largest palindrome made from the product of two 3-digit numbers
	 * be abccba.
	 *
	 * = (a * 100000) + (b * 10000) + (c * 1000) + (c * 100) + (b * 10) + a
	 * = 100001a + 10010b + 1100c
	 * = 11 * (9091a + 910b + 100c)
	 *
	 * This means one of the numbers must be a multiple of 11, and narrows our
	 * search down to the same.
	 */

	int i, j, product, largest_palindrome = 0;

	for (i = 100; i < 1000; i++) {
		for (j = 110; j < 1000; j += 11) {
			product = i * j;

			if (product > largest_palindrome && product == reverse(product)) {
				largest_palindrome = product;
			}
		}
	}

	printf("%d", largest_palindrome); /* 906609 */

	return 0;
}

int reverse(int x) {
	int rev = 0;

	while (x > 0) {
		rev = (rev * 10) + (x % 10);
		x = x / 10;
	}

	return rev;
}

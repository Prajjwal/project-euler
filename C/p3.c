#include <stdio.h>

int main(void)
{
	long num = 600851475143;
	int largest_pf = 2;

	while (num > 1) {
		if (num % largest_pf == 0) {
			num /= largest_pf;
		} else {
			largest_pf += 1;
		}
	}

	printf("%d", largest_pf); /* 6857 */

	return 0;
}

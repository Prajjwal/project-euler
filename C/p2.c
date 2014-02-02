#include <stdio.h>

int main(void)
{
	int a, b, temp, sum = 0;

	for (a = 0, b = 1; b < 4E6; temp = b, b = a + b, a = temp) {
		if (b % 2 == 0) {
			sum += b;
		}
	}

	printf("%d", sum); /* 4613732 */

	return 0;
}

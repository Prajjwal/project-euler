#include <stdio.h>

int main(void)
{
	int i;
	long sum = 0, sum_of_squares = 0;

	for (i = 1; i < 101; ++i) {
		sum += i;
		sum_of_squares += i * i;
	}

	printf("%ld", (sum * sum) - sum_of_squares); /* 25164150 */

	return 0;
}

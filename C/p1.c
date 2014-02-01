#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i, sum = 0;

	for (i = 1; i < 1000; ++i) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}

	printf("%d", sum); /* 233168 */

	return 0;
}

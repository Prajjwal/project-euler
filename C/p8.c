#include <stdio.h>

int main(void)
{
	char num[1000];
	int i, j, p, largest_p = 1;

	FILE *f = fopen("../input/p8.txt", "r");
	fgets(num, 1000, f);
	fclose(f);

	for (i = 0; i < 996; ++i) {
		p = 1;

		for (j = i; j < i + 5; ++j) {
			p *= num[j] - '0';
		}

		if (p > largest_p) {
			largest_p = p;
		}
	}

	printf("%d", largest_p); /* 40824 */

	return 0;
}

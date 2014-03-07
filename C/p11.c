#include <stdio.h>

int main(void)
{
	int grid[20][20], i, j, k, products[4], largest_p = 1;
	char buffer[60];

	/* Dump numbers from ../input/p11.txt into grid. */
	FILE *f = fopen("../input/p11.txt", "r");

	for (i = 0; i < 20; ++i) {
		fgets(buffer, 60, f);

		/* Dump numbers from the read line into grid[i].
		 * One day I will clean up or document this mess.
		 */
		for (j = 0; j < 20; ++j) {
			grid[i][j] = (buffer[j * 3] - '0') * 10 + (buffer[j * 3 + 1] - '0');
		}

		getc(f);
	}

	fclose(f);

	/* Calculate all possible products. */
	for (i = 0; i < 20; ++i) {
		for (j = 0; j < 17; ++j) {

			/* Reset all products to 1. */
			for (k = 0; k < 4; ++k) {
				products[k] = 1;
			}

			for (k = 0; k < 4; ++k) {

				/* left to right product */
				products[0] *= grid[i][j + k];

				/* right to left product */
				products[1] *= grid[j + k][i];

				/* There are no diagonal products for (i, j) beyond (16, 16) */
				if (i < 17) {
					/* top-left -> bottom-right diagonal product */
					products[2] *= grid[i + k][j + k];

					/* bottom-left -> top-right diagonal product */
					products[3] *= grid[19 - i - k][j + k];
				}
			}

			/* Update largest_p if a larger product was found. */
			for (k = 0; k < 4; ++k) {
				if (products[k] > largest_p) {
					largest_p = products[k];
				}
			}
		}
	}

	printf("%d", largest_p);

	return 0;
}

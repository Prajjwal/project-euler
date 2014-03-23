#include <stdio.h>
#include <malloc.h>
#define THOUSAND 8
#define HUNDRED 7
#define AND 3

void extract_digits(int, int*, int*, int*);

int main(void)
{
	int i, huns, tens, units, count = 0;

	/* Letter counts upto 19. */
	int lc_1_19[20] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };

	/* Letter counts from 20 - 90 in increments of 10. */
	int lc_20_90[10] = { 0, 0, 6, 6, 5, 5, 5, 7, 6, 6 };

	for (i = 1; i < 1000; ++i) {
		extract_digits(i, &units, &tens, &huns);

		/* Hundreds digit letter count + the letter count of "hundred".
		 * Add letter count of "and" if the number has a units or tens digit.
		 */
		if (huns) {
			count += lc_1_19[huns] + HUNDRED;
			count += (units || tens) ? AND : 0;
		}

		/* For numbers [10-19], add corresponding letter count from lc_1_19[].
		 * For others, add letter count for tens & units separately.
		 */
		if (tens == 1) {
			count += lc_1_19[(tens * 10) + units];
		} else {
			count += lc_20_90[tens] + lc_1_19[units];
		}
	}

	/* Total count = sum(counts [1..999] + count "One Thousand"). */
	printf("%d", count + lc_1_19[1] + THOUSAND);

	return 0;
}

void extract_digits(int n, int *units, int *tens, int *huns)
{
	*units = n % 10;
	n = n / 10;
	*tens = n % 10;
	n = n / 10;
	*huns = n;
}

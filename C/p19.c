#include <stdio.h>

int main(void)
{
	int m_lengths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year, month, sum_days = 0, count = 0;

	for (year = 1900; year <= 2000; ++year) {
		for (month = 0; month < 12; ++month) {
			/* February has 28 days on non-leap years. */
			m_lengths[1] = (year % 4 != 0) ? 28 : 29;

			sum_days += m_lengths[month];

			if (sum_days % 7 == 0) {
				count += 1;
			}
		}
	}

	/* Account for the two first Sunday's in 1900 */
	printf("%d", count - 2);

	return 0;
}

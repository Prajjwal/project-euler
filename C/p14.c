#include <stdio.h>

int main(void)
{
	int i, max = 2, chain_length, chain_lengths[1000000] = { 0, 1, 2 };
	long n;

	/* Idea:
	 *
	 * Instead of computing the total chain length for every number, cache the
	 * chain length for each number i in chain_lengths[i]. Then, compute the
	 * chain length for all successive numbers until the chain reaches a number
	 * for which the value is already known. The total chain length is then:
	 *
	 * (length until n reached a known value < i) + chain_lengths[n];
	 *
	 * This is extremely fast, runs in ~19ms on my machine with gcc -O3.
	 */
	for (i = 3; i < 1000000; ++i) {
		chain_length = 0;
		n = i;

		/* Compute chain length until n hits a known value. */
		while (n >= i) {
			n = (n % 2 == 0) ? (n / 2) : (n * 3 + 1);
			chain_length++;
		}

		/* Cache total chain length. */
		chain_lengths[i] = chain_length + chain_lengths[n];

		/* Update index of max chain length. */
		if (chain_lengths[i] > chain_lengths[max]) {
			max = i;
		}
	}

	printf("%d", max);

	return 0;
}

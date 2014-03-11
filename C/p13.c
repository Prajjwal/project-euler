#include <stdio.h>
#include <gmp.h>

int main(void)
{
	int i;
	mpz_t num, sum;
	char buffer[100];

	mpz_init(num);
	mpz_init(sum);

	/* Add each number from ../input/p13.txt to sum. */
	FILE *f = fopen("../input/p13.txt", "r");

	for (i = 0; i < 100; ++i) {
		mpz_set_str(num, fgets(buffer, 52, f), 10);
		mpz_add(sum, sum, num);
	}

	fclose(f);

	/* Print out the first ten digits of sum. */
	mpz_get_str(buffer, 10, sum);

	mpz_clear(sum);
	mpz_clear(num);

	for (i = 0; i < 10; ++i) {
		printf("%c", buffer[i]);
	}

	return 0;
}

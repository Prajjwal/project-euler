clean:
	find ./ -type f -executable -print0 | xargs -0 rm
p10:
	cc -c p10.c include/primes.c
	cc primes.o p10.o -o p10 -lm

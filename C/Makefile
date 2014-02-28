clean:
	find ./ -type f -executable -print0 | xargs -0 rm
p7 p10:
	cc -c $@.c include/primes.c
	cc primes.o $@.o -o $@ -lm

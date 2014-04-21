CFLAGS=-Wall

p7 p10 p12: LDLIBS=-lm
p13 p15 p16 p20 p25 p48: LDLIBS=-lgmp

p7 p10 p12: include/primes.o

.PHONY: clean
clean:
	-find ./ -type f -executable -print0 | xargs -0 rm
	-find ./ -name "*.o" -print0 | xargs -0 rm

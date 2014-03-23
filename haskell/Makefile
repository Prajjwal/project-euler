.DEFAULT:
	ghc --make $@.hs

.PHONY: clean
clean:
	-rm *.o
	-rm *.hi
	-find ./ -type f -executable -print0 | xargs -0 rm

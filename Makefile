self-linker: self-linker.c
	gcc -g -Wall -o self-linker self-linker.c -ldl

.PHONY: clean
clean:
	rm -f self-linker

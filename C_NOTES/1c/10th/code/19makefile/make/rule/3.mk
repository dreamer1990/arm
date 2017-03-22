
main: main.c
	gcc main.c -o main

.PHONY: clean
clean: source1.c

	@echo clean executed...
	rm -f main

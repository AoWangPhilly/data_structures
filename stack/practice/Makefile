run:
	gcc -o reverse stack.c reverse.c

debug:
	gcc -g -Og stack.c reverse.c -o reverse
	valgrind --leak-check=full ./reverse
run:
	gcc -o stack stack.c main.c

debug:
	gcc -g -Og stack.c main.c -o stack
	valgrind --leak-check=full ./stack
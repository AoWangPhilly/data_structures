run:
	rm stack
	gcc -o stack stack.c main.c

debug:
	rm stack
	gcc -g -Og stack.c main.c -o stack
	valgrind --leak-check=full ./stack
run:
	gcc -o queue queue.c main.c

debug:
	gcc -g -Og queue.c main.c -o queue
	valgrind --leak-check=full ./queue

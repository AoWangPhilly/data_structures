#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "stack.h"

void readFile(char *, char**);
Stack* split(char *);

int
main(int argc, char **argv)
{
    int fd;
    char *buf;
    Stack *stack;

    if (argc != 2) {
        perror("Usage: ./reverse fname");
        exit(1);
    }

    readFile(argv[1], &buf);
    stack = split(buf);
    
    while (!isEmpty(stack)) {
        printf("%s\n", pop(stack));
    }

    free(buf);
    free(stack); 
    buf = NULL;
    stack = NULL;
}

void
readFile(char *fname, char **buf) {
    int fd;
    int cap, used, n;
    char *tmp;

    fd = open(fname, O_RDONLY);
    used = 0;
    cap = 128;
    *buf = malloc(cap);
    tmp = *buf;

    while ((n = read(fd, tmp, cap - used)) > 0) {
        used += n;
        tmp += n;
        if (cap - used < 32) {
            cap *= 2;
            *buf = realloc(*buf, cap);
            tmp = *buf + used;
        }
    }
    close(fd);
}

Stack *
split(char *buf)
{
    Stack *stack;
    char *token;
    
    stack = create();

    while ((token = strsep(&buf, "\n")) != NULL) {
        push(stack, token);
    }

    return stack;
}
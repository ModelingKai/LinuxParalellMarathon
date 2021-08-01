#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    int pfd;
    char c;

    if ((pfd = open("mypipe", O_RDONLY)) == -1) {
        exit(1);
    }

    while (read(pfd, &c, 1) != 0) {
        write(1, &c, 1);
    }
}
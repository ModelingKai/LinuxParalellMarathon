#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    int pfd, rfd;
    char c;

    if ((pfd = open("mypipe", O_WRONLY)) == -1) {
        exit(1);
    }

    if ((rfd = open("oldfile", O_RDONLY)) == -1) {
        exit(1);
    }

    while (read(rfd, &c, 1) != 0) {
        write(pfd, &c, 1);
    }
}
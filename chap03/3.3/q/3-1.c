#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd_from, fd_to;
    char ch;

    if ((fd_from = open(argv[1], O_RDONLY)) == -1) {
        printf("can't open %s\n", argv[1]);
        exit(1);
    }

    if ((fd_to = open(argv[2], O_RDWR | O_CREAT, 0644)) == -1) {
        printf("can't create %s\n", argv[2]);
        exit(1);
    }

    while (read(fd_from, &ch, 1) != 0) {
        write(fd_to, &ch, 1);
    }

    printf("done\n");
}

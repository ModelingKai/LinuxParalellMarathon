#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    int fd;
    char ch;

    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        exit(1);
    }

    while (read(fd, &ch, 1) != 0) {
        write(1, &ch, 1);
    }
}
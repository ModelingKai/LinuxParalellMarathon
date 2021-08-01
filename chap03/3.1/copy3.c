//
// Created by mohira on 2021/08/01.
//

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int fd1, fd2;
    char ch;
    printf("cpy3\n");

    if ((fd1 = open("./oldfile", O_RDONLY)) == -1) {
        exit(1);
    }

//    if ((fd2 = creat("newfile", 0644)) == -1) {
    if ((fd2 = open("newfile", O_WRONLY | O_CREAT, 0644)) == -1) {
        printf("error fd2\n");
        exit(1);
    }

    while (read(fd1, &ch, 1) != 0) {
        write(fd2, &ch, 1);
    }

    close(fd1);
    close(fd2);
}
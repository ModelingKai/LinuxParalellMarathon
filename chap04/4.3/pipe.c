//
// Created by jun on 2021/08/01.
//

#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd[2], rfd;
    char c;

    pipe(fd);

    if(fork() == 0){
        close(fd[0]);
        rfd = open("oldfile", O_RDONLY);
        while (read(rfd, &c, 1) != 0) {
            write(fd[1], &c, 1);
        }
        close(fd[1]);
        close(rfd);
    }else {
        close(fd[1]);
        while(read(fd[0], &c, 1) != 0){
            write(1, &c, 1);
        }
        close(fd[0]);
    }
}
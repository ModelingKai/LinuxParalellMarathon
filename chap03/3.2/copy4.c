//
// Created by jun on 2021/08/01.
//

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd1, fd2;
    int status;
    int count;
    char buf[20];


    if((fd1 = open("oldfile", O_RDONLY)) == -1 ) exit(1);
    if (fork() == 0) { // fork()することで、fd表もコピーされて、fd1が同じファイル(oldfile)を見ている
        if((fd2 = creat("newfile1", 0664)) == -1) exit(1);
        while((count = read(fd1, buf, 20)) != 0) {
            write(fd2, buf, count);
            write(fd2,"\n", 1);
            write(1, "child\n", 6);
            sleep(1);
        }
    } else {
        if((fd2 = creat("newfile2", 0664)) == -1) exit(1);
        while((count = read(fd1, buf, 20)) != 0) {
            write(fd2, buf, count);
            write(fd2, "\n", 1);
            write(1, "parent\n", 7);
            sleep(1);
        }
        wait(&status);
    }
}
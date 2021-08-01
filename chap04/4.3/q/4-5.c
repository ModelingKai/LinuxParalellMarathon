//
// Created by jun on 2021/08/01.
//

#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    char *argv[10];
    int status;

    pipe(fd);
    if(fork() == 0){
        close(fd[0]);
        close(1);
        dup(fd[1]);
        close(fd[1]);

        argv[0] = "ls";
        argv[1] = "-l";
        argv[2] = (char *)0;



        execvp(argv[0], argv);
    } else if(fork() == 0){
        close(fd[1]);
        close(0);
        dup(fd[0]);
        close(fd[0]);

        argv[0] = "grep";
        argv[1] = "c$";
        argv[2] = (char *)0;
        execvp(argv[0], argv);
    } else {

        wait(&status);
        wait(&status);
    }
}
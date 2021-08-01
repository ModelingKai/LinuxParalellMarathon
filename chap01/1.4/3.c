//
// Created by jun on 2021/08/01.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int status;
    pid_t pid;

    if (fork() == 0){
        printf("子プロセス\n");
        sleep(2);
        exit(15);
    } else {
        pid = wait(&status);
        printf("親プロセス\n");
        printf("子プロセスのid = %d\n", pid);
        printf("子プロセス終了時の値は = %04x\n", status);
    }
}
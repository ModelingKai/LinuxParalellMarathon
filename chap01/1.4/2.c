//
// Created by jun on 2021/08/01.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int status;

    if (fork() == 0){
        printf("子プロセス\n");
        sleep(2);
        exit(15);
    } else {
        wait(&status);
        printf("親プロセス\n");
        printf("子プロセス終了時の値は = %04x\n", status);
    }
}
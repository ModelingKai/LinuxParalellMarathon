//
// Created by jun on 2021/08/01.
//


#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    int status = 0;

    if(fork() == 0){
        printf("子プロセス pid = %d\n", getpid());
        printf("子プロセスステータス %d\n", status);
        sleep(2);

    }else {
        printf("ステータス %d\n", status);
        printf("wait ステータス %d\n", wait(&status));
        printf("ステータス %d\n", status);
        printf("親プロセス\n");
    }
}
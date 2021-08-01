//
// Created by jun on 2021/08/01.
//

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int status;

    if(fork() == 0){
        printf("子プロセス1\n");
        sleep(5);
        printf("子プロセス1 done\n");
        exit(1);
    }
    else {
        if(fork() == 0){
            printf("子プロセス2\n");
            sleep(1);
            printf("子プロセス2 done\n");
            exit(255);
        } else {
            wait(&status);
            printf("子プロセス終了時の値は = %04x\n", status);
            wait(&status);
            printf("子プロセス終了時の値は = %04x\n", status);
            printf("子プロセス終わったよ\n");
        }
    }
}

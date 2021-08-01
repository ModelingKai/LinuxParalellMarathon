//
// Created by jun on 2021/08/01.
//

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    pid_t pid1;
    pid_t pid2;
    int status;

    if ((pid1 = fork()) == 0) {
        // 子プロセス


        if ((pid2 = fork()) == 0) {
            // 孫プロセス
            sleep(2);
            printf("孫プロセス done\n");
            exit(1);

        } else {
            wait(&status);
            sleep(3);
            printf("子プロセス done\n");
            exit(255);
        }
    } else {
        wait(&status);
        printf("孫プロセス pid = %d\n", pid2);
        printf("子プロセス pid = %d\n", pid1);
        printf("親プロセス pid = %d\n", getpid());
    }

}

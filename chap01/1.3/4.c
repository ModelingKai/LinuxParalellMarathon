//
// Created by mohira on 2021/08/01.
//

#include <unistd.h>
#include <stdio.h>

int main() {
    if (fork() == 0) {
        printf("子プロセス PID=%d\n", getpid());
    } else {
        printf("親プロセス PID=%d\n", getpid());
    }
}
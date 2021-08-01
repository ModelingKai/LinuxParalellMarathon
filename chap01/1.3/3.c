//
// Created by mohira on 2021/08/01.
//

// p.6
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t val;

    val = fork();

    if (val == 0) {
        printf("子プロセス PID=%d\n", getpid());
    } else {
        printf("親プロセス PID=%d\n", getpid());
    }
}
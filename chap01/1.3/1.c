//
// Created by mohira on 2021/08/01.
//

// p.5

#include <unistd.h>
#include <stdio.h>


int main() {
    pid_t val;

    val = fork();

    printf("forkの戻り値=%d\n", val);
    printf("プロセスID=%d\n", getpid());
}
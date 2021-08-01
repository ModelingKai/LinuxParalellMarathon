//
// Created by jun on 2021/08/01.
//

#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    printf("プロセス id = %d\n", getpid());
}

// プロセス id = 15887
// プロセス id = 15888
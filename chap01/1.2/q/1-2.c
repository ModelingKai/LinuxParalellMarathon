//
// Created by jun on 2021/08/01.
//

#include <unistd.h>
#include <stdio.h>

int main() {
    fork();
    fork();
    fork();
    printf("プロセス id = %d\n", getpid());
}

// プロセス id = 17068
//プロセス id = 17070
//プロセス id = 17069
//プロセス id = 17071
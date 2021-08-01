//
// Created by jun on 2021/08/01.
//

// p.2

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    printf("プロセス id = %d\n", getpid());
}

// プロセス id = 14673
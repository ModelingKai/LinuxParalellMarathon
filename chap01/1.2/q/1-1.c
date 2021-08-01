//
// Created by jun on 2021/08/01.
//


#include <stdio.h>
#include <unistd.h>

int main(){
    printf("プロセス id = %d\n", getpid());
    fork();
}

//プロセス id = 16632
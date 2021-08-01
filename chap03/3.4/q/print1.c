//
// Created by jun on 2021/08/01.
//

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("before fork : ");
    if(fork() == 0){
        printf("child process");
    }else{
        sleep(1);
        printf("parent process");
    }
}
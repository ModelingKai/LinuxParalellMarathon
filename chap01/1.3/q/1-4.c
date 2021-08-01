//
// Created by mohira on 2021/08/01.
//


#include <unistd.h>
#include <stdio.h>

int main() {
    if (fork() == 0) {
    } else {
        printf("ご機嫌いかがですか\n");
    }
}
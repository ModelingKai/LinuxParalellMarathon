//
// Created by mohira on 2021/08/01.
//
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("cal 1 2020 に変身\n");

    execl("/usr/bin/cal", "cal", "1", "2020", (char *) 0);
    execl("/usr/bin/cal", "hgoehgioehgo", "1", "2020", (char *) 0);

}

// ./add2 3 4
// 7

#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[]){
    int a, b;

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    printf("%d", a+b);

    printf("%d", '9'-'0');

}
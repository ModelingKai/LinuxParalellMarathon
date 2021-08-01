//
// Created by jun on 2021/08/01.
//

#include <stdio.h>
#include <pthread.h>

int x; // グローバルな変数

void Func2(void){
    printf("new thread: x = %d\n", x);
}

int main(int argc, char *argv[]){
    pthread_t th_id;
    int st, y;
    x=1;
    st = pthread_create(&th_id, NULL, (void *(*)(void *))Func2, NULL);
    if(st != 0) return 1;
    pthread_join(th_id, NULL);
    return 0;
}

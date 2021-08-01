//
// Created by jun on 2021/08/01.
//

#include <stdio.h>
#include <pthread.h>

int Func4(int *x){
    printf("new thread: x = %d\n", *x);
    return (*x)*2;
}

int main(int argc, char *argv[]){
    pthread_t th_id;
    int st, x=10, y;
    st = pthread_create(&th_id, NULL, (void *(*)(void *)) Func4, &x);
    if (st != 0){
        return 1;
    }
    // void ** がよくわからない
    pthread_join(th_id, (void **)&y);
    printf("answer : y = %d\n", y*10);
    return 0;
}
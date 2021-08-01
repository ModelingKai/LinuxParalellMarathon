#include <stdio.h>
#include <pthread.h>


void Func3(int *x) {
    printf("new thread: x = %d\n", *x);
}

int main(int argc, char *argv[]) {
    pthread_t th_id;
    int st, x;
    x = 1;

    st = pthread_create(&th_id, NULL, (void *(*)(void *)) Func3, &x);
    if (st != 0) {
        printf("can't crete new thread\n");
        return 1;
    }

    pthread_join(th_id, NULL);

    return 0;
}


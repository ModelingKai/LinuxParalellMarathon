
// Thread1: Func1(void)
// Thread2: Func2(void)

#include <stdio.h>
#include <pthread.h>

void Func1(void) {
    printf("thread1\n");
}

void Func2(void) {
    printf("thread2\n");
}

int main() {
    pthread_t th_id1, th_id2;
    int st1, st2;

    st1 = pthread_create(&th_id1, NULL, (void *(*)(void *)) Func1, NULL);
    if (st1 != 0) {
        printf("can't create thread1\n");
        return 1;
    }

    st2 = pthread_create(&th_id2, NULL, (void *(*)(void *)) Func2, NULL);
    if (st2 != 0) {
        printf("can't create thread2\n");
        return 1;
    }

    pthread_join(th_id1, NULL);
    pthread_join(th_id2, NULL);

    printf("All done\n");
}








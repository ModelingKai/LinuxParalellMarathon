#include <stdio.h>
#include <pthread.h>

void Func1(int d) {
    // 新しいスレッドで実行される関数
    printf("new thread: hello from %d\n", d);
}

int main(int arc, char *argv[]) {
    pthread_t th_id;
    int st;
    int *d;

    d = (int *) 123;
    st = pthread_create(&th_id, NULL, (void *(*)(void *)) Func1, d);

    if (st != 0) {
        return 1;
    }

    pthread_join(th_id, NULL); // スレッドの終了を待つ
    printf("joined\n");

    return 0;
}

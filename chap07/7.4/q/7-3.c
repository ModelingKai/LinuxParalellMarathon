#include <stdio.h>
#include <pthread.h>

struct pair {
    int x;
    float y;
};

void Func3(struct pair *p) {
    printf("new thread: x = %d y = %f\n", p->x, p->y);
}

int main(int argc, char *argv[]) {
    pthread_t th_id;
    int st, x;

    struct pair p;

    p.x = 1;
    p.y = 0.1;

    st = pthread_create(&th_id, NULL, (void *(*)(void *)) Func3, &p);
    if (st != 0) {
        printf("can't crete new thread\n");
        return 1;
    }

    pthread_join(th_id, NULL);

    return 0;
}


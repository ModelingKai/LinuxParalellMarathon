#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct board {
        char msg[10][1000];
        int empty; // 空の位置を指す変数
    } *top; // 電子掲示板へのポインタ

    key_t mykey;
    int shmid;
    char message[100];
    int k;

    mykey = ftok("/Users/mohira", 'b');
    if ((shmid = shmget(mykey, 0, 0)) != -1) {
        printf("電子掲示板は存在します\n");
        top = shmat(shmid, NULL, 0);
    } else {
        shmid = shmget(mykey, sizeof(struct board), IPC_CREAT | 0666);
        printf("電子掲示板を生成しました\n");
        top = shmat(shmid, NULL, 0);
        top->empty = 0;
    }


    for (;;) {
        printf("1:表示 2:投稿 3:終了 4:掲示板の削除 ？ ");

        fgets(message, 100, stdin);

        switch (message[0]) {
            case '1':
                printf("掲示板の内容\n");
                for (k = 0; k < top->empty; ++k) {
                    printf("%d: %s", k, top->msg[k]);
                }
                break;
            case '2':
                if (top->empty == 10) {
                    break;
                }
                printf("メッセージ？ ");
                fgets(message, 100, stdin);
                strcpy(top->msg[top->empty], message);

                top->empty += 1;
                break;
            case '3':
                shmdt(top);
                exit(0);
            case '4':
                shmdt(top);
                shmctl(shmid, IPC_RMID, 0);
                exit(0);
        }
    }
}

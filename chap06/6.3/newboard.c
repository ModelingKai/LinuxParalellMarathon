//
// Created by jun on 2021/08/01.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sem.h>

static struct sembuf down_1 = {0, -1, 0};
static struct sembuf up_1 = {0, 1, 0};

void down (int semaphore){
    semop(semaphore, &down_1, 1);
}

void up (int semaphore) {
    semop(semaphore, &up_1, 1);
}

int main() {
    struct board {
        char msg[10][100];
        int empty;
    } *top;

    key_t mykey;
    int shmid;
    char message[100];
    int k;

    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
        struct seminfo *__buf;
    };

    union semun arg;
    int semid;

    mykey = ftok("/home/jun", 'a');

    if((semid = semget(mykey, 1, 0)) == -1 ){
        semid = semget(mykey, 1, 0666 | IPC_CREAT);
        arg.val = 1;
        semctl(semid, 0, SETVAL, arg);
    }

    if((shmid = shmget(mykey, 0, 0 )) != -1 ){
        printf("電子掲示板は存在します\n");
        top = shmat(shmid, NULL, 0);
    } else {
        shmid = shmget(mykey, sizeof(struct board), IPC_CREAT | 0666);
        printf("電子掲示板を生成しました\n");
        top = shmat(shmid, NULL, 0);
        top->empty = 0;
    }

    for(;;){
        printf("1:表示 2:投稿 3:終了 4:掲示板の削除 ? ");
        fgets(message, 100, stdin);
        switch (message[0]) {
            case '1':
                printf("掲示板の内容\n");
                down(semid);
                for(k=0; k < top-> empty; k++){
                    printf("%d : %s", k, top->msg[k]);
                }
                up(semid);
                printf("sem val = %d\n", semctl(semid, 0, GETVAL));
                break;
            case '2':
                if (top->empty == 10) {
                    break;
                }
                printf("メッセージ ? ");
                fgets(message, 100, stdin);
                //  ここで危険領域だっていうことを示している
                down(semid);
                printf("sem val = %d\n", semctl(semid, 0, GETVAL));
                strcpy(top->msg[top->empty], message);
                top -> empty += 1;
                // もう大丈夫だよー
                up(semid);
                printf("sem val = %d\n", semctl(semid, 0, GETVAL));
                break;
            case '3':
                shmdt(top);
                exit(0);
            case '4':
                shmdt(top);
                // 共有メモリ
                shmctl(shmid,IPC_RMID, 0);
                // セマフォ
                semctl(semid,0,IPC_RMID);
                exit(0);
        }
    }
}



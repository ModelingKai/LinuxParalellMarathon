//
// Created by jun on 2021/08/01.
//


#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

int main() {
    struct msgbuf{
        long mtype;
        char mtext[80];
    };

    key_t mykey;
    int queid;
    struct msgbuf msg;

    mykey = ftok("/home/jun", 'a');
    queid = msgget(mykey, 0666 | IPC_CREAT);

    for(;;){
        printf("メッセージ ? ");
        if (fgets(msg.mtext, 80, stdin) == NULL) {
            exit(0);
        }
        if(strncmp(msg.mtext, "end", 3) == 0) {
            msgctl(queid, IPC_RMID, 0);
            exit(0);
        }
        msg.mtype = 2; // 宛先をプロセス2に指定する
        msgsnd(queid, &msg, strlen(msg.mtext)+1,0); // プロセス2へ送る
        msgrcv(queid, &msg,80, 1,0); // 自分宛てのメッセージを受け取る
        puts(msg.mtext); // メッセージを表示する
    }
}
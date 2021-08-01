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
    queid = msgget(mykey, 0666);

    for(;;){
        //  受信
        if(msgrcv(queid, &msg, 80, 2, 0) == -1){
            exit(0);
        }

        puts(msg.mtext);
        printf("メッセージ ? ");
        if (fgets(msg.mtext, 80, stdin) == NULL){
            exit(0);
        }
        msg.mtype = 1;
        msgsnd(queid, &msg, strlen(msg.mtext)+1, 0);

    }
}
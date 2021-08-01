#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    struct msgbuf {
        long mtype;
        char mtext[80];
    };

    key_t mykey;
    int queid;
    struct msgbuf msg;

    mykey = ftok("/home/jun", 'a');
    queid = msgget(mykey, 0666 | IPC_CREAT);

    char *ans[4];
    int rfd, wfd1, wfd2, k;
    char ch, client;

    ans[0] = "質問番号がおかしいよ！";
    ans[1] = "Tokyo";
    ans[2] = "ワシントンD.C.";
    ans[3] = "モスクワ";

    rfd = open("request", O_RDONLY);
    wfd1 = open("response1", O_WRONLY);
    wfd2 = open("response1", O_WRONLY);


    for (;;) {
        if(msgrcv(queid, &msg, 80, 1, 0) == -1) {
            exit(0);
        }
        strcpy(msg.mtext, ans[msg.mtext[0] - '0']);
        msg.mtype = 0;
        msgsnd(queid, &msg, strlen(msg.mtext)+1, 0);
    }
}
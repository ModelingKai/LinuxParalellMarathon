#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>


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

    for (;;) {
        printf("首都を探します。国名をいれてね\n");
        printf("0:exit, 1:Japan, 2:USA, 3:Russia ? ");

        if (fgets(msg.mtext, 80, stdin) == NULL) {
            exit(0);
        }

        msg.mtype = 1;
        msgsnd(queid, &msg, strlen(msg.mtext)+1, 0);
        msgrcv(queid, &msg, 80, 0, 0);
        puts(msg.mtext);
    }
}

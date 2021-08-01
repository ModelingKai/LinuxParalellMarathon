#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main() {

    int wfd, rfd, n;
    char client, cmd[80];
    wfd = open("request", O_WRONLY);
    printf("response2 open");

    client = '2';

    for (;;) {
        printf("首都を探します。国名をいれてね\n");
        printf("0:exit, 1:Japan, 2:USA, 3:Russia ? ");

        if (fgets(cmd, 80, stdin) == NULL) {
            exit(0);
        }

        if (cmd[0] == '0') {
            exit(0);
        }

        write(wfd, &client, 1); // 私はクライアント1ですよ
        write(wfd, cmd, 1); // 調べてほしい首都の国名のリクエスト

        n = read(rfd, cmd, 80);
        cmd[n] = '\0';
        printf("Answer:%s\n\n", cmd);
    }
}

#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
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
        if (read(rfd, &client, 1) == 0) {
            exit(0);
        }

        printf("Client%c ", client);

        if (read(rfd, &ch, 1) == 0) {
            exit(0);
        }

        printf("質問番号 = %c  ", ch);

        k = ch - '0';

        if (k > 3) {
            k = 0;
        }

        if (client == '1') {
            write(wfd1, ans[k], strlen(ans[k] + 1));
            printf("Answer = %s\n", ans[k]);
        } else if (client == '2') {
            write(wfd2, ans[k], strlen(ans[k] + 1));
            printf("Answer = %s\n", ans[k]);
        }
    }
}
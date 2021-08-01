//
// Created by mohira on 2021/08/01.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int argc; // コマンドのトークン数
    char cmd[80];
    char *cmdp; // 作業用ポインタ
    char *argv[10]; // トークンを入れる配列

    printf("コマンドを入力してください? ");

    if (fgets(cmd, 80, stdin) == NULL) {
        exit(0);
    }


    cmd[strlen(cmd) - 1] = '\0'; // 最後の改行文字をNULL文字に変更

    cmdp = cmd;

    for (argc = 0;; argc++) {
        if ((argv[argc] = strtok(cmdp, " ")) == NULL) {
            break;
        }
//        printf("%s \n", argv[argc]);
        cmdp = NULL;
    }

    printf("ex1 は %s に変身します\n", cmd);

    printf("PID=%d\n", getpid());
    execvp(argv[0], argv);
}
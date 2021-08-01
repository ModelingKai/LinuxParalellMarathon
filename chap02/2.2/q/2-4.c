//
// Created by jun on 2021/08/01.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int argc;
    char cmd[80];
    char *cmdp;
    char *argv[10];
    int status;
    char alias[80];

    for(;;){
        printf("コマンドを入力してください ? ");
        if(fgets(cmd, 80, stdin) == NULL) exit(0);
        cmd[strlen(cmd)-1] = '\0';
        cmdp = cmd;
        for(argc = 0; ; argc++) {
            if((argv[argc] = strtok(cmdp, " "))==NULL) break;

            if(strcmp(argv[0],"exit") == 0) {
                printf("親プロセスが終了しました\n");
                exit(0);
            }

            cmdp = NULL;
        }

        if(strcmp(argv[0],"alias") == 0) {
            // aliasを登録する
            // dir2='ls -la'
        }

        if(fork() == 0){
            // alias実行するもの
            if(strcmp(argv[0], "dir2") == 0) {
                execlp("ls", "ls", "-al", (char *)0);
            }
            printf("%s", argv[0]);
            execvp(argv[0], argv);
            printf("コマンドが見つかりませんでした\n");
            exit(1);
        }else{
            wait(&status);
        }
    }
}
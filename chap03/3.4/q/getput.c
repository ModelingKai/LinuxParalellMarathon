//
// Created by jun on 2021/08/01.
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *rfp, *wfp;
    char c;

    if ((rfp=fopen("oldfile", "r")) == NULL){
        exit(1);
    }
    c=getc(rfp);
    printf("%c\n", c);
    // 読み込んだ文字を入力バッファへ戻す
    ungetc(c,rfp);

    if(fork() == 0) {
        if((wfp=fopen("newfile3", "w")) == NULL)
        {
            exit(1);
        }
        while((c=getc(rfp)) != EOF) {
            putc(c,wfp);
        }
        fclose(rfp);
        fclose(wfp);
    }
    else
    {
        if((wfp= fopen("newfile4", "w")) == NULL) {
            exit(1);
        }
        while((c=getc(rfp)) != EOF) {
            putc(c, wfp);
        }
        fclose(rfp);
        fclose(wfp);
    }
}
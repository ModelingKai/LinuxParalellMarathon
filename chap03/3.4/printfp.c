//
// Created by jun on 2021/08/01.
//

#include <bits/types/FILE.h>
#include <stdio.h>

int main() {
    FILE *fp;
    int k;

    k=15;

    fp = fopen("newfile", "w"); // ファイルが無かったら勝手に作る
    fprintf(fp, "%d\n", k); // 指定したファイルポインタへ、出力バッファに書き込む
    fclose(fp); // ここでflushされ、出力バッファの内容を書き出す。
}
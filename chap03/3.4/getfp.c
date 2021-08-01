//
// Created by jun on 2021/08/01.
//

#include <bits/types/FILE.h>
#include <stdio.h>

int main() {
    FILE *fp;
    char buf[80];

    fp=fopen("oldfile","r");
    // 実際には20文字まで。21文字目には、'\0'が入る
    fgets(buf, 21,fp);
    fprintf(stdout, "%s\n", buf);
    fclose(fp);
}


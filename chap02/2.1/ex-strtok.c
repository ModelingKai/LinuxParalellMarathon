// http://www9.plala.or.jp/sgwr-t/lib/strtok.html
#include        <stdio.h>
#include        <string.h>

int main(void) {
    char str[] = "ABCD ef.1234.G";
    char str2[] = "Hello World";
    char *tp;

    puts(tp);

    // tp は トークンの先頭を示す「ポインタ」
    tp = strtok(str, " .");
    puts(tp);

    tp = strtok(NULL, " .");
    puts(tp);

    tp = strtok(str2, " ");
    puts(tp);
}

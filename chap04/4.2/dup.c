#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    fd = open("newfile", O_WRONLY | O_CREAT, 0664);

    close(1); // stdout を 開放する

    // dupは開放されているエントリの中で、もっと若い番号のfdに複製するぞ！
    dup(fd); // close(1)により、fd=1が欠番だから、fd=1はnewfileにつながる

    execlp("cat", "cat", (char *) 0);
}
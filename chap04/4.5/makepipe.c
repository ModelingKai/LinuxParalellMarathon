#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    if (mknod("mypipe", S_IFIFO | 0644, 0) == 0) {
        printf("mypipe created\n");
    } else {
        printf("mypipe exists\n");
    }
}
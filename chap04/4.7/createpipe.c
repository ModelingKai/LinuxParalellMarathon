//
// Created by jun on 2021/08/01.
//

#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main () {
    if(mknod("request", S_IFIFO | 0664, 0) == 0){
        printf("request created\n");
    }else {
        printf("request exists\n");
    }
    if(mknod("response1", S_IFIFO | 0664, 0) == 0){
        printf("response1 created\n");
    }else{
        printf("response1 exists\n");
    }
    if(mknod("response2", S_IFIFO | 0664, 0) == 0){
        printf("response2 created\n");
    }else{
        printf("response2 exists\n");
    }
}
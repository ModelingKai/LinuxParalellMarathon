cmake_minimum_required(VERSION 3.19)
project(LinuxParalellMarathon)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinuxParalellMarathon
        chap01/1.c chap01/1.2/1.c chap01/1.2/q/1-1.c chap01/1.2/q/1-2.c chap01/1.3/1.c chap01/1.3/2.c chap01/1.3/3.c chap01/1.3/4.c chap01/1.3/q/1-3.c chap01/1.3/q/1-4.c chap01/1.4/1.c chap01/1.4/2.c chap01/1.4/3.c chap01/1.4/q/1-5.c chap01/1.4/q/1-7.c chap02/2.1/1.c chap02/2.1/2.c chap02/2.1/3.c chap02/2.1/ex1.c chap02/2.1/ex-strtok.c chap02/2.2/shell.c chap02/2.2/q/2-3.c chap02/2.2/q/2-4.c chap03/3.1/copy1.c chap03/3.1/copy2.c chap03/3.1/copy3.c chap03/3.2/copy4.c chap03/3.3/arg.c chap03/3.3/cat.c chap03/3.3/q/3-1.c chap03/3.3/q/3-2.c chap03/3.4/getfp.c chap03/3.4/printfp.c chap03/3.4/q/getput.c chap03/3.4/q/print1.c chap03/3.4/q/print2.c chap04/4.3/pipe.c chap04/4.3/lsc.c chap04/4.3/q/4-5.c chap04/4.5/makepipe.c chap04/4.5/pread.c chap04/4.5/pwrite.c chap04/4.7/createpipe.c chap04/4.7/client1.c chap04/4.7/client2.c chap04/4.7/server.c chap05/5.2/proc1.c chap05/5.2/q/server.c  chap05/5.2/q/client1.c chap05/5.5/board.c)

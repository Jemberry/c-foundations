#include <my_header.h>

int main(int argc, char *argv[]){

    printf("father process. pid = %d\n", getpid());

    pid_t ret = fork();

    if(ret == 0){
        // 说明，这是在什么进程内部？ 子进程
        printf("child process, pid = %d\n", getpid());
        /* sleep(30); */
    }else{
        printf("father process, pid = %d\n", getpid());
        sleep(30);
    }

    /* sleep(30); */


    return 0;
}


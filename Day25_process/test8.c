#include <my_header.h>

int main(int argc, char *argv[]){

    // 孤儿进程，僵尸进程。 讲的是，在fork的时候，创建出来的进程的一些特殊情况。 
    // 孤儿进程： 父进程先结束，子进程迟迟不结束。 这时候子进程就被称为孤儿进程。 
    // 孤儿进程，会被一个进程收养。 pid=1的进程收养。 
    // 僵尸进程： 子进程先结束，父进程不结束。 因为父进程无法为其处理一些数据，所以会导致
    // 子进程无法退出。 Z状态。  


    // 创建子进程
    pid_t ret = fork();

    if(ret == 0){
        printf("child process.\n");
        while(1){
            printf("child process runnig.\n");
            sleep(1);
        }

    }else{
        printf("father process.\n");

        sleep(5);
        printf("father process over.\n");
    }


    return 0;
}


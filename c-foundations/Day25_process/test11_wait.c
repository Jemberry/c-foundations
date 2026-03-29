#include <my_header.h>

int main(int argc, char *argv[]){

    // fork的返回值，用于确认目前在父进程中，还是子进程中。
    pid_t fork_ret = fork();


    if(fork_ret == 0){
        // 这是子进程
        printf("child process.\n");
        sleep(30);
        printf("child process over.\n");
    }else{
        printf("father process, sleep before.\n");
        sleep(3);
        printf("father process, sleep after(wait before).\n");
        // 父进程. 用于等待一个子进程
        pid_t wait_ret = wait(NULL);
    
        printf("father process, wait after, wait_ret = %d.\n", wait_ret);
    }


    return 0;
}


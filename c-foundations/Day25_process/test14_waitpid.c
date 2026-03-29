#include <my_header.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    // waitpid 默认是一个阻塞函数，它会等待指定的一个子进程。 等待它结束
    // 我们可以给options设置一个值。 WNOHANG 会导致 waitpid 不再阻塞
    //
    
    pid_t fork_ret = fork();

    if(fork_ret == 0){
        // 子进程。 
        printf("child process begin.\n");
        sleep(30);
        printf("child process over.\n");
    }else{
        printf("father process begin.\n");
        pid_t wait_pid_ret = waitpid(fork_ret, NULL, WNOHANG);
    
        printf("father process waitpid over. ret = %d\n", wait_pid_ret);

    }


    return 0;
}


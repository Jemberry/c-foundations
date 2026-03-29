#include <my_header.h>

int main(int argc, char *argv[]){

    printf("fork before.\n");

    // fork 会创建出来一个子进程。 父子进程会执行一样的代码。 
    pid_t ret = fork();

    if(ret ==0 ){
        // 说明在子进程中。 
        printf("child process, pid = %d, ppid = %d, ret = %d\n", getpid(), getppid(), ret);
        sleep(20);
        printf("child process, sleep over.\n");
    }else{
        printf("father process, pid = %d, ppid = %d, ret = %d\n", getpid(), getppid(), ret);
        sleep(5);
        printf("father process, sleep over.\n");
    }


    // shell进程（父进程的父进程），只会等待父进程，也就是它创建出来的这个进程
    // 其余的进程，shell不等。
    return 0;
}


#include <my_header.h>

int main(int argc, char *argv[]){

    if(fork() == 0){
        // 子进程。 
        printf("child process begin.\n");
        sleep(30);
        printf("child process over.\n");
        return 10;
    }else{
        printf("father process begin.\n");
        int wstatus;
        // wait 的入参。相当于，就是得到子进程的状态的。 是否正常退，
        // 正常退，退出码是多少； 不正常退，信号标志是什么。 都在wstatus 里存
        pid_t wait_ret = wait(&wstatus);
        printf("father process over.\n");
        
        if(WIFEXITED(wstatus)){// 子进程正常退出
            printf("child status: %d \n", WEXITSTATUS(wstatus));
        }else if(WIFSIGNALED(wstatus)){//子进程信号退出
            printf("child signed: %d \n", WTERMSIG(wstatus));
        }

    }



    return 0;
}


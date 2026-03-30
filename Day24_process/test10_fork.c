#include <my_header.h>

int global_num = 111;
int main(int argc, char *argv[]){
    int num = 10;

    pid_t ret = fork();
    // 内存可以认为是隔开的。 父进程改，子进程看不到；
    // fork的内存，可以简单认为是复制。 但是，实际实现的时候，并不直接复制。 
    // 采取的是写时复制。 COW copy on write. 
    if(ret ==0){
        num = 9999;
        global_num = 1234;
        printf("child process, num = %d, global_num = %d\n", num, global_num);
    }else{
        sleep(2);
        printf("father process, num = %d, global_num = %d\n", num, global_num);
    }


    return 0;
}


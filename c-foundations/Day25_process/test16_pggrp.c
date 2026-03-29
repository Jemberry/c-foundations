#include <my_header.h>

int main(int argc, char *argv[]){


    // 进程有自己的id。pid 进程，也有组的概念。 叫做组id
    // getpgrp 获取组id。 
    printf("pid = %d, pgrp = %d\n", getpid(), getpgrp());

    // 组id。 默认是跟外面的shell一起的。 但是启动时候，会设置为自己的pid。 
    
    if(fork() == 0){
        // setpgid来设置，组id。让自己独成一组
        setpgid(0, 0);

        // 子进程。 
        printf("child process pid = %d, pgrp = %d\n", getpid(), getpgrp());
    }else{
        printf("father process pid = %d, pgrp = %d\n", getpid(), getpgrp());
    }



    return 0;
}


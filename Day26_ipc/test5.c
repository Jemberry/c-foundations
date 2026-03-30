#include <fcntl.h>
#include <my_header.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    // 匿名管道： 就是pipe函数直接创建管道。 由于父子进程是会复制文件描述符的
    // pipe  + fork 

    int arr[2] = {0};
    pipe(arr); // 创了一根管子。0下标，是读文件描述符； 1下标，是写文件描述符
    
    pid_t ret = fork();

    if(ret == 0){
        // 子进程。 往管子中写消息。 父进程读到消息。 
        // arr[1] : 写文件描述符
        int write_fd = arr[1];

        char msg[] = "msg from ccccccccchild.";
        write(write_fd, msg, sizeof(msg));

    }else{
        // arr[0] : 读文件描述符
        int read_fd = arr[0];
        char buf[100] = {0};
        read(read_fd, buf, sizeof(buf));

        printf("father process read from pipe: %s\n", buf);
    }



    return 0;
}


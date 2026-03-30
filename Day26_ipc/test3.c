#include <bits/pthreadtypes.h>
#include <fcntl.h>
#include <my_header.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    // 现在，想在一个c文件中，启俩进程。  fork 
    // 让这俩进程，进程间通信。
    mkfifo("1.pipe", 0600);
    pid_t ret = fork();

    if(ret == 0 ){
        // 子进程。 光开一端，阻塞
        printf("child process open before\n");
        int fd = open("1.pipe", O_RDONLY);
        printf("child process open after\n");

        char buf[100] = {0};
        read(fd, buf, sizeof(buf));
        printf("child process read buf: %s\n", buf);

        close(fd);
    }else{
        printf("father process sleep before\n");
        sleep(5);
        printf("father process sleep after(open before)\n");
        int fd = open("1.pipe", O_WRONLY);
        printf("father process open after\n");

        char content[] = "msg from father process";
        write(fd, content, sizeof(content));

        close(fd);
    }


    unlink("1.pipe");
    return 0;
}


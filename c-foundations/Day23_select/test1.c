#include <my_header.h>

int main(int argc, char *argv[]){

    // select 简单说，就是系统提供给你的监听多个文件描述符的函数。 
    // read(STDIN_FILENO, ... ) 监听（看这个文件描述符是否可用）+捞数据
    // 文件描述符，是否可用。指的是。 
    // STDIN_FILENO: 说的是键盘中有数据
    // read_fd: 说的是管道中有数据。 

    /* select(10, NULL, NULL, NULL, NULL); */

    fd_set readset;
    // 系统不希望大家了解其中的字段， 也想让大家使用。 系统提供了几个宏给大家使用。 
    FD_ZERO(&readset);
    // 将1这个文件描述符加入了 fd_set 
    FD_SET(STDIN_FILENO, &readset);

    // select 会阻塞。 阻塞到，监听的文件描述符中最少一个可用，会结束阻塞。 
    int ret = select(10, &readset, NULL, NULL, NULL);
    printf("ret = %d\n", ret);

    // 监听了多个文件描述符。 哪一个文件描述符可用？
    // 入参是 *。 没有用const修饰，信息是通过指针的方式带出，传入传出参数
    // 所以，select结束之后。 在fd_set中的文件描述符，就是可用的文件描述符
    FD_ISSET(STDIN_FILENO, &readset);
    
    if(FD_ISSET(STDIN_FILENO, &readset)){
        // 说明文件描述符在 fd_set中.
        // STDIN_FILENO 文件描述符可用。 说明键盘有信息。 

        char buf[100] = {0};
        read(STDIN_FILENO, buf, sizeof(buf));
        printf("read from stdin: %s\n", buf);
    }

    return 0;
}


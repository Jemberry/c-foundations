#include <my_header.h>

int main(int argc, char *argv[]){
    // fork的返回值问题： 
    pid_t ret = fork();

    // 这个位置。 几个进程执行？
    // 我靠返回值 ret来确定当前在父进程中，还是子进程中。 
    // ret 是 0， 表明目前在子进程中； ret是正数，表明目前在父进程中， ret的值是子进程pid。 

    printf("ret = %d\n", ret);

    return 0;
}


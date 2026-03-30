#include <my_header.h>

int main(int argc, char *argv[]){

    // pid 是进程ID。 ppid 是进程父进程id。
    // ./test1 
    // getpid()  getppid()

    /* getpid(); */
    printf("pid = %d\n", getpid());
    printf("ppid = %d\n", getppid());

    sleep(60);

    return 0;
}


#include <my_header.h>

int main(int argc, char *argv[]){

    pid_t ret = fork();

    if(ret == 0){
        printf("child process.\n");

        // 不行。 在使用exec的时候，参数是什么就是什么。 为了保持 shell调用和
        // execl 调用的一致性。 将execl 的第一个参数，写成path
        /* execl("./test6_calculate", "6", "7", (void *)0); */
        // ./test6_calculate 8 9
        execl("./test6_calculate","./test6_calculate" , "8", "7", (void *)0);

    }else{
        printf("father process.\n");
        sleep(20);

        printf("father over.\n");
    }

    return 0;
}


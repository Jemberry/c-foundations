#include <my_header.h>

int main(int argc, char *argv[]){

    // 在重定向这个节，再任何操作之前，先输出依次
    // 重点重点重点：：：：：：：一定要有 \n
    printf("hello world.\n");

    int fd = open("1.txt", O_RDONLY);
    printf("fd = %d\n", fd);




    return 0;
}


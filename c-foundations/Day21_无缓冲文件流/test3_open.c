#include <my_header.h>
#include <stdio.h>

int main(int argc, char *argv[]){

    // 之前打开有缓冲区文件流。使用fopen  现在使用open开无缓冲区文件流。

    printf("%o\n", O_RDONLY);
    printf("%o\n", O_WRONLY);
    printf("%o\n", O_RDWR);
    printf("%o\n", O_APPEND);

    


    return 0;
}


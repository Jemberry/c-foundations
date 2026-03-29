#include <my_header.h>

int main(int argc, char *argv[]){

    printf("111111\n");
    close(1);

    int fd = open("1.txt", O_WRONLY);
    printf("fd = %d\n", fd);

    close(fd);


    return 0;
}


#include <my_header.h>

int main(int argc, char *argv[]){

    int fd = open("1.pipe", O_WRONLY);
    printf("open after.\n");

    sleep(30);

    char content[] = "hhhhhhhh from write";
    write(fd, content, sizeof(content));

    return 0;
}


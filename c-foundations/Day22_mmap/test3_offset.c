#include <my_header.h>

int main(int argc, char *argv[]){

    int fd = open("1.txt", O_RDONLY);
    ERROR_CHECK(fd, -1, "open failed");

    char *p = (char *)mmap(NULL, 10, PROT_READ, MAP_SHARED, fd, 0);
    ERROR_CHECK(p, MAP_FAILED, "mmap failed");
    // offset的值，只能是 4096 的倍数

    for(int i=0; i< 10; i++){
        printf("%d-----\n", p[i]);
    }

    munmap(p, 10);
    close(fd);


    return 0;
}


#include <my_header.h>

int main(int argc, char *argv[]){

    printf("fork before.\n");
    pid_t ret = fork();
    printf("fork after.\n");

    pid_t ret2 = fork();
    printf("fork after2.\n");


    return 0;
}


#include <my_header.h>

int main(int argc, char *argv[]){
    printf("11111------\n");
    int write_fd = open("2.pipe", O_WRONLY);
    printf("22222------\n");
    int read_fd = open("1.pipe", O_RDONLY);
    printf("33333------\n");
    ERROR_CHECK(write_fd, -1, "open 2.pipe failed");
    ERROR_CHECK(read_fd, -1, "open 1.pipe failed");

    char content[] = "msggggggg from userbbbbbb";
    write(write_fd, content, sizeof(content));

    char buf[100] = {0};
    read(read_fd, buf, sizeof(buf));
    printf("userb get msg: %s\n", buf);

    close(read_fd);
    close(write_fd);



    return 0;
}


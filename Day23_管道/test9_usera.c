#include <my_header.h>

int main(int argc, char *argv[]){
    // 一定要保证两个管子。是存在的。 1.pipe 2.pipe 
    printf("11111-----\n");
    int write_fd = open("1.pipe", O_WRONLY);
    printf("22222-----\n");
    int read_fd = open("2.pipe", O_RDONLY);
    printf("33333-----\n");

    ERROR_CHECK(write_fd, -1, "open 1.pipe failed");
    ERROR_CHECK(read_fd, -1, "open 2.pipe failed");

    char content[] = "hello from useraaaaaa";
    write(write_fd, content, sizeof(content));

    char buf[100] = {0};
    read(read_fd, buf, sizeof(buf));
    printf("usera get msg: %s\n", buf);
    // read  write 的len语义是不一样的。 一个是最多能装多少
    // 一个是实际要写出去多少。 
    close(read_fd);
    close(write_fd);



    return 0;
}


#include <my_header.h>

int main(int argc, char *argv[]){

    // 现在有一个大文件。 10G
    // 分段映射。 再将每一段弄出去。 
    // 使用mmap的方式，完成大文件的复制。 
    //
    // 1.文件大小怎么拿？fstat 

    int fd = open(argv[1], O_RDONLY);
    struct stat stat_buf;
    fstat(fd, &stat_buf);

    printf("%ld\n", stat_buf.st_size);

    return 0;
}


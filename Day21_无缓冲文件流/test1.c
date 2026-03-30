#include <my_header.h>
#include <stdio.h>

int main(int argc, char *argv[]){

    FILE *fp = fopen("1.txt", "r");
    ERROR_CHECK(fp, NULL, "fopen failed");
    // fgetc 
    // fread

    char buf[120] = {0};
    int ret = fread(buf, sizeof(char), 100, fp);
    printf("fread = %s\n", buf);

    // 在之前的文件流中。 内核发挥了怎样的作用？
    // 内存分两类： 内核区域，非内核区域/用户空间
    // 有缓冲文件流：指的是，在用户空间，有一块缓冲区。数据会首先存储在
    // 缓冲区。 其次读数据的时候。才会进入自己的数组
    // 有缓冲文件流。 说的是有缓冲区，位于用户空间。 
    // 作用是防呆，即使你不知道缓冲区的设计目的，fgetc fgetc。
    // 效率也不至于太差。 
    
    FILE *fp1;
    fp1->_unused2;
    // FILE 中存在大量指针，指针是
    // 用户空间的指针，不是内核的



    fclose(fp);

    return 0;
}


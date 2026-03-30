#include <my_header.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    // mkdir 就是创建目录。 

    // 也会收到umask的控制。 也就是将umask里面的内容掩去。
    mode_t mode = 0767;
    int ret = mkdir("test111", mode);
    
    printf("ret = %d\n", ret);
    ERROR_CHECK(ret, -1, "mkdir failed");

    // ./test7_mkdir test222 777
    //
    return 0;
}


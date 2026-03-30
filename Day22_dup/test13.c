#include <my_header.h>

int main(int argc, char *argv[]){

    printf("11111111\n");

    int ret = dup2(STDOUT_FILENO, 10);

    // 返回值就是系统告诉你，许愿成功还是失败。 
    printf("fd = %d\n", ret);

    // 文件描述符有文件对象在使用， 或者没有使用。 
    // 1.如果文件描述符没有被使用，直接给你
    // 2.如果文件描述符被使用了。直接将文件描述符和文件对象之间的
    // 关系断掉，再让它指向你。
    // 返回值就是是否申请到。 

    return 0;
}


#include <my_header.h>

int main(int argc, char *argv[]){

    // 现在都是在重定向输出。 能不能重定向输入
    // scanf ： 本来从键盘进。 从文件描述符0读数据。 
    // 如果将0关掉，重新打开了一个文件。 占用文件描述符0
    // 这时候。 如果使用scanf 直接从文件读数据。 
    close(STDIN_FILENO);

    ARGS_CHECK(argc, 2);
    int fd = open(argv[1], O_RDONLY);

    printf("fd = %d\n", fd);


    int num1 = 0;
    double d1 = 0.0;

    scanf("%d %lf", &num1, &d1);

    printf("num1 = %d\n d1 = %lf\n", num1, d1);

    // 输入重定向
    return 0;
}


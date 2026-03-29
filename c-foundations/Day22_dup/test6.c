#include <my_header.h>

int main(int argc, char *argv[]){

    FILE *fp = fopen("222.txt", "w");
    ERROR_CHECK(fp, NULL, "fopen failed");

    fputs("hello\n", fp);
    fflush(fp);
    // 有缓冲区文件流是一个满缓冲区。 如果缓冲区满，才会输出到内核
    // printf标准输出，是一个行缓冲区。  \n

    write(3, "world", 5);
    fclose(fp);

    return 0;
}


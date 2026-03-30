#include <my_header.h>

int main(int argc, char *argv[]){

    FILE *fp = fopen("222.txt", "w");
    ERROR_CHECK(fp, NULL, "fopen failed");

    /* fputs("hello", fp); */
    fputs("hello\n", fp);

    write(3, "world", 5);
    fclose(fp);

    return 0;
}


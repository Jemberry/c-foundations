#include <my_header.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    int ret = rmdir("test111");
    ERROR_CHECK(ret, -1, "rmdir failed");
    return 0;
}


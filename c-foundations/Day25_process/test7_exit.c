#include <my_header.h>

void func(){
    // exit(EXIT_SUCCESS);
    //_exit(EXIT_SUCCESS);
    _Exit(EXIT_SUCCESS);
}
int main(){
    printf(" 123 ");
    func();
    return 0;
}

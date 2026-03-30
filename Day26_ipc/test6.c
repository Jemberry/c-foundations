#include <my_header.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    // 父子进程之间，想实现 有来有往的通信。 也就是双向的。 
    // 现在需要两根管子。 
    //
    // pipe 一下创建一根。 pipe两下。 
    
    int arr[2] = {0};
    int arr2[2] ={0};

    pipe(arr);
    pipe(arr2);

    printf("%d %d %d %d\n", arr[0], arr[1], arr2[0], arr2[1]);

    // 管子的名字，如果不注意。很容易搞晕。 




    return 0;
}


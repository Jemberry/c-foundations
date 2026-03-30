#include <my_header.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    // 父子进程之间，想实现 有来有往的通信。 也就是双向的。 
    // 现在需要两根管子。 
    // pipe 一下创建一根。 pipe两下。 
    
    int child_to_father_arr[2] = {0};
    int father_to_child_arr[2] ={0};

    pipe(child_to_father_arr);
    pipe(father_to_child_arr);

    pid_t ret = fork();

    if(ret == 0){
        // 子进程。 
        // child_to_father_arr write. child_to_father_arr[1]
        // father_to_child_arr read. father_to_child_arr[0]
        close(father_to_child_arr[1]);
        close(child_to_father_arr[0]);

        int read_fd = father_to_child_arr[0];
        int write_fd = child_to_father_arr[1];

        char msg[] = "hello from child";
        write(write_fd, msg, sizeof(msg));

        char buf[100] = {0};
        read(read_fd, buf, sizeof(buf));

        printf("child process read from pipe: %s\n", buf);

        close(read_fd);
        close(write_fd);
    }else{
        // child_to_father_arr read. child_to_father_arr[0]
        // father_to_child_arr write. father_to_child_arr[1]
        int read_fd = child_to_father_arr[0];
        int write_fd = father_to_child_arr[1];

        char msg[] = "hello from fatherrrrrr";
        write(write_fd, msg, sizeof(msg));

        char buf[100] = {0};
        read(read_fd, buf, sizeof(buf));

        printf("father process read from pipe: %s\n", buf);
        // 
    }

    // 父子进程可以发文件。  
    // 1.txt     2.txt 
    // 没有办法直接读取标准输入。来实现发消息。 

    return 0;
}


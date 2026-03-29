#include <my_header.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    ARGS_CHECK(argc, 2);
    // ./test15_stat 1.txt  
    // ..   /home/zhou/test1 

    struct stat *stat_p = (struct stat *)malloc(sizeof(struct stat));
    int ret = stat(argv[1], stat_p);

    ERROR_CHECK(ret, -1, "stat failed");

    printf("%o %ld %d %d %ld %ld\n", 
           stat_p->st_mode, stat_p->st_nlink, 
           stat_p->st_uid, stat_p->st_gid, 
           stat_p->st_size, stat_p->st_mtim.tv_sec);





    return 0;
}


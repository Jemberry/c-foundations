#include <bits/types/stack_t.h>
#include <dirent.h>
#include <my_header.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    // 我们使用目录流，获取目录中的子项（dirent  ）
    // 可以提供： inode  name type 

    ARGS_CHECK(argc, 2);
    DIR *dirp = opendir(argv[1]);
    ERROR_CHECK(dirp, NULL, "opendir failed");
    chdir(argv[1]);

    struct dirent *dirent_p = NULL;
    struct stat *stat_p = calloc(1, sizeof(struct stat));
    while((dirent_p = readdir(dirp)) != NULL){
        /* printf("%s-----\n", dirent_p->d_name); */
        // 可以将获取到的name。塞进stat。 用于获取详细信息。 
        int ret = stat(dirent_p->d_name, stat_p);
        ERROR_CHECK(ret, -1, "stat failed");

        // stat_p 有绝大多数信息。 但是差名字。 
        // dirent 结构体中有名字。 
        
        printf("%o %ld %d %d %ld %ld %s\n", stat_p->st_mode, stat_p->st_nlink, 
               stat_p->st_uid, stat_p->st_gid,
               stat_p->st_size, stat_p->st_mtime, 
               dirent_p->d_name);

    }

    closedir(dirp);

    return 0;
}


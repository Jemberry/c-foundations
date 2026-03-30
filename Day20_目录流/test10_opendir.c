#include <dirent.h>
#include <my_header.h>
#include <stdio.h>

int main(int argc, char *argv[]){

    DIR *dirp = opendir("/home/zhou/cpp71");

    ERROR_CHECK(dirp, NULL, "opendir failed");

    // 使用。 读目录流。 读出来的是这个目录中装了哪些子项，目录项。 
    struct dirent *dirent_p = readdir(dirp);

    // dirent里面 的字段。不多。 
    /* dirent_p->d_ino; */
    printf("%ld %s %ld\t  %d %d\n", 
           dirent_p->d_ino, dirent_p->d_name, dirent_p->d_off, 
           dirent_p->d_reclen, dirent_p->d_type);

    closedir(dirp);
    return 0;
}


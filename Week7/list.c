#include <stdio.h>
#include <sys/types.h>//opendir
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <sys/stat.h>
#include <unistd.h>

   //    struct dirent *readdir(DIR *dirp);
void showStatInfo(const char *fname, struct stat *buf);
int main(){
    DIR *dirp;
    struct dirent *pDir;
    dirp = opendir("..");
    if (dirp ==NULL){
        perror("Openning directory");
        exit(1);
    }

    // while((pDir=readdir(dirp))!=NULL){
    //     if ((pDir->d_name)[0] != '.')
    //         printf("%s\n", pDir->d_name);
    // }
    struct stat statbuf;
    pDir=readdir(dirp);
    printf("%s\n", pDir->d_name);
    if(stat("../Week4", &statbuf) != -1){
       showStatInfo("../Week4",&statbuf ); 
    }else{
        printf("Is -1\n");
    }
    

    closedir(dirp);


}

void showStatInfo(const char *fname, struct stat *buf)
{
    printf("   mode: %o\n", buf->st_mode);
    printf("  links: %ld\n", buf->st_nlink);
    printf("   user: %d\n", buf->st_uid);
    printf("  group: %d\n", buf->st_gid);
    printf("   size: %ld\n", buf->st_size);
    printf("modtime: %ld\n", buf->st_mtime);
    printf("   name: %s\n", fname);
}

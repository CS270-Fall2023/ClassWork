#include <stdio.h>
#include <sys/types.h>//opendir
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define MAXPATH 512

void list(const char *dirName);
void showStatInfo(const char *fname, struct stat *buf);

int main(int argc, char * argv[]){
    if (argc ==1){
        list(".");
    }
    else{
        while(--argc){
            printf("%s:\n", *++argv);
            list(*argv);
        }
    }
   
    return 0;
}
void list(const char *dirName){
    DIR *dirp;
    struct dirent *pDir;
    dirp = opendir(dirName);
    if (dirp ==NULL){
        perror("Openning directory");
        exit(1);
    }else{
        while((pDir=readdir(dirp))!=NULL){
            char fileName[MAXPATH];//need to construct file name
            struct stat statbuf;//needs to colect infor about file

            strcpy(fileName, dirName);// fileName = "test"
            if (dirName[strlen(dirName)-1] != '/'){//fileName = "test/""
                strcat(fileName, "/");
            }
            strcat(fileName, pDir->d_name);//fileName = "test/junk.txt"

            if(stat(fileName, &statbuf) != -1){
                showStatInfo(pDir->d_name, &statbuf ); //first arg needs to see if file name starts with '.'
            }else{
                perror(pDir->d_name);
            }    
        }
        closedir(dirp);   
    }
}
void showStatInfo(const char *fname, struct stat *buf)
{
    if (fname[0] == '.')//don't display infor for hiden files
        return;

    printf("   name: %s\n", fname);
    printf("   mode: %o\n", buf->st_mode);
    printf("  links: %ld\n", buf->st_nlink);
    printf("   user: %d\n", buf->st_uid);
    printf("  group: %d\n", buf->st_gid);
    printf("   size: %ld\n", buf->st_size);
    printf("modtime: %ld\n\n", buf->st_mtime);
}

#include <stdio.h>
#include <sys/types.h>//opendir
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysmacros.h>
#include <pwd.h>
#include <grp.h> 
#include <time.h>

#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAXPATH 512

void list(const char *dirName);
void showStatInfo(const char *fname, struct stat *buf);
void modeToLetters(int mode, char str[]);

char* uidToName(uid_t id);
char* gidToName(gid_t id);

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
    char strMode[11];
    
    //printf("   mode: %o\n", buf->st_mode);
    modeToLetters(buf->st_mode, strMode);
    //printf("   mode: %s\n", strMode);
    printf("%-12s", strMode);
    //printf("  links: %ld\n", buf->st_nlink);
    printf("%-3ld", buf->st_nlink);
    //printf("   user: %d\n", buf->st_uid);
    //printf("   user: %s\n", uidToName(buf->st_uid));
    printf("%-12s", uidToName(buf->st_uid));
    
    //printf("  group: %d\n", buf->st_gid);
    //printf("  group: %s\n", gidToName(buf->st_gid));
    printf("%-12s", gidToName(buf->st_gid));
    //printf("   size: %ld\n", buf->st_size);
    printf("%6ld", buf->st_size);

    printf("   name: %s\n", fname);
    char strMode[11];
    modeToLetters(buf->st_mode, strMode);
    //printf("   mode: %o\n", buf->st_mode);
    printf("   mode: %s\n", strMode);

    printf("  links: %ld\n", buf->st_nlink);
    //printf("   user: %d\n", buf->st_uid);
    printf("   user: %s\n", uidToName(buf->st_uid));
    //printf("  group: %d\n", buf->st_gid);
    printf("  group: %s\n", gidToName(buf->st_gid));
    printf("   size: %ld\n", buf->st_size);
    //printf("modtime: %ld\n\n", buf->st_mtime);
    printf("modtime: %.12s\n\n", 4+ctime(&buf->st_mtime));
}

void modeToLetters(int mode, char str[])
{
    strcpy(str, "----------");
    if (S_ISDIR(mode)) str[0] = 'd';  // directory
    if (S_ISCHR(mode)) str[0] = 'c';  // char device
    if (S_ISBLK(mode)) str[0] = 'b';  // block device

    // 3 bits for user
    if (mode & S_IRUSR) str[1] = 'r';
    if (mode & S_IWUSR) str[2] = 'w';
    if (mode & S_IXUSR) str[3] = 'x';

    // 3 bits for group
    if (mode & S_IRGRP) str[4] = 'r';
    if (mode & S_IWGRP) str[5] = 'w';
    if (mode & S_IXGRP) str[6] = 'x';

    // 3 bits for other
    if (mode & S_IROTH) str[7] = 'r';
    if (mode & S_IWOTH) str[8] = 'w';
    if (mode & S_IXOTH) str[9] = 'x';
}

char* uidToName(uid_t id)
{
    return getpwuid(id)->pw_name;
}

char* gidToName(gid_t id)
{
    return getgrgid(id)->gr_name;
}

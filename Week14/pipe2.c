// pipes2.c
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXLINE 100

int main( void ) 
{ 
    int n; 
    int fd1[2]; 
    int fd2[2]; 
    pid_t pid; 
    char line[MAXLINE];
    
    if (pipe(fd1) < 0) //creat pipe
    {
        perror("pipe error");
        exit(1);
    }
    if (pipe(fd2) < 0) //creat pipe
    {
        perror("pipe error");
        exit(1);
    }

    if ((pid = fork()) < 0)
    {
        perror("fork error"); 
        exit(1);
    } 
    else if (pid > 0)   /* parent */
    {
        close(fd1[0]); //close read end
        if (write(fd1[1], "Hello from parent\n", 18)!=18){
            perror("parent writes"); 
            exit(1); 
        } 
        
        close(fd2[1]); //close write end
        n = read(fd2[0], line, MAXLINE); 
        if (n<0){
            perror("parent reads"); 
            exit(1);
        }
        line[n]='\0';
        printf("Parent read: %s\n", line);
        wait(NULL);
    } 
    else                /* child  */
    {
        close(fd1[1]); //close write end
        n = read(fd1[0], line, MAXLINE); 
        if (n<0){
            perror("child reads"); 
            exit(1);
        }
        line[n]='\0';
        printf("Child read: %s\n", line); 

        close(fd2[0]); //close read end
        if (write(fd2[1], "Hello from child\n", 17)!=17){
            perror("child writes"); 
            exit(1); 
        } 
        exit(0); 
    }
}

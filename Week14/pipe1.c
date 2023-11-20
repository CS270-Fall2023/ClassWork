// pipes1.c
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXLINE 100

int main( void ) 
{ 
    int n; 
    int fd[2]; 
    pid_t pid; 
    char line[MAXLINE];
    
    if (pipe(fd) < 0) //creat pipe
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
        close(fd[0]); //close read end
        write(fd[1], "Hello world\n", 12); 
        wait(NULL);
    } 
    else                /* child  */
    {
        close(fd[1]); //close write end
        n = read(fd[0], line, MAXLINE); 
        write(1, line, n); 
        exit(0); 
    }
}

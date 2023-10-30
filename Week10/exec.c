#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    printf("I am an original comand\n");

    pid_t pid = fork();  // int pid = fork();
    if (pid == -1)
    {
        fprintf(stderr, "the process creation failed\n"); 
    }
    else if (pid == 0)
    {
        execlp("ls", "ls", NULL);  
    
    }
    else
    {
        wait(NULL);
        printf("I am back to original comand\n");
    }
    return 0;
}
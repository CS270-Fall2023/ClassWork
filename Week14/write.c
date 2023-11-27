// writer.c
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h> // getpid(), stat()
#include <sys/stat.h>  // stat()
#include <unistd.h>    // write(), getpid(), close(), sleep(), stat()

int main()
{
    printf("Client process ID: %d\n", getpid());

    // Prepare message
    char message[100];
    sprintf(message, "Hello from PID %d", getpid());
    int messageLen = strlen(message) + 1; // include NULL
    
    // Keep checking if pipe file exist
    struct stat st;
    while (stat("aPipe", &st) < 0)
    {
        sleep(1);
    }
    // Additionally, we can verify if aPipe 
    // is a pipe file using struct stat st

    // Open named pipe for writing
    int fd = open("aPipe", O_WRONLY);  

    // Send three messages
    for (int i = 1 ; i <= 3 ; i++ )
    {
        // Write message down pipe 
        printf("Sending message to server...\n");
        write(fd, message, messageLen); 
        sleep(3); // Pause a while
    }
    
    // Close pipe descriptor
    close(fd); 
}

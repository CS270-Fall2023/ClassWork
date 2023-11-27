// reader.c
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int readLine(int fd, char* str);

int main ()
{
    // Create named pipe
    // mkfifo("aPipe", 0660);        
    mknod("aPipe", S_IFIFO | 0660, 0);

    while (1) // Server continues running forever
    {
        printf("Waiting for a client...\n");
        // Open named pipe for reading 
        int fd = open("aPipe", O_RDONLY);  
        // Read and display received messages
        char str[100];
        while (readLine(fd, str))    
            printf ("%s\n", str);

        // Close named pipe
        close(fd);  
    }                  
}

/**
 * @brief Read a single NULL-terminated line into str from fd
 * 
 * @param fd   named pipe file descriptor
 * @param str  characters read from named pipe
 * @return int 0 when the end-of-input is reached and 
 *             1 otherwise
 */
int readLine(int fd, char* str)
{
    int n;

    // Read characters until NULL or end-of-input
    while (1) 
    {
        n = read(fd, str, 1); // Read one character
        if (n == 0 || *str++ == 0)
            break;
    }

    return (n > 0); // Return false if end-of-input
}

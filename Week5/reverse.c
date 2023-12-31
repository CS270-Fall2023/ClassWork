#include <stdio.h>
#include <sys/types.h>//open
#include <sys/stat.h>//open
#include <fcntl.h>//open
#include <stdlib.h> //exit
#include <unistd.h> //close//read
#include <string.h>

#define BUF_SIZE 4096
#define MAX_NUM_LINES 200

int main(int argc, char *argv[]){
    char buffer[BUF_SIZE];
    ssize_t bytesRead;

    int fd_input = open("test2.txt", O_RDONLY);
    if (fd_input == -1){
        perror("Opening input file");
        exit(1);
    }
    //ssize_t read(int fd, void *buf, size_t count);
    bytesRead=read(fd_input, buffer, BUF_SIZE);

    //print to the console
    //ssize_t write(int fd, const void *buf, size_t count);
    if (write(1,buffer, bytesRead ) != bytesRead){
        perror("Printing to the console");
        exit(1);
    }

    if(close(fd_input)==-1){
        perror("Closing input file");
        exit(1);
    }

    int newlines[MAX_NUM_LINES];
    int index=1,
        count = 1;
    newlines[0]=-1;//was 0
    for (int i =0; i <bytesRead; i++){
        if (buffer[i]=='\n'){
            newlines[index] = i;
            index++;
            count++;
        }
    }
    //newlines[-1, 6, 13, 20, 28]

    char ** lines = malloc(count * sizeof(char *));
    index=0;
    //copy lines from buffer in reverce order
    for (int i = count-1; i >0; i--){
        int lenght=newlines[i]-newlines[i-1];
        char temp[100];
        printf("%.*s", lenght, buffer+newlines[i-1]+1);
        // lines[index]=malloc((lenght+1)*sizeof(char));
        // strncpy(lines[index], buffer + newlines[i-1]+1, lenght);
        // lines[index][lenght]='\0';
        // index++;
    }
    //print lines






}
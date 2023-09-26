#include <stdio.h>
#include <errno.h>
#include <sys/types.h>//open
#include <sys/stat.h>//open
#include <fcntl.h>//open
#include <unistd.h> //close()

int main () {
   //using system call
     int fd = open("unexist.txt", O_RDONLY); /* system call to open a file */
     if (fd == -1) {
          perror("Error printed by perror");
     }
     if (close(fd) == -1) {
          perror("Error printed by perror");
     }
   return 0;
}

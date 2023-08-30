#include <stdio.h>
#include <stdlib.h>

int main(){
    char * string = NULL;
    int size;
    printf("Enter the size of input: ");
    scanf("%d", &size);
    string = malloc(size*sizeof(*string));
    printf("Please, enter the string: ");
    //you might need somthing here
    //getchar();
    getc(stdin);
    fgets(string, size, stdin);
    if (string != NULL)
        printf("You enterd: %s\n", string);
    char newString[20];
    fgets(newString, size, stdin);
    printf("You enterd: %s\n", newString);
    free(string);
    return 0;

}
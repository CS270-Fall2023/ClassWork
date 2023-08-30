#include <stdio.h>
#include "nano.h"

int main(){
    char word[256];
    printf("Enter the \"word\": ");
    scanf(word);
    if (nanoIsInWord(word)){
        printf("nano is in the %s\n", word);
    } else{
        printf("nano is in the %s\n", word);
    }
    return 0;
}
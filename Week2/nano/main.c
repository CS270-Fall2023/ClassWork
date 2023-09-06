/**
 * @file main.c
 * @author Ekaterina Miller
 * @brief This program checks if string has "nano" substring
 * @version 0.1
 * @date 2023-09-01 
 */
#include <stdio.h>
#include "nano.h"

int main(){
    char word[256];
    printf("Enter the \"word\": ");
    scanf("%s",word);
    if (nanoIsInWord(word)){
        printf("nano is in the %s\n", word);
    } else{
        printf("nano is not in the %s\n", word);
    }
    return 0;
}
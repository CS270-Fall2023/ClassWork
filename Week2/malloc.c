#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arr = malloc(sizeof(int)*50);
    for (int i = 0; i<50; i++){
        printf("%d ", arr[i]);
    }
    printf("\nUsing calloc\n");
    int *arr2 = calloc(50, sizeof(int)*50);
    for (int i = 0; i<50; i++){
        printf("%d ", arr2[i]);
    }
    return 0;
}
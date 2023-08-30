#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    printf("This program was called with %d arguments\n", argc);

    for (i = 0; i < argc; ++i)
        printf("%s\n", argv[i]);

    return 0;
}


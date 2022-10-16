#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
    if(argc != 2){
        fprintf(stderr, "Usage: %s num\n", argv[0]);
        return 1;
    }

    printf("  .globl _main\n");
    printf("  .p2align	2\n");
    printf("_main:\n");
    printf("  mov w0, #%d\n", atoi(argv[1]));
    printf("  ret\n");
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
    if(argc != 2){
        fprintf(stderr, "Usage: %s num\n", argv[0]);
        return 1;
    }

    char *p = argv[1];

    printf("  .globl _main\n");
    printf("  .p2align	2\n");
    printf("_main:\n");
    printf("  mov w0, %ld\n", strtol(p, &p, 10));

    while (*p) {
        if (*p == '+') {
            p++;
            printf("  add w0, w0, %ld\n", strtol(p, &p, 10));
            continue;
        }

        if (*p == '-') {
            p++;
            printf("  sub w0, w0, %ld\n", strtol(p, &p, 10));
            continue;
        }

        fprintf(stderr, "unexpected character: '%c'\n", *p);
        return 1;
    }

    printf("  ret\n");
    return 0;
}
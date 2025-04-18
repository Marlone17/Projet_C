#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>


int open(char *path, int *flags){
    printf("test de vick");
    return 0; 
}

//Pour compiler : gcc -shared -fPIC -o first_hook_test.so first_hook_test.c -ldl
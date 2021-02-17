#include "upo_sort.h"

/** FUNCTIONS
 * 
 * Implemented by https://github.com/LukeAz/
 */

int int_cmp(void *a, void *b) {
    int *aa=a, *bb=b;
    return (*aa > *bb) - (*bb > *aa);
}

int float_cmp(void *a, void *b) {
    float *aa=a, *bb=b;
    return (*aa > *bb) - (*bb > *aa);
}

int string_cmp(void *a, void *b) {
    char **aa = (char**) a;
    char **bb = (char**) b;
    return strcmp(*aa,*bb);
}

void swap_el(void *a, void *b, size_t size) {
    unsigned char *aa=a, *bb=b, temp;
    for(size_t i=0; i<size;i++) {
        temp = aa[i];
        aa[i] = bb[i];
        bb[i] = temp;
    }
}

void print_array_int(int v[], int dim) {
    for(int i=0; i < dim; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void print_array_float(float v[], int dim) {
    for(int i=0; i < dim; i++) {
        printf("%f ", v[i]);
    }
    printf("\n");
}

void print_array_string(char *s[], int dim) {
    for(int i=0; i < dim; i++) {
        printf("%s ", s[i]);
    }
    printf("\n");
}

/** Sorting Functions
 * 
 * Implemented by https://github.com/LukeAz/
 */

void upo_bubble_sort(void *base, size_t n, size_t size, int (*cmp)(void*, void*)) {
    unsigned char *base_ptr = base;
    int repeat=1;

    while(repeat) {
        repeat=0;
        for(size_t i = 0; i < n-1; i++) {
            if(cmp(base_ptr + i*size, base_ptr + (i+1)*size) > 0) {
                swap_el(base_ptr + i*size, base_ptr + (i+1)*size, size);
                repeat=1;
            }
        }
    }
}
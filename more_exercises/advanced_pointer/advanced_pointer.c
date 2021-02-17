#include "advanced_pointer.h"

/** FUNCTIONS
 * 
 * Implemented by https://github.com/LukeAz/
 */


void upo_hex_fprint_char(FILE *stream, const void *p, size_t n) {
    for(size_t i=0; i<n; i++) {
        fprintf(stream, "0x%lX\t", *(char *)p + i);
    }
}

void upo_hex_fprint_int(FILE *stream, const void *p, size_t n) {
    for(size_t i=0; i<n; i++) {
        fprintf(stream, "0x%lX\t", *(int *)p + i);
    }
}

void upo_mem_set(void *p, unsigned char c, size_t n) {
    unsigned char *p_ptr = p;
    for(size_t i=0; i<n; i++) 
       p_ptr[i] = c;
}

int upo_mem_cmp(const void *p1, const void *p2, size_t n) {
    const unsigned char *p1_ptr = p1;
    const unsigned char *p2_ptr = p2;
    int cmp=0;

    for(size_t i=0; i<n && cmp == 0; i++) {
        if(p1_ptr[i] > p2_ptr[i])
            cmp = 1;
        else if (p1_ptr[i] < p2_ptr[i])
            cmp = -1;
    }
    return cmp;
}

int upo_all_of(const void *base, size_t n, size_t sz, int (*pred)(const void *)) {
    const unsigned char *base_ptr = base;
    int res = 1;

    for(size_t i=0; i<n && res == 1; i++) {
        res = pred(base_ptr + i *sz);
    }
    return res;
}

int is_even(const void *el) {
    if(*(const int *)el %2 == 0) 
        return 1;
    return 0;
}

int is_odd(const void *el) {
    if(*(const int *)el %2 == 1) 
        return 1;
    return 0;
}
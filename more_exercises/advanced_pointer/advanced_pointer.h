#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** FUNCTIONS PROTOTYPES
 * 
 * Implemented by https://github.com/LukeAz/
 */

void upo_hex_fprint_char(FILE *stream, const void *p, size_t n);
void upo_hex_fprint_int(FILE *stream, const void *p, size_t n);
void upo_mem_set(void *p, unsigned char c, size_t n);
int upo_mem_cmp(const void *p1, const void *p2, size_t n);
int upo_all_of(const void *base, size_t n, size_t sz, int (*pred)(const void *));
int is_even(const void *el);
int is_odd(const void *el);
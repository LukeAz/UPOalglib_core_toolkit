#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** HEADER
 * 
 * Implemented by https://github.com/LukeAz/
 */

void upo_bubble_sort(void *base, size_t n, size_t size, int (*cmp)(void*, void*));

/** Comparison functions
 * 
 * Implemented by https://github.com/LukeAz/
 */
int int_cmp(void *a, void *b);
int float_cmp(void *a, void *b);
int string_cmp(void *a, void *b);

/** Utilities functions
 * 
 * Implemented by https://github.com/LukeAz/
 */
void swap_el(void *a, void *b, size_t size);
void print_array_int(int v[], int dim);
void print_array_float(float v[], int dim);
void print_array_string(char *s[], int dim);
/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

/*
 * Copyright 2015 University of Piemonte Orientale, Computer Science Institute
 *
 * This file is part of UPOalglib.
 *
 * UPOalglib is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * UPOalglib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with UPOalglib.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <assert.h>
#include "sort_private.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void upo_insertion_sort(void *base, size_t n, size_t size, upo_sort_comparator_t cmp)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    size_t i,j;
    unsigned char *basePtr = base, *a=NULL,*b=NULL;

    for(i=1; i < n; ++i) {
        j=i;
        while(j>0 && cmp(basePtr + j * size, basePtr + (j * size) - (1*size)) < 0) {
            a = basePtr + j * size;
            b = basePtr + (j * size) - (1*size);

            upoSwap(a, b, size);
            j = j-1;
        }
    }
}

void upo_merge_sort(void *base, size_t n, size_t size, upo_sort_comparator_t cmp)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    upo_merge_sort_rec(base, 0, n-1, size, cmp);
}

void upo_merge_sort_rec(void *base, size_t low, size_t high, size_t size, upo_sort_comparator_t cmp) 
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    size_t mid;
    if (low>=high)
        return;
    mid = (low + high) / 2;
    
    upo_merge_sort_rec(base, low, mid, size, cmp);
    upo_merge_sort_rec(base, mid + 1, high, size, cmp);
    upo_merge(base, low, mid, high, size, cmp);
}

void upo_merge(void *base, size_t low, size_t mid, size_t high, size_t size, upo_sort_comparator_t cmp) 
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    unsigned char *base_ptr = base, *new_base = malloc(size * (high - low + 1));
    size_t i = 0, j = mid + 1 - low, k;
    
    for(i = low; i <= high; ++i) {
        upoCopy(new_base + (i - low) * size, base_ptr + i * size, size);
    }

    i = 0;
    for(k = low; k <= high; ++k) {
        if(i > (mid - low)) {
            upoCopy(base_ptr + k * size, new_base + j * size, size);
            j++;
        } else if(j > (high - low)) {
            upoCopy(base_ptr + k * size, new_base + i  * size, size);
            i++;
        } else if(cmp(new_base + j * size, new_base + i * size) <= -1) {
            upoCopy(base_ptr + k * size, new_base + j * size, size);
            j++;
        } else {
            upoCopy(base_ptr + k * size, new_base + i * size, size);
            i++;
        }
    }

    free(new_base);
}

void upo_quick_sort(void *base, size_t n, size_t size, upo_sort_comparator_t cmp)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    upo_quick_sort_rec(base, 0, n-1, size, cmp);
}

void upo_quick_sort_rec(void *base, size_t low, size_t high, size_t size, upo_sort_comparator_t cmp) 
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    size_t j;
    if(low >= high) 
        return;
    
    j = upo_quick_sort_partition(base, low, high, size, cmp);
    if(j>0)
        upo_quick_sort_rec(base, low, j-1, size, cmp);
    upo_quick_sort_rec(base, j + 1, high, size, cmp);
}

size_t upo_quick_sort_partition(void *base, size_t low, size_t high, size_t size, upo_sort_comparator_t cmp) 
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    
    size_t p = low, i = low, j = high;
    unsigned char *basePtr = base;
    
    while(i < j) {
        while((i < high) && (cmp(basePtr + i * size, basePtr + p * size) <= -1)) i++;
        while((j > low) && (cmp(basePtr + j * size, basePtr + p * size) >= 1)) j--; 
        upoSwap(basePtr + i * size, basePtr + j * size, size);
    }
    upoSwap(basePtr + p * size, basePtr + j * size, size);
    return j;
}

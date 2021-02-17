/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void *binary_search(const void *key, const void *base, size_t num_elem, size_t elem_size, int (*compar)(const void *, const void *));

static int int_cmp(const void *key, const void *elem);

static int str_cmp(const void *key, const void *elem);


int main()
{
    int iary[] = {1, 20, 25, 32, 76, 123};
    int ikey = 76;
    int inokey = 77;
    int *ires = NULL;
    int *ires_check = NULL;
    char *sary[] = {"e01","e02","e03","e04","e05","e06"};
    //char *skey = "e01";
    char *skey = "e01";
    char *snokey = "e07";
    char **sres = NULL;
    char **sres_check = NULL;

    // Case: integer array - key found
    ires = binary_search(&ikey, iary, sizeof iary/sizeof iary[0], sizeof iary[0], int_cmp);
    ires_check = bsearch(&ikey, iary, sizeof iary/sizeof iary[0], sizeof iary[0], int_cmp);
    assert( ires == ires_check );
    if (ires != NULL)
    {
        printf("Key %d -> found (element: %d)\n", ikey, *ires); 
    }
    else
    {
        printf("Key %d -> not found\n", ikey); 
    }

    // Case: integer array - key not found
    ires = binary_search(&inokey, iary, sizeof iary/sizeof iary[0], sizeof iary[0], int_cmp);
    ires_check = bsearch(&inokey, iary, sizeof iary/sizeof iary[0], sizeof iary[0], int_cmp);
    assert( ires == ires_check );
    if (ires != NULL)
    {
        printf("Key %d -> found (element: %d)\n", inokey, *ires); 
    }
    else
    {
        printf("Key %d -> not found\n", inokey); 
    }

    // Case: string array - key found
    sres = binary_search(&skey, sary, sizeof sary/sizeof sary[0], sizeof sary[0], str_cmp);
    sres_check = bsearch(&skey, sary, sizeof sary/sizeof sary[0], sizeof sary[0], str_cmp);
    assert( sres == sres_check );
    if (sres != NULL)
    {
        printf("Key '%s' -> found (element: '%s')\n", skey, *sres); 
    }
    else
    {
        printf("Key '%s' -> not found\n", skey); 
    }

    // Case: string array - key not found
    sres = binary_search(&snokey, sary, sizeof sary/sizeof sary[0], sizeof sary[0], str_cmp);
    sres_check = bsearch(&snokey, sary, sizeof sary/sizeof sary[0], sizeof sary[0], str_cmp);
    assert( sres == sres_check );
    if (sres != NULL)
    {
        printf("Key '%s' -> found (element: '%s')\n", snokey, *sres); 
    }
    else
    {
        printf("Key '%s' -> not found\n", snokey); 
    }

    return 0;
}

void *binary_search(const void *key, const void *base, size_t num_elem, size_t elem_size, int (*compar)(const void *, const void *))
{
    assert( key != NULL );
    assert( base != NULL );
    assert( compar != NULL );

    if (num_elem <=0)
        return NULL;

    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    const unsigned char *base_ptr = base;
    size_t low=0, high=num_elem-1, mid;
    int comp;
    void* result=NULL;

    while(low <= high) {
        mid=(low+high)/2;
        comp=compar(key, base_ptr + mid*elem_size);
        if(comp == 0) {
            result= (void *) (base_ptr + mid*elem_size);
            break;
        } 
        else if(comp < 0) 
            high = mid-1;
        else if(comp > 0)
            low = mid+1;
        
        if(mid==0)
            break;
    }
    return result;

}

int int_cmp(const void *pkey, const void *pelem)
{
    const int *pk = pkey;
    const int *pe = pelem;

    assert( pk != NULL );
    assert( pe != NULL );

    return (*pk > *pe) ? 1 : ((*pk < *pe) ? -1 : 0);
}

int str_cmp(const void *pkey, const void *pelem)
{
    const char **pk = (const char**) pkey;
    const char **pe = (const char**) pelem;

    assert( pk != NULL );
    assert( pe != NULL );

    //fprintf(stderr, "key: '%s', candidate: '%s' -> cmp: %d\n", *pk, *pe, strcmp(*pk, *pe));

    return strcmp(*pk, *pe);
}


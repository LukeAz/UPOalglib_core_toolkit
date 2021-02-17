#include "advanced_pointer.h"

/** MAIN
 * 
 * Implemented by https://github.com/LukeAz/
 */

int main() {
    char s[] = "exercise";
    int hex_sample[] = {255,144,15,1,1};
    int num_cmp_1 = 33, num_cmp_2 = 50, cmp;
    int all_of[] = {1,5,77,81};

    printf("EXERCISE 1: upo_hex_fprint\n");
    printf("String: '%s':\n",s);
    upo_hex_fprint_char(stdout, s, strlen(s));
    printf("\nInteger array: '{255,144,15,1,1}':\n");
    upo_hex_fprint_int(stdout, hex_sample, sizeof(hex_sample));

    printf("\n\nEXERCISE 2: upo_mem_set\n");
    printf("Original string: %s\n", s);
    upo_mem_set(s, '-', strlen(s));
    printf("Modified string: %s\n", s);

    printf("\nEXERCISE 3: upo_mem_cmp\n");
    cmp = upo_mem_cmp(&num_cmp_1, &num_cmp_2, sizeof(int));
    printf("%d > %d ? %d\n", num_cmp_1, num_cmp_2, cmp);
    cmp = upo_mem_cmp(&num_cmp_2, &num_cmp_1, sizeof(int));
    printf("%d > %d ? %d\n", num_cmp_2, num_cmp_1, cmp);
    cmp = upo_mem_cmp(&num_cmp_1, &num_cmp_1, sizeof(int));
    printf("%d > %d ? %d\n", num_cmp_1, num_cmp_1, cmp);

    printf("\nEXERCISE 4: upo_all_of\n");
    printf("Integer array: {1,5,77,81}\n");
    if(upo_all_of(all_of, sizeof(all_of)/sizeof(all_of[0]), sizeof(all_of[0]), is_even) == 1)
        printf("The numbers are all even\n");
    else
        printf("The numbers are not all even\n");
    
    if(upo_all_of(all_of, sizeof(all_of)/sizeof(all_of[0]), sizeof(all_of[0]), is_odd) == 1)
        printf("The numbers are all odd\n");
    else
        printf("The numbers are not all odd\n");
}
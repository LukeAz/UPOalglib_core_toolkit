#include "upo_sort.h"

/** MAIN
 * 
 * Implemented by https://github.com/LukeAz/
 */

int main() {
    int int_numbers[] = {12,1,0,17,21,-4,8,5};
    int int_numbers2[] = {12,1,0,17,21,-4,8,5,3,2,53,23,123,12,44,21,345,75,32,55,32,554,232,23};
    float float_numbers[] = {1.32,0.2,-4,21,6.34,15.21,4.32};
    char *string_vector[] = {"this", "is", "a", "preparation", "exercise"};

    printf("[1] Testing bubble sort:\n");
    printf("[1-1] Original int array:\n");
    print_array_int(int_numbers, sizeof(int_numbers)/sizeof(int_numbers[0]));
    upo_bubble_sort(int_numbers, sizeof(int_numbers)/sizeof(int_numbers[0]), sizeof(int_numbers[0]), int_cmp);
    printf("[1-2] Sorted int array:\n");
    print_array_int(int_numbers, sizeof(int_numbers)/sizeof(int_numbers[0]));
    printf("\n");

    printf("[1-3] Original float array:\n");
    print_array_float(float_numbers, sizeof(float_numbers)/sizeof(float_numbers[0]));
    upo_bubble_sort(float_numbers, sizeof(float_numbers)/sizeof(float_numbers[0]), sizeof(float_numbers[0]), float_cmp);
    printf("[1-4] Sorted float array:\n");
    print_array_float(float_numbers, sizeof(float_numbers)/sizeof(float_numbers[0]));
    printf("\n");

    printf("[1-5] Original string array:\n");
    print_array_string(string_vector, sizeof(string_vector)/sizeof(string_vector[0]));
    upo_bubble_sort(string_vector, sizeof(string_vector)/sizeof(string_vector[0]), sizeof(string_vector[0]), string_cmp);
    printf("[1-6] Sorted string array:\n");
    print_array_string(string_vector, sizeof(string_vector)/sizeof(string_vector[0]));
    printf("\n");

    printf("[2] Testing O(n log n) quicksort:\n");
    printf("Work in progres...\n");
}
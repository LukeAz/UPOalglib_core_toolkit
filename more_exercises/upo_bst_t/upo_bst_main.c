#include "upo_bst.h"

/** MAIN
 * 
 * Implemented by https://github.com/LukeAz/
 */

int main() {
    upo_bst_t bst;
    upo_bst_key_list_t node_list;
    size_t rank, depth=-1;
    int keys[] = {8,3,1,6,10,14,4,7,13};
    int n = sizeof(keys)/sizeof(keys[0]);
    int value = 34, value2=-2, predecessor;

    printf("[0] Testing upo_bst_create:\n");
    bst = upo_bst_create(int_compare);
    assert(bst != NULL);
    printf("[OK] Test success..\n\n");
    
    printf("[1] Testing upo_bst_insert:\n");
    for(size_t i=0; i<n;i++)
        upo_bst_insert(bst, &keys[i], &value);
    assert(upo_bst_size(bst) == n);
    printf("[OK] Test success..\n\n");

    printf("[2] Testing upo_bst_rank:\n");
    rank = upo_bst_rank(bst, &keys[0]);
    assert(rank==5);
    printf("[2-1] Rank of 8 is: %lu\n", rank);
    rank = upo_bst_rank(bst, &keys[2]);
    assert(rank==0);
    printf("[2-2] Rank of 1 is: %lu\n", rank);
    rank = upo_bst_rank(bst, &keys[8]);
    printf("[2-3] Rank of 13 is: %lu\n", rank);
    assert(rank==7);
    printf("[OK] Test success..\n\n");
    
    printf("[3] Testing upo_bst_predecessor:\n");
    predecessor= *(int *) upo_bst_predecessor(bst, &keys[0]);
    assert(predecessor==7);
    printf("[3-1] predecessor of 8 is: %d\n", predecessor);
    predecessor= *(int *) upo_bst_predecessor(bst, &keys[1]);
    assert(predecessor==1);
    printf("[3-2] predecessor of 3 is: %d\n", predecessor);
    assert(upo_bst_predecessor(bst, &value)==NULL);
    printf("[3-3] predecessor of 34 is: NULL\n");
    printf("[OK] Test success..\n\n");

    printf("[4] Testing upo_bst_get_value_depth:\n");
    assert(*(int*)upo_bst_get_value_depth(bst, &keys[0] , &depth)==8);
    assert(depth==0);
    assert(*(int*)upo_bst_get_value_depth(bst, &keys[2] , &depth)==1);
    assert(depth==2);
    assert(*(int*)upo_bst_get_value_depth(bst, &keys[8] , &depth)==13);
    assert(depth==3);
    assert(upo_bst_get_value_depth(bst, &value , &depth)==NULL);
    assert(depth==-1);
    printf("[OK] Test success..\n\n");

    printf("[5] Testing upo_bst_keys_le:\n");
    node_list = upo_bst_keys_le(bst, &keys[0]);
    assert(node_list!=NULL);
    while(node_list!=NULL) {
        printf("%d -> ", *(int*) node_list->key);
        node_list = node_list->next;
    }
    printf("NULL\n");
    node_list = upo_bst_keys_le(bst, &value);
    assert(node_list!=NULL);
    while(node_list!=NULL) {
        printf("%d -> ", *(int*) node_list->key);
        node_list = node_list->next;
    }
    printf("NULL\n");
    node_list = upo_bst_keys_le(bst, &keys[1]);
    assert(node_list!=NULL);
    while(node_list!=NULL) {
        printf("%d -> ", *(int*) node_list->key);
        node_list = node_list->next;
    }
    printf("NULL\n");
    node_list = upo_bst_keys_le(bst, &value2);
    assert(node_list==NULL);
    printf("[OK] Test success..\n\n");

    printf("[6] Testing upo_bst_delete:\n");
    for (size_t i=0; i<n; i++)
        upo_bst_delete(bst, &keys[i], 0);
    assert(upo_bst_size(bst) == 0);
    assert(upo_bst_is_empty(bst) == 1);
    printf("[OK] Test Success!\n\n");

    printf("[7] Testing upo_bst_destroy:\n");
    upo_bst_destroy(bst, 0);
    printf("[OK] Test Success!\n");
}
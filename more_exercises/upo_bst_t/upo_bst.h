#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/** HEADER
 * 
 * Implemented by https://github.com/LukeAz/
 */

typedef int (*upo_bst_comparator_t)(const void*, const void*);

typedef struct upo_bst_node_s upo_bst_node_t;

struct upo_bst_node_s
{
    void *key; 
    void *value; 
    upo_bst_node_t *left; 
    upo_bst_node_t *right;
};

struct upo_bst_s
{
    upo_bst_node_t *root;
    upo_bst_comparator_t key_cmp;
};

typedef struct upo_bst_s* upo_bst_t;

struct upo_bst_key_list_node_s
{
    const void *key; 
    struct upo_bst_key_list_node_s *next; 
};
typedef struct upo_bst_key_list_node_s upo_bst_key_list_node_t;
typedef upo_bst_key_list_node_t* upo_bst_key_list_t;

/** BASIC BST METHODS
 * 
 * Implemented by https://github.com/LukeAz/
 */
upo_bst_t upo_bst_create(upo_bst_comparator_t key_cmp);
void upo_bst_clear(upo_bst_t tree, int destroy_data);
void upo_bst_destroy(upo_bst_t tree, int destroy_data);
void upo_bst_clear_impl(upo_bst_node_t *node, int destroy_data);
void upo_bst_insert(upo_bst_t tree, void *key, void *value);
void* upo_bst_get(const upo_bst_t tree, const void *key);
void upo_bst_delete(upo_bst_t tree, const void *key, int destroy_data);
size_t upo_bst_size(const upo_bst_t tree);
int upo_bst_is_empty(const upo_bst_t tree);

/** BASIC BST IMPLEMENTATION
 * 
 * Implemented by https://github.com/LukeAz/
 */
upo_bst_node_t* newNode(void *key, void *value);
void* upo_bst_insert_impl(upo_bst_node_t *node, void *key, void *value, upo_bst_comparator_t cmp);
void* upo_bst_get_impl(upo_bst_node_t *node, const void *key, upo_bst_comparator_t cmp);
void* upo_bst_delete_impl(upo_bst_node_t *node, const void *key, int destroy_data, upo_bst_comparator_t cmp);
void* upo_bst_delete_impl_1(upo_bst_node_t *node, int destroy_data);
void* upo_bst_delete_impl_2(upo_bst_node_t *node, int destroy_data, upo_bst_comparator_t cmp);
void* upo_bst_max_impl(upo_bst_node_t *node);
size_t upo_bst_size_impl(upo_bst_node_t *node);
int upo_bst_is_leaf_impl(upo_bst_node_t *node);
int int_compare(const void *a, const void *b);

/** MORE EXERCISE
 * 
 * Implemented by https://github.com/LukeAz/
 */
size_t upo_bst_rank(const upo_bst_t tree, const void *key);
void* upo_bst_predecessor(const upo_bst_t tree, const void *key);
void* upo_bst_get_impl_depth(upo_bst_node_t *node, const void *key, size_t *depth, upo_bst_comparator_t cmp);
void* upo_bst_get_value_depth(const upo_bst_t tree, const void *key, size_t *depth);
upo_bst_key_list_t upo_bst_keys_le(const upo_bst_t tree, const void *key);
#include "upo_bst.h"

/** BASIC BST METHODS
 * 
 * Implemented by https://github.com/LukeAz/
 */

upo_bst_t upo_bst_create(upo_bst_comparator_t key_cmp) {
    upo_bst_t tree = malloc(sizeof(struct upo_bst_s));
    if (tree == NULL) {
        perror("Unable to create a binary search tree");
        abort();
    }
    tree->root = NULL;
    tree->key_cmp = key_cmp;
    return tree;
}

void upo_bst_clear(upo_bst_t tree, int destroy_data) {
    if (tree != NULL) {
        upo_bst_clear_impl(tree->root, destroy_data);
        tree->root = NULL;
    }
}

void upo_bst_destroy(upo_bst_t tree, int destroy_data) {
    if (tree != NULL) {
        upo_bst_clear(tree, destroy_data);
        free(tree);
    }
}

void upo_bst_clear_impl(upo_bst_node_t *node, int destroy_data)
{
    if (node != NULL) {
        upo_bst_clear_impl(node->left, destroy_data);
        upo_bst_clear_impl(node->right, destroy_data);

        if (destroy_data) {
            free(node->key);
            free(node->value);
        }

        free(node);
    }
}

void upo_bst_insert(upo_bst_t tree, void *key, void *value)
{
    tree->root = upo_bst_insert_impl(tree->root, key, value, tree->key_cmp);
}

void* upo_bst_get(const upo_bst_t tree, const void *key)
{
    upo_bst_node_t *node = (upo_bst_node_t *) upo_bst_get_impl(tree->root, key, tree->key_cmp);
    if (node!=NULL) 
        return node->value;
    return NULL;
}

void upo_bst_delete(upo_bst_t tree, const void *key, int destroy_data)
{
    tree->root = upo_bst_delete_impl(tree->root, key, destroy_data, tree->key_cmp);
}

size_t upo_bst_size(const upo_bst_t tree)
{
    if(tree==NULL) 
        return 0;
    return upo_bst_size_impl(tree->root);
}

int upo_bst_is_empty(const upo_bst_t tree)
{
    if (tree == NULL || tree->root == NULL) 
        return 1;
    return 0;
}

int int_compare(const void *a, const void *b) {
    const int *aa = a;
    const int *bb = b;
    return (*aa > *bb) - (*aa < *bb);
}

/** BASIC BST IMPLEMENTATION
 * 
 * Implemented by https://github.com/LukeAz/
 */

upo_bst_node_t* newNode(void *key, void *value) {
    upo_bst_node_t *node = malloc(sizeof(upo_bst_node_t));
    node -> value = value;
    node -> key = key;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

void* upo_bst_insert_impl(upo_bst_node_t *node, void *key, void *value, upo_bst_comparator_t cmp) {
    if(node == NULL) {
        node = newNode(key, value);
    } else if (cmp(key,node->key) < 0) 
        node->left = upo_bst_insert_impl(node->left, key, value, cmp);
    else if (cmp(key,node->key) > 0) 
        node->right = upo_bst_insert_impl(node->right, key, value, cmp);
    return node;
}

void* upo_bst_get_impl(upo_bst_node_t *node, const void *key, upo_bst_comparator_t cmp) {
    if (node == NULL) return NULL;
    if (cmp(key,node->key) < 0)
        return upo_bst_get_impl(node->left, key, cmp);
    else if (cmp(key,node->key) > 0) 
        return upo_bst_get_impl(node->right, key, cmp);
    else 
        return node;
}

void* upo_bst_delete_impl(upo_bst_node_t *node, const void *key, int destroy_data, upo_bst_comparator_t cmp) {
    if (node == NULL) return NULL;
    if(cmp(key,node->key) < 0) 
        node->left = upo_bst_delete_impl(node->left, key, destroy_data, cmp);
    else if(cmp(key,node->key) > 0)
        node->right = upo_bst_delete_impl(node->right, key, destroy_data, cmp);
    else if (node->left != NULL && node->right != NULL)
        node = upo_bst_delete_impl_2(node, destroy_data, cmp);
    else 
        node = upo_bst_delete_impl_1(node, destroy_data);

    return node;
}

void* upo_bst_delete_impl_1(upo_bst_node_t *node, int destroy_data) {
    upo_bst_node_t *x = node;
    if (node->left != NULL)
        node = node->left;
    else 
        node = node->right;

    if(destroy_data == 1) free(x);

    return node;
}

void* upo_bst_delete_impl_2(upo_bst_node_t *node, int destroy_data, upo_bst_comparator_t cmp) {
    upo_bst_node_t *max = upo_bst_max_impl(node->left);
    node->key = max->key;
    node->value = max->value;
    node->left = upo_bst_delete_impl(node->left, max->key, destroy_data, cmp);
    return node;
}

size_t upo_bst_size_impl(upo_bst_node_t *node) {
    if (node == NULL) return 0;
    return 1 + upo_bst_size_impl(node->left) + upo_bst_size_impl(node->right);
}

void* upo_bst_max_impl(upo_bst_node_t *node) {
    if (node == NULL) return NULL;

    if(node != NULL && node->right != NULL)
        return upo_bst_max_impl(node->right);
    else 
        return node;
}

int upo_bst_is_leaf_impl(upo_bst_node_t *node) {
    if (node->left == NULL && node->right == NULL) return 1;
    return 0;
}

/** Exercise 8 MORE EXERCISE
 * 
 * Implemented by https://github.com/LukeAz/
 */
size_t upo_bst_rank_impl(const upo_bst_node_t *node, const void *key, upo_bst_comparator_t key_cmp) {
    if(node == NULL) return 0;

    size_t rank = 0;

    if(key_cmp(node->key, key)<0) 
        rank += 1+ upo_bst_rank_impl(node->right, key, key_cmp);
    rank += upo_bst_rank_impl(node->left, key, key_cmp);

    return rank;
}

size_t upo_bst_rank(const upo_bst_t tree, const void *key) {
    if(tree==NULL) return 0;
    return upo_bst_rank_impl(tree->root, key, tree->key_cmp);
}

/** Exercise 9 MORE EXERCISE
 * 
 * Implemented by https://github.com/LukeAz/
 */
void* upo_bst_predecessor(const upo_bst_t tree, const void *key) {
    if(tree==NULL) return NULL;
    upo_bst_node_t *node = upo_bst_get_impl(tree->root, key, tree->key_cmp);
    if (node!=NULL) {
        node = upo_bst_max_impl(node->left);
        return node->key;
    }
    return NULL;
}

/** Exercise 10 MORE EXERCISE
 * 
 * Implemented by https://github.com/LukeAz/
 */
void* upo_bst_get_impl_depth(upo_bst_node_t *node, const void *key, size_t *depth, upo_bst_comparator_t cmp) {
    if (node == NULL) return NULL;
    
    if (cmp(key,node->key) < 0) {
        *depth = *depth +1;
        return upo_bst_get_impl_depth(node->left, key, depth, cmp);
    }
    else if (cmp(key,node->key) > 0) {
        *depth = *depth +1;
        return upo_bst_get_impl_depth(node->right, key, depth, cmp); 
    }
    else 
        return node;
}

void* upo_bst_get_value_depth(const upo_bst_t tree, const void *key, size_t *depth) {
    if(tree!=NULL) {
        *depth=0;
        upo_bst_node_t *node =  upo_bst_get_impl_depth(tree->root, key, depth, tree->key_cmp);
        if(node!=NULL) {
            return node -> key;
        }
    }
    *depth = -1;
    return NULL;
}

/** Exercise 11 MORE EXERCISE
 * 
 * Implemented by https://github.com/LukeAz/
 */
upo_bst_key_list_t upo_bst_keys_le_impl(upo_bst_node_t *node, const void *key, upo_bst_comparator_t cmp) {
    if(node==NULL) return NULL; 

    upo_bst_key_list_t list_node_left=NULL, list_node_right=NULL;

    if(cmp(key, node->key) >= 0) {
        list_node_left = malloc(sizeof(struct upo_bst_key_list_node_s));
        list_node_left -> key = node->key;
        list_node_right = upo_bst_keys_le_impl(node->right, key, cmp);
        if(list_node_right!=NULL) {
            list_node_left->next = list_node_right;
            while(list_node_right -> next != NULL) {
                list_node_right = list_node_right->next;
            }
            list_node_right->next = upo_bst_keys_le_impl(node->left, key, cmp);
        } else 
            list_node_left->next = upo_bst_keys_le_impl(node->left, key, cmp);
    } else {
        return upo_bst_keys_le_impl(node->left, key, cmp);
    }

    return list_node_left;
}

upo_bst_key_list_t upo_bst_keys_le(const upo_bst_t tree, const void *key) {
    if(tree==NULL) return NULL;

    return upo_bst_keys_le_impl(tree->root, key, tree->key_cmp);
}
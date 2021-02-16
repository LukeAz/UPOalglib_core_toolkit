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

#include "bst_private.h"
#include <stdio.h>
#include <stdlib.h>


/**** EXERCISE #1 - BEGIN of FUNDAMENTAL OPERATIONS ****/


upo_bst_t upo_bst_create(upo_bst_comparator_t key_cmp)
{
    upo_bst_t tree = malloc(sizeof(struct upo_bst_s));
    if (tree == NULL)
    {
        perror("Unable to create a binary search tree");
        abort();
    }

    tree->root = NULL;
    tree->key_cmp = key_cmp;

    return tree;
}

void upo_bst_destroy(upo_bst_t tree, int destroy_data)
{
    if (tree != NULL)
    {
        upo_bst_clear(tree, destroy_data);
        free(tree);
    }
}

void upo_bst_clear_impl(upo_bst_node_t *node, int destroy_data)
{
    if (node != NULL)
    {
        upo_bst_clear_impl(node->left, destroy_data);
        upo_bst_clear_impl(node->right, destroy_data);

        if (destroy_data)
        {
            free(node->key);
            free(node->value);
        }

        free(node);
    }
}

void upo_bst_clear(upo_bst_t tree, int destroy_data)
{
    if (tree != NULL)
    {
        upo_bst_clear_impl(tree->root, destroy_data);
        tree->root = NULL;
    }
}

void* upo_bst_put(upo_bst_t tree, void *key, void *value)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    void  *v_old = NULL;
    if(tree != NULL) 
        tree->root = upo_bst_put_impl(tree->root, key, value, v_old, tree->key_cmp);
    return v_old;
}

void* upo_bst_put_impl(upo_bst_node_t *node, void *key, void *value, void *v_old, upo_bst_comparator_t cmp) 
{
    /* TO STUDENTS:
     *  Implemented by https://github.com/LukeAz
    */
    v_old = NULL;
    if(node == NULL)
        node = newNode(key, value);
    else if (cmp(key,node->key) < 0) 
        node->left = upo_bst_put_impl(node->left, key, value, v_old, cmp);
    else if (cmp(key,node->key) > 0) 
        node->right = upo_bst_put_impl(node->right, key, value, v_old, cmp);
    else {
        v_old = node->value;
        node->value = value;
    }
    return node;
}

void upo_bst_insert(upo_bst_t tree, void *key, void *value)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    if(tree!=NULL)
        tree->root = upo_bst_insert_impl(tree->root, key, value, tree->key_cmp);
}

void* upo_bst_insert_impl(upo_bst_node_t *node, void *key, void *value, upo_bst_comparator_t cmp) 
{
    /* TO STUDENTS:
     *  Implemented by https://github.com/LukeAz
    */
    if(node == NULL)
        node = newNode(key, value);
    else if (cmp(key,node->key) < 0) 
        node->left = upo_bst_insert_impl(node->left, key, value, cmp);
    else if (cmp(key,node->key) > 0) 
        node->right = upo_bst_insert_impl(node->right, key, value, cmp);
    return node;
}

void* upo_bst_get(const upo_bst_t tree, const void *key)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    upo_bst_node_t *node=NULL;
    if(tree!=NULL) {
        node = (upo_bst_node_t *) upo_bst_get_impl(tree->root, key, tree->key_cmp);
        if(node!=NULL)
            return node->value;
    }
    return NULL;
}

void* upo_bst_get_impl(upo_bst_node_t *node, const void *key, upo_bst_comparator_t cmp) {
    /* TO STUDENTS:
     *  Implemented by https://github.com/LukeAz
    */
    if (node == NULL) 
        return NULL;
    
    if (cmp(key,node->key) < 0)
        return upo_bst_get_impl(node->left, key, cmp);
    else if (cmp(key,node->key) > 0) 
        return upo_bst_get_impl(node->right, key, cmp);
    else 
        return node;
}

int upo_bst_contains(const upo_bst_t tree, const void *key)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    if(tree!=NULL)
        if(upo_bst_get_impl(tree->root, key, tree->key_cmp) != NULL)
            return 1;
    return 0;
}

void upo_bst_delete(upo_bst_t tree, const void *key, int destroy_data)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    if(tree!=NULL) {
        tree->root = upo_bst_delete_impl(tree->root, key, destroy_data, tree->key_cmp);
    }
}

void* upo_bst_delete_impl(upo_bst_node_t *node, const void *key, int destroy_data, upo_bst_comparator_t cmp) {
    /* TO STUDENTS:
     *  Implemented by https://github.com/LukeAz
    */
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
    /* TO STUDENTS:
     *  Implemented by https://github.com/LukeAz
    */
    if(node==NULL) return NULL;
    
    upo_bst_node_t *x = node;
    
    if (node->left != NULL)
        node = node->left;
    else 
        node = node->right;

    if(destroy_data == 1) free(x);

    return node;
}

void* upo_bst_delete_impl_2(upo_bst_node_t *node, int destroy_data, upo_bst_comparator_t cmp) {
    /* TO STUDENTS:
     *  Implemented by https://github.com/LukeAz
    */
    if(node==NULL) return NULL;
    
    upo_bst_node_t *max = upo_bst_max_impl(node->left);
    node->key = max->key;
    node->value = max->value;
    node->left = upo_bst_delete_impl(node->left, max->key, destroy_data, cmp);
    return node;
}

size_t upo_bst_size(const upo_bst_t tree)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    if(tree==NULL) 
        return 0;
    return upo_bst_size_impl(tree->root);
}

size_t upo_bst_size_impl(upo_bst_node_t *node) {
    /* TO STUDENTS:
     *  Implemented by https://github.com/LukeAz
    */
    if(node == NULL) 
        return 0;
    return 1 + upo_bst_size_impl(node->left) + upo_bst_size_impl(node->right);
}

size_t upo_bst_height(const upo_bst_t tree)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    if(tree!=NULL) 
        return upo_bst_height_impl(tree->root);
    return 0;
}

size_t upo_bst_height_impl(upo_bst_node_t *node) {
    /* TO STUDENTS:
     *  Implemented by https://github.com/LukeAz
    */
    if (node == NULL || upo_bst_is_leaf_impl(node)) 
        return 0;
    
    size_t left = 0, right = 0;
    
    left = upo_bst_height_impl(node->left);
    right = upo_bst_height_impl(node->right);
    return 1 + (left >  right ? left : right);
}

int upo_bst_is_leaf_impl(upo_bst_node_t *node) {
    /* TO STUDENTS:
     *  Implemented by https://github.com/LukeAz
    */
    if(node!=NULL)
        if (node->left == NULL && node->right == NULL) 
            return 1;
    return 0;
}

void upo_bst_traverse_in_order(const upo_bst_t tree, upo_bst_visitor_t visit, void *visit_context)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    if(tree!=NULL) 
        upo_bst_traverse_in_order_impl(tree->root, visit, visit_context);
}

void upo_bst_traverse_in_order_impl(upo_bst_node_t *node, upo_bst_visitor_t visit, void *visit_context) {
    /* TO STUDENTS:
     *  Implemented by https://github.com/LukeAz
    */
    if (node != NULL) {
        upo_bst_traverse_in_order_impl(node->left, visit, visit_context);
        visit(node->key, node->value, visit_context);
        upo_bst_traverse_in_order_impl(node->right, visit, visit_context);
    }
}

int upo_bst_is_empty(const upo_bst_t tree)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    if (tree == NULL || tree->root == NULL) 
        return 1;
    return 0;
}


/**** EXERCISE #1 - END of FUNDAMENTAL OPERATIONS ****/


/**** EXERCISE #2 - BEGIN of EXTRA OPERATIONS ****/


void* upo_bst_min(const upo_bst_t tree)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    if (tree == NULL)
        return NULL;

    upo_bst_node_t *min = upo_bst_min_impl(tree->root);
    if(min != NULL)
        return min->key;
    return NULL;
}

void* upo_bst_min_impl(upo_bst_node_t *node) {
    /* TO STUDENTS:
     *  Implemented by https://github.com/LukeAz
    */
    if(node == NULL)
        return NULL;
    
    if(node->left != NULL)
        return upo_bst_min_impl(node->left);
    return node;
}

void* upo_bst_max(const upo_bst_t tree)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    if (tree == NULL)
        return NULL;

    upo_bst_node_t *max = upo_bst_max_impl(tree->root);
    if(max != NULL)
        return max->key;
    return NULL;
}

void* upo_bst_max_impl(upo_bst_node_t *node) {
    /* TO STUDENTS:
     *  Implemented by https://github.com/LukeAz
    */
    if(node == NULL)
        return NULL;
    
    if(node->right != NULL)
        return upo_bst_max_impl(node->right); 
    return node;
}

void upo_bst_delete_min(upo_bst_t tree, int destroy_data)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    if(tree!=NULL) {
        upo_bst_node_t *min = upo_bst_min(tree);
        if (min != NULL)
            upo_bst_delete(tree, min, destroy_data);
    }
}

void upo_bst_delete_max(upo_bst_t tree, int destroy_data)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    if(tree!=NULL) {
        upo_bst_node_t *max = upo_bst_max(tree);
        if (max != NULL)
            upo_bst_delete(tree, max, destroy_data);
    }
}

void* upo_bst_floor(const upo_bst_t tree, const void *key)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    if (tree != NULL) {
        upo_bst_node_t *node = upo_bst_floor_impl(tree->root, key, tree->key_cmp);
        if (node!=NULL)
            return node->key;
    }
    return NULL;
}

void* upo_bst_floor_impl(upo_bst_node_t *node, const void *key, upo_bst_comparator_t cmp) {
    /* TO STUDENTS:
     *  Implemented by https://github.com/LukeAz
    */
    if(node != NULL) {
        if(cmp(key, node->key) < 0) 
            return upo_bst_floor_impl(node->left, key, cmp);
        else if (cmp(key, node->key) > 0) {
            upo_bst_node_t *floor_node = upo_bst_floor_impl(node->right, key, cmp);
            return (floor_node != NULL) ? floor_node : node;
        }  
        else 
            return node;
    }
    return NULL;
}

void* upo_bst_ceiling(const upo_bst_t tree, const void *key)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    if (tree != NULL) {
        upo_bst_node_t *node = upo_bst_ceiling_impl(tree->root, key, tree->key_cmp);
        if (node!=NULL)
            return node->key;
    }
    return NULL;
}

void* upo_bst_ceiling_impl(upo_bst_node_t *node, const void *key, upo_bst_comparator_t cmp) {
    /* TO STUDENTS:
     *  Implemented by https://github.com/LukeAz
    */
    if(node != NULL) {
        if(cmp(key, node->key) > 0) 
            return upo_bst_ceiling_impl(node->right, key, cmp);
        else if (cmp(key, node->key) < 0) {
            upo_bst_node_t *floor_node = upo_bst_ceiling_impl(node->left, key, cmp);
            return (floor_node != NULL) ? floor_node : node;
        }  
        else 
            return node;
    }
    return NULL;
}

upo_bst_key_list_t upo_bst_keys_range(const upo_bst_t tree, const void *low_key, const void *high_key)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    upo_bst_key_list_t key_list = NULL;
    if(tree != NULL) 
        upo_bst_keys_range_impl(tree->root, low_key, high_key, tree->key_cmp, &key_list);
    return key_list;
}

void upo_bst_keys_range_impl(upo_bst_node_t *node, const void *low_key, const void *high_key, upo_bst_comparator_t cmp, upo_bst_key_list_t *key_list) {
    /* TO STUDENTS:
     *  Implemented by https://github.com/LukeAz
    */
    if(node == NULL) 
        return;

    upo_bst_keys_range_impl(node->left, low_key, high_key, cmp, key_list);

    if(cmp(node->key, low_key) >= 0 && cmp(node->key, high_key) <= 0) {
        upo_bst_key_list_node_t *list = malloc(sizeof(struct upo_bst_key_list_node_s));
        list->key = node->key;
        list->next = *key_list;
        *key_list = list;
    }

    upo_bst_keys_range_impl(node->right, low_key, high_key, cmp, key_list);
}

upo_bst_key_list_t upo_bst_keys(const upo_bst_t tree)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    upo_bst_key_list_t key_list = NULL;
    if(tree != NULL) 
        upo_bst_keys_impl(tree->root, tree->key_cmp, &key_list);
    return key_list;
}

void upo_bst_keys_impl(upo_bst_node_t *node, upo_bst_comparator_t cmp, upo_bst_key_list_t *key_list) {
    /* TO STUDENTS:
     *  Implemented by https://github.com/LukeAz
    */
    if(node == NULL) 
        return;

    upo_bst_keys_impl(node->left, cmp, key_list);

    upo_bst_key_list_node_t *list = malloc(sizeof(struct upo_bst_key_list_node_s));
    list->key = node->key;
    list->next = *key_list;
    *key_list = list;

    upo_bst_keys_impl(node->right, cmp, key_list);
}

int upo_bst_is_bst(const upo_bst_t tree, const void *min_key, const void *max_key)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    int is_bst = 0;
    if(tree != NULL) 
        is_bst = upo_bst_is_bst_impl(tree->root, min_key, max_key, tree->key_cmp);
    return is_bst;
}

int upo_bst_is_bst_impl(upo_bst_node_t *node, const void *min_key, const void *max_key, upo_bst_comparator_t cmp) {
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation.
     *  fprintf(stderr, "To be implemented!\n");
     *  abort();
     *  Implemented by https://github.com/LukeAz
    */
    if(node == NULL) 
        return 1;
    
    int res;

    if(cmp(node->key, min_key) > 0 && cmp(node->key, max_key) < 0) {
        res = upo_bst_is_bst_impl(node->left, min_key, node -> key, cmp);
        if(res == 1)
            res = upo_bst_is_bst_impl(node->right, node -> key, max_key, cmp);
        return res;
    }
    return 0;
    
}

/**** EXERCISE #2 - END of EXTRA OPERATIONS ****/


upo_bst_comparator_t upo_bst_get_comparator(const upo_bst_t tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    return tree->key_cmp;
}

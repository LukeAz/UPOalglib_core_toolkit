/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

/**
 * \file bst_private.h
 *
 * \brief Private header for the Binary Search Tree abstract data type.
 *
 * \author Your Name
 *
 * \copyright 2015 University of Piemonte Orientale, Computer Science Institute
 *
 *  This file is part of UPOalglib.
 *
 *  UPOalglib is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  UPOalglib is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with UPOalglib.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UPO_BST_PRIVATE_H
#define UPO_BST_PRIVATE_H


#include <upo/bst.h>
#include <stdlib.h>

/** \brief Alias for binary search tree node type. */
typedef struct upo_bst_node_s upo_bst_node_t;

/** \brief Type for nodes of a binary search tree. */
struct upo_bst_node_s
{
    void *key; /**< Pointer to user-provided key. */
    void *value; /**< Pointer to user-provided value. */
    upo_bst_node_t *left; /**< Pointer to the left child node. */
    upo_bst_node_t *right; /**< Pointer to the right child node. */
};

/** \brief Defines a binary tree. */
struct upo_bst_s
{
    upo_bst_node_t *root; /**< The root of the binary tree. */
    upo_bst_comparator_t key_cmp; /**< Pointer to the key comparison function. */
};


/**
 * \brief Clears the subtree rooted at the given node.
 *
 * \param node The root of the subtree where to clear nodes.
 * \param destroy_data Tells whether the memory previously allocated for the key
 *  and the associated value must be freed (value `1`) or not (value `0`).
 *
 * Memory deallocation (if requested) is performed by means of the `free()`
 * standard C function.
 */
static void upo_bst_clear_impl(upo_bst_node_t*, int destroy_data);

/* TO STUDENTS:
     *  Prototypes basic functions for bst
     *  Implemented by https://github.com/LukeAz
 */
upo_bst_node_t* new_node(void *key, void *value);
void* upo_bst_put_impl(upo_bst_node_t *node, void *key, void *value, void *v_old, upo_bst_comparator_t cmp);
void* upo_bst_insert_impl(upo_bst_node_t *node, void *key, void *value, upo_bst_comparator_t cmp);
void* upo_bst_get_impl(upo_bst_node_t *node, const void *key, upo_bst_comparator_t cmp);
void* upo_bst_delete_impl(upo_bst_node_t *node, const void *key, int destroy_data, upo_bst_comparator_t cmp);
void* upo_bst_delete_impl_1(upo_bst_node_t *node, int destroy_data);
void* upo_bst_delete_impl_2(upo_bst_node_t *node, int destroy_data, upo_bst_comparator_t cmp);
size_t upo_bst_size_impl(upo_bst_node_t *node);
size_t upo_bst_height_impl(upo_bst_node_t *node);
int upo_bst_is_leaf_impl(upo_bst_node_t *node);
void upo_bst_traverse_in_order_impl(upo_bst_node_t *node, upo_bst_visitor_t visit, void *visit_context);
void* upo_bst_max_impl(upo_bst_node_t *node);

upo_bst_node_t* newNode(void *key, void *value) {
    upo_bst_node_t *node = malloc(sizeof(upo_bst_node_t));
    node -> value = value;
    node -> key = key;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

/* TO STUDENTS:
     *  Prototypes for additional bst functions
     *  Implemented by https://github.com/LukeAz
 */
void* upo_bst_min_impl(upo_bst_node_t *node);
void* upo_bst_floor_impl(upo_bst_node_t *node, const void *key, upo_bst_comparator_t cmp);
void* upo_bst_ceiling_impl(upo_bst_node_t *node, const void *key, upo_bst_comparator_t cmp);
void upo_bst_keys_range_impl(upo_bst_node_t *node, const void *low_key, const void *high_key, upo_bst_comparator_t cmp, upo_bst_key_list_t *key_list);
void upo_bst_keys_impl(upo_bst_node_t *node, upo_bst_comparator_t cmp, upo_bst_key_list_t *key_list);
int upo_bst_is_bst_impl(upo_bst_node_t *node, const void *min_key, const void *max_key, upo_bst_comparator_t cmp);

#endif /* UPO_BST_PRIVATE_H */

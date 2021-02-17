#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/** HEADER
 * 
 * Implemented by https://github.com/LukeAz/
 * Inside the struct upo_queue_s I have inserted also a pointer to the last element to bring the complexity of the function enqueue to O(1)
 */

struct upo_queue_list_s {
    void *info;
    struct upo_queue_list_s *next;
};

typedef struct upo_queue_list_s* upo_queue_list_t;

struct upo_queue_s {
    upo_queue_list_t queue_el;
    upo_queue_list_t last_el;
    size_t size;
};

typedef struct upo_queue_s* upo_queue_t;

//Prototype
upo_queue_t upo_queue_create();
void upo_queue_destroy(upo_queue_t queue, int destroy_data);
void upo_queue_clear(upo_queue_t queue, int destroy_data);
void upo_queue_enqueue(upo_queue_t queue, void *data);
void upo_queue_dequeue(upo_queue_t queue, int destroy_data);
void* upo_queue_peek(const upo_queue_t queue);
size_t upo_queue_size(const upo_queue_t queue);
int upo_queue_is_empty(const upo_queue_t queue);
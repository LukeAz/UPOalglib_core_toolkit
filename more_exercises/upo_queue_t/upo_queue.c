#include "upo_queue.h"

/** FUNCTIONS
 * 
 * Implemented by https://github.com/LukeAz/
 */

upo_queue_t upo_queue_create() {
    upo_queue_t queue = malloc(sizeof(struct upo_queue_s));
    if(queue == NULL) {
        perror("Failed to allocate: upo_queue_t");
        abort();
    }
    queue->queue_el = NULL;
    queue->last_el = NULL;
    queue->size = 0;
    return queue;
}

void upo_queue_destroy(upo_queue_t queue, int destroy_data) {
    if(queue != NULL) {
        upo_queue_clear(queue, destroy_data);
        free(queue);
    }
}

void upo_queue_clear(upo_queue_t queue, int destroy_data) {
    if(queue != NULL) {
        upo_queue_list_t element = queue->queue_el, remove = NULL;
        while(queue->queue_el != NULL) {
            upo_queue_dequeue(queue, destroy_data);
        } 
        queue->size=0;   
    }
}

void upo_queue_enqueue(upo_queue_t queue, void *data) {
    if(queue != NULL) {
        upo_queue_list_t element = malloc(sizeof(struct upo_queue_list_s));
        if(element == NULL) {
            perror("Failed to allocate: upo_queue_list_t");
            abort();
        }
        
        element->info = data;
        element->next = NULL;
        
        if(queue->queue_el == NULL) {
            queue->queue_el = element;
            queue->last_el = element;
        } else {
            queue->last_el->next = element;
            queue->last_el = element;
        }
        queue->size++;
    }
}

void upo_queue_dequeue(upo_queue_t queue, int destroy_data) {
    if(queue != NULL) {
        upo_queue_list_t remove;
        remove = queue->queue_el;
        queue->queue_el = queue->queue_el->next;
        if(destroy_data)
            free(remove->info);
        free(remove);
        queue->size--;
    }
}

void* upo_queue_peek(const upo_queue_t queue) {
    if(queue != NULL) {
        return queue->queue_el->info;
    }
    return NULL;
}

size_t upo_queue_size(const upo_queue_t queue) {
    if(queue!= NULL) 
        return queue->size;
    return 0;
}

int upo_queue_is_empty(const upo_queue_t queue) {
    if(queue == NULL || (queue != NULL && queue->queue_el == NULL))
        return 1;
    return 0;
}

#include "upo_queue.h"

/** MAIN
 * 
 * Implemented by https://github.com/LukeAz/
 */

int main() {
    
    upo_queue_t queue; 
    size_t size;
    int v1=5, v2=7, v3=11;

    queue = upo_queue_create();
    assert(queue!=NULL);
    assert(upo_queue_size(queue)==0);
    printf("[OK] Test Create: Success!\n");

    upo_queue_enqueue(queue, &v1);
    assert(upo_queue_size(queue)==1);
    assert(*(int *)upo_queue_peek(queue)==v1);
    
    upo_queue_dequeue(queue, 0);
    assert(upo_queue_size(queue)==0);
    assert(upo_queue_is_empty(queue)==1);
    printf("[OK] Test Emqueue/Dequeue/Size/Isempty: Success!\n");

    upo_queue_enqueue(queue, &v1);
    upo_queue_enqueue(queue, &v2);
    upo_queue_enqueue(queue, &v3);
    assert(upo_queue_size(queue)==3);
    assert(upo_queue_is_empty(queue)==0);
    assert(*(int *)upo_queue_peek(queue)==v1);

    upo_queue_clear(queue, 0);
    assert(upo_queue_is_empty(queue)==1);
    printf("[OK] Test clear: Success!\n");

    upo_queue_enqueue(queue, &v1);
    upo_queue_enqueue(queue, &v2);

    upo_queue_destroy(queue, 0);
    assert(upo_queue_is_empty(queue)==1);
    printf("[OK] Test destroy: Success!\n");
}

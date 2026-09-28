#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

void test_queue()
{
    Queue queue = queue_new(10);
    QueueResult result = {0, RESULT_INVALID};

  
    // Test queue_add
    

    queue_add(&queue, 64, &result);

    assert(result.data == 64);
    assert(result.status == QUEUE_OK);

    queue_add(&queue, 67, &result);

    assert(result.data == 67);
    assert(result.status == QUEUE_OK);


    
    // Test queue_peek
    

    queue_peek(&queue, &result);

    // 64 was added first, so it is at the front
    assert(result.data == 64);
    assert(result.status == QUEUE_OK);


    // Test queue_remove
    

    queue_remove(&queue, &result);

    // 64 should be removed first
    assert(result.data == 64);
    assert(result.status == QUEUE_OK);


    // Now 67 should be at the front
    queue_peek(&queue, &result);

    assert(result.data == 67);
    assert(result.status == QUEUE_OK);


    
    // Test queue_remove again
    

    queue_remove(&queue, &result);

    assert(result.data == 67);
    assert(result.status == QUEUE_OK);


    
    // Test queue_isEmpty
    

    assert(queue_isEmpty(&queue));


    
    // Test removing from empty queue
    

    queue_remove(&queue, &result);

    assert(result.data == RESULT_INVALID);
    assert(result.status == QUEUE_EMPTY);


    
    // Test peeking empty queue
    

    queue_peek(&queue, &result);

    assert(result.data == RESULT_INVALID);
    assert(result.status == QUEUE_EMPTY);


    printf("All queue tests passed!\n");
}

int main()
{
    test_queue();

    return 0;
}
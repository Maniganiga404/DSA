#include<assert.h>
#include<stddef.h>
#include "queue.h"

Queue queue_new(uint32_t size)
{
    size = (size > 0 && size <= MAX_QUEUE_LEN)? size:MAX_QUEUE_LEN;

    Queue queue = {size,0,0,0,{0}};

    return queue;
}

Queue *queue_add(Queue *queue, uint32_t data, QueueResult *result)
{
    if(queue -> count < queue -> size)
    {
        queue -> q[queue -> tail] = data;
        queue -> tail = (queue -> tail + 1) % queue -> size;
        ++queue -> count;

        result -> data = data;
        result -> status = QUEUE_OK;
    }
    else{
        result -> data = RESULT_INVALID;
        result -> status = QUEUE_FULL;
    }
    return queue;
}

Queue *queue_remove(Queue *queue, QueueResult *result)
{
    if(queue -> count > 0)
    {
        result -> data = queue -> q[queue -> head];
        queue -> head = (queue -> head + 1)% queue -> size;
        --queue -> count;

        result -> status = QUEUE_OK;
    }
    else{
        result -> data = RESULT_INVALID;
        result -> status = QUEUE_EMPTY;
    }
    return queue;
}

Queue *queue_peek(Queue *queue, QueueResult *result)
{
    if(queue->count>0)
    {
        result->data = queue->q[queue->head];
        result->status = QUEUE_OK;
    }
    else
    {
        result->data = RESULT_INVALID;
        result->status = QUEUE_EMPTY;
    }
    return queue;
}

uint32_t queue_isFull(const Queue *queue)
{
    return queue->count == queue->size;
}

uint32_t queue_isEmpty(const Queue *queue)
{
    return (queue->count == 0 && queue->head == queue->tail);
}






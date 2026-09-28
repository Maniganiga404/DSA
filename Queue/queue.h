#include<stdint.h>
#define MAX_QUEUE_LEN 32

struct _queue_{
    uint32_t size;
    uint32_t count;
    uint32_t head;
    uint32_t tail;
    uint32_t q[MAX_QUEUE_LEN];
};

typedef struct _queue_ Queue;

struct _result_{
    uint32_t data;
    uint32_t status;
};

typedef struct _result_ QueueResult;

#define RESULT_INVALID 0
#define QUEUE_OK 1
#define QUEUE_FULL 2
#define QUEUE_EMPTY 4

Queue queue_new(uint32_t size);

Queue *queue_add(Queue *queue, uint32_t data, QueueResult *result);

Queue *queue_remove(Queue *queue, QueueResult *result);

Queue *queue_peek(Queue *queue, QueueResult *result);

uint32_t queue_isFull(const Queue *queue);

uint32_t queue_isEmpty(const Queue *queue);

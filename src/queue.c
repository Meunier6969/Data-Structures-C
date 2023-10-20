#include <stdlib.h>
#include <stdio.h>

#include "../headers/queue.h"

que_list QUE_createEmptyQueue()
{
    que_list newQueue;

    newQueue.values = (int*) malloc(QUEUE_MAX_SIZE * sizeof(int));
    newQueue.numberOfElements = 0;

    return newQueue;
}

int QUE_isEmptyQueue(que_list queue)
{
    return queue.numberOfElements == 0;
}

int QUE_isFullQueue(que_list queue)
{
    return queue.numberOfElements == QUEUE_MAX_SIZE;
}

void QUE_queue(que_list *queue, int value)
{
    if (QUE_isFullQueue(*queue))
    {
        printf("cannot queue on a full queue\n");
        return;
    }

    printf("stacking %d\n", value);

    queue->values[queue->numberOfElements] = value;
    queue->numberOfElements++;
}

int QUE_unqueue(que_list *queue)
{
    if (QUE_isEmptyQueue(*queue))
    {
        printf("cannot unqueue on an empty queue\n");
        return 0;
    }

    int toDelete = queue->values[0];
    printf("unstacking %d\n", toDelete);

    for (size_t i = 0; i < queue->numberOfElements; i++)
    {
        queue->values[i] = queue->values[i+1]; 
    }
    
    queue->numberOfElements--;

    return toDelete;
}

void QUE_displayList(que_list queue)
{
    if (queue.numberOfElements == 0)
    {
        printf("stack [empty]\n");
        return;
    }

    printf("queue [");
    for (int i = 0; i < queue.numberOfElements; i++)
    {
        if (i != 0) printf(" : ");
        printf("%i", queue.values[i]);
    }
    printf("]\n");
}
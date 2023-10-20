#pragma once

// FIRST IN FIRST OUT
#define QUEUE_MAX_SIZE 50

typedef struct que_list
{
    int* values;
    int numberOfElements;
} que_list;

que_list QUE_createEmptyQueue();

int QUE_isEmptyQueue(que_list queue);
int QUE_isFullQueue(que_list queue);
void QUE_queue(que_list *queue, int value);
int QUE_unqueue(que_list *queue);

void QUE_displayList(que_list queue);


#include <stdlib.h>

#define false 0
#define true 1

typedef int bool;

/***********************************/

typedef struct MyLinkNode {
    int value;
    struct MyLinkNode *next;
} MyLinkNode;

typedef struct {
    int size;
    int capacity;
    MyLinkNode *front, *rear;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *obj = (MyCircularQueue *)malloc(k * sizeof(MyCircularQueue));
    obj->capacity = k;
    obj->size = 0;
    obj->front = NULL;
    obj->rear = NULL;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size >= obj->capacity) {
        return false;
    }
    MyLinkNode *node = malloc(sizeof(MyLinkNode));
    node->value = value;
    node->next = NULL;
    obj->rear->next = node;
    obj->rear = node;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) return 0;
    MyLinkNode *p = obj->front->next;

}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) return -1;

    return obj->front->value;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) return -1;

    return obj->rear->value;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    obj->size = 0;
    obj->capacity = 0;
    obj->front->next == NULL;
    obj->rear->next == NULL;
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
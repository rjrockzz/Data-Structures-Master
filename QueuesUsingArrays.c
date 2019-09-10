//@coding bloke
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};
struct Queue* create(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(queue->capacity*(sizeof(int)));
    return queue;
}
int isFull(struct Queue* queue)
{
    return (queue->size==queue->rear);
}
int isEmpty(struct Queue* queue)
{
    return queue->size == 0;
}
void enque(struct Queue* queue, int data)
{
    if(isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;    //A circular queue uses this concept if rear==9 return 0 and if rear==3
                                                        //returns 4 , when the capacity is given to be 10
    queue->array[queue->rear] = data;
    queue->size++;
    printf("Enqueued to the Queue! = %d\n", data);
}
int deque(struct Queue* queue)
{
    if(isEmpty(queue))
        return INT_MIN;
    int data = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;    //As seen in Enqueue, A circular queue uses this concept if front==9
                                                            // return 0 and if front==3 , returns 4 , when the capacity is given to be 10
    queue->size--;
    return data;
}
int front(struct Queue* queue)
{
    if(isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
int rear(struct Queue* queue)
{
    if(isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}
int main()
{
    struct Queue* queue = create(10);
    enque(queue, 22);
    enque(queue, 11);
    enque(queue, 20);
    enque(queue, 30);
    printf("Dequeued from Queue = %d\n",deque(queue));
    printf("The front item is = %d\n", front(queue));
    printf("The rear item is = %d\n", rear(queue));
    return 0;
}
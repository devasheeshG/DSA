#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Queue *q)
{
    return q->rear == q->size - 1;
}

int isEmpty(struct Queue *q)
{
    return q->front == q->rear;
}

void show(struct Queue *q)
{
    if (isEmpty(q))
        return;

    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("Index: %d Element: %d\n", i, q->arr[i]);
    }
}

void enqueue(struct Queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is Full!\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = data;
}

int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty!\n");
        return -1;
    }

    int data = q->arr[q->front + 1];
    q->front++;
    return data;
}

int main()
{
    struct Queue q;
    q.size = 10;
    q.front = -1;
    q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 10);
    enqueue(&q, 20);

    show(&q);

    printf("Dequeued Element: %d\n", dequeue(&q));

    show(&q);

    return 0;
}
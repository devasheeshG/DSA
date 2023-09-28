#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct Stack *s)
{
    return s->top == s->size - 1;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

void show(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty!\n");
        return;
    }

    for (int i = 0; i <= s->top; i++)
    {
        printf("Index: %d Element: %d\n", i, s->arr[i]);
    }
}

void push(struct Stack *s, int data)
{
    if (isFull(s))
        return;
    s->top++;
    s->arr[s->top] = data;
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty!\n");
        return -1;
    }
    int data = s->arr[s->top];
    s->top--;
    return data;
}

int main()
{
    struct Stack s;
    s.size = 10;
    s.top = -1;
    s.arr = (int *)malloc(s.size * sizeof(int));

    show(&s);

    push(&s, 5);
    push(&s, 50);

    show(&s);

    printf("Popped Element: %d\n", pop(&s));
    printf("Popped Element: %d\n", pop(&s));

    show(&s);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* push(struct Node* head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

void show(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node* pop(struct Node *head)
{
    struct Node* ptr = head;
    if (ptr == NULL)
    {
        printf("Stack is Empty!\n");
        return NULL;
    }


    int data = head->data;
    printf("Popped Element: %d\n", data);
    head = head->next;
    free(ptr);
    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;

    show(head);

    head = push(head, 20);
    head = push(head, 30);

    show(head);

    head = pop(head);
    head = pop(head);

    show(head);
        
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

// Traversing a Linked List
void traversalLinkedList(struct Node *newNode) {
    int index = 0;
    while (newNode != NULL)
    {
        printf("Index: %d - Element: %d\n", index, newNode->data);
        newNode = newNode->next;
        index++;
    }
    printf("Linked List Traversed Successfully!\n\n");
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 675;
    head->next = second;

    second->prev = head;
    second->data = 276;
    second->next = third;

    third->prev = second;
    third->data = 366;
    third->next = NULL;

    traversalLinkedList(head);

    return 0;
}
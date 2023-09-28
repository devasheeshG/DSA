#include <stdio.h>
#include <stdlib.h>

// Node for Linked List
struct Node
{
    int data;
    struct Node *next;
};

// Traversing a Linked List
void traversalLinkedList(struct Node *newNode)
{
    int index = 0;
    while (newNode != NULL)
    {
        printf("Index: %d - Element: %d\n", index, newNode->data);
        newNode = newNode->next;
        index++;
    }
    printf("Linked List Traversed Successfully!\n\n");
}

// Insetion in Linked List
// 1. Insertion at the beginning
struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = head;
    newNode->data = data;
    head = newNode;
    return head;
}

// 2. Insertion in between
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    // set data
    newNode->data = data;

    // set pointer
    newNode->next = p->next;
    p->next = newNode;

    return head;
}

// 3. Insertion at the end
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    // set data
    newNode->data = data;

    // set pointer
    p->next = newNode;
    newNode->next = NULL;

    return head;
}

// 4. Insertion after a node
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // set data
    newNode->data = data;

    // set pointer
    newNode->next = prevNode->next;
    prevNode->next = newNode;

    return head;
}

// Deletion in Linked List
// 1. Deletion at the beginning
struct Node *deleteAtBeginning(struct Node *head)
{
    struct Node *p = head;
    head = head->next;
    free(p);
    return head;
}

// 2. Deletion in between
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    struct Node *toBeDeletedNode = p->next;
    p->next = p->next->next;
    printf("Deleted Element: %d at index: %d\n", toBeDeletedNode->data, index);
    free(toBeDeletedNode);

    return head;
}

// 3. Deletion at the end

// 4. Deletion of first node found with given value

int main()
{
    // Create Linked List with 3 nodes (head, second, third)
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Create a Linked List
    head->data = 21;
    head->next = second;

    second->data = 24;
    second->next = third;

    third->data = 31;
    third->next = NULL; // end of the linked list

    // Traversing a Linked List
    traversalLinkedList(head);

    // Insertion in Linked List
    head = insertAtBeginning(head, 100);
    traversalLinkedList(head);

    head = insertAtIndex(head, 200, 2);
    traversalLinkedList(head);

    head = insertAtEnd(head, 300);
    traversalLinkedList(head);

    head = insertAfterNode(head, second, 400);
    traversalLinkedList(head);

    // Deletion in Linked List
    head = deleteAtBeginning(head);
    traversalLinkedList(head);

    head = deleteAtIndex(head, 2);
    traversalLinkedList(head);
    return 0;
}
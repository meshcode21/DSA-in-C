#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;
Node* front = NULL;
Node* rear = NULL;

int isEmpty() {
    return front == NULL;
}

void enqueue(int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = front;
    printf("Dequeued element: %d\n", front->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, item;
    while (1) {
        system("cls");
        printf("\nQueue Operations using Linked List\n\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
        printf("\nPress any key to continue...\n");
        getch();
    }
    return 0;
}
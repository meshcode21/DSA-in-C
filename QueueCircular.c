#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 10 

int queue[MAX], front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % MAX);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued element: %d\n", queue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i != rear; i = (i + 1) % MAX) {
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[rear]); // Print the last element
}

int main() {
    int choice, value;
    while (1) {
        system("cls");
        printf("Circular Queue Operations:\n\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("\nPress any key to continue...\n");
        getch();
    }
    return 0;
}

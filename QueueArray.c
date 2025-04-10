#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10

int queue[MAX], front = -1, rear = -1;

int isFull() {
    return rear == MAX - 1;
}
int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full\n");
    }
    else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = item;
    }
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    }
    else {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
    }
}
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, item;

    while (1) {
        system("cls");
        printf("Queue Operations using Array\n");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
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
    getch();
}
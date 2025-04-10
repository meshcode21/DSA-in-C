#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10

int minQueue[MAX], maxQueue[MAX];
int minFront = -1, minRear = -1;
int maxFront = -1, maxRear = -1;

int isEmpty(int front) {
    return front == -1;
}

void minEnqueue(int value) {
    if (minRear == MAX - 1) {
        printf("Min Priority Queue is full\n");
        return;
    }
    if (isEmpty(minFront)) {
        minFront = 0;
    }
    minRear++;
    minQueue[minRear] = value;
    for (int i = minRear; i > minFront && minQueue[i] < minQueue[i - 1]; i--) {
        int temp = minQueue[i];
        minQueue[i] = minQueue[i - 1];
        minQueue[i - 1] = temp;
    }
}

void minDequeue() {
    if (isEmpty(minFront)) {
        printf("Min Priority Queue is empty\n");
        return;
    }
    printf("Dequeued Min: %d\n", minQueue[minFront]);
    if (minFront == minRear) minFront = minRear = -1;
    else minFront++;
}

void maxEnqueue(int value) {
    if (maxRear == MAX - 1) {
        printf("Max Priority Queue is full\n");
        return;
    }
    if (isEmpty(maxFront)) {
        maxFront = 0;
    }
    maxRear++;
    maxQueue[maxRear] = value;
    for (int i = maxRear; i > maxFront && maxQueue[i] > maxQueue[i - 1]; i--) {
        int temp = maxQueue[i];
        maxQueue[i] = maxQueue[i - 1];
        maxQueue[i - 1] = temp;
    }
}

void maxDequeue() {
    if (isEmpty(maxFront)) {
        printf("Max Priority Queue is empty\n");
        return;
    }
    printf("Dequeued Max: %d\n", maxQueue[maxFront]);
    if (maxFront == maxRear) maxFront = maxRear = -1;
    else maxFront++;
}

void display(int queue[], int front, int rear) {
    if (isEmpty(front)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        system("cls");
        printf("\nPriority Queue Operations:\n\n");
        printf("1. Min Enqueue\n2. Min Dequeue\n3. Display Min Queue\n");
        printf("4. Max Enqueue\n5. Max Dequeue\n6. Display Max Queue\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                printf("Enter value to enqueue (Min Priority): ");
                scanf("%d", &value);
                minEnqueue(value);
                break;
            case 2:
                minDequeue();
                break;
            case 3:
                display(minQueue, minFront, minRear);
                break;
            case 4:
                printf("Enter value to enqueue (Max Priority): ");
                scanf("%d", &value);
                maxEnqueue(value);
                break;
            case 5:
                maxDequeue();
                break;
            case 6:
                display(maxQueue, maxFront, maxRear);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("\nPress any key to continue...\n");
        getch();
    }
    return 0;
}
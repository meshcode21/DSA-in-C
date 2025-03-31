#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Stack structure using linked list
struct LinkedListStack
{
    Node *top;
    int size;
};
typedef struct LinkedListStack LinkedListStack;

// Function to push an element onto the stack
void push(LinkedListStack *stack, int data)
{
    Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// Function to pop an element from the stack
// Returns -1 if stack is empty
int pop(LinkedListStack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack Underflow\n");
        return -1; // Indicate stack is empty
    }
    Node *temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return poppedValue;
}

// Function to display the stack elements
void display(LinkedListStack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    Node *temp = stack->top;
    printf("Stack elements are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    LinkedListStack stack;
    stack.size = 0;
    stack.top = NULL;

    int choice, value;
    int poppedValue;
    do
    {
        system("cls");
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&stack, value);
            break;
        case 2:
            poppedValue = pop(&stack); // Use the declared variable
            if (poppedValue != -1)
                printf("Popped value: %d\n", poppedValue);
            break;
        case 3:
            display(&stack);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
        printf("\nEnter any key to continue...");
        getch();
    } while (choice != 4);
    return 0;
}
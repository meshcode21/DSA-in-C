#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int stack[100], top = -1, n;
    int i, choice, value;
    printf("Enter the size of stack: ");
    scanf("%d", &n);
    do
    {
        system("cls");
        printf("The size of stack is %d \n", n);
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (top == n - 1)
                printf("Stack Overflow\n");
            else
            {
                printf("Enter value to push: ");
                scanf("%d", &value);
                stack[++top] = value;
            }
            break;
        case 2:
            if (top == -1)
                printf("Stack Underflow\n");
            else
            {
                value = stack[top--];
                printf("Popped value: %d\n", value);
            }
            break;
        case 3:
            if (top == -1)
                printf("Stack is empty\n");
            else
            {
                printf("Stack elements are: ");
                for (i = top; i >= 0; i--)
                    printf("%d ", stack[i]);
                printf("\n");
            }
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

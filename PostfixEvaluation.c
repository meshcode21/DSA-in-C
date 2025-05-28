#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 50

int main()
{
    float vstack[MAX];
    int tos = -1;

    char postfix[MAX];
    int i = 0;

    char ch;
    printf("Enter the postfix expression:\n");
    while (1)
    {
        ch = getch();
        printf(" %c", ch);
        if (ch == 13)
            break;

        postfix[i++] = ch;
    }
    postfix[i] = '\0';
    printf("\n");

    printf("\nvalue\top1\top2\tresult\tV-Stack\n");
    printf("----------------------------------------\n");

    float op1, op2, result;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        op1 = -1;
        if (postfix[i] >= '0' && postfix[i] <= '9')
            vstack[++tos] = postfix[i] - '0';
        else
        {
            op1 = vstack[tos--];
            op2 = vstack[tos--];
            switch (postfix[i])
            {
            case '+':
                result = op2 + op1;
                break;
            case '-':
                result = op2 - op1;
                break;
            case '*':
                result = op2 * op1;
                break;
            case '/':
                result = op2 / op1;
                break;
            case '^':
                result = pow(op2, op1);
                break;
            }
            vstack[++tos] = result;
        }

        if (op1 != -1)
            printf("%c\t%.2f\t%.2f\t%.2f\t", postfix[i], op1, op2, result);
            else
            printf("%c\t-\t-\t-\t", postfix[i]);

        for (int j = 0; j <= tos; j++)
        {
            printf("%.2f ", vstack[j]);
        }
        printf("\n");
    }

    printf("\nThe value is: %.2f", vstack[tos]);
    getch();
}
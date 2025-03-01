#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#define MAX 50

char stack[MAX];
int tos = -1;

bool isempty(){
    return tos == -1;
}
void push(char ch){
    stack[++tos] = ch;
}
char pop(){
    if(!isempty())
        return stack[tos--];
    return ' ';
}
char peek(){
    return stack[tos];
}

int precedende(char op){
    if(op=='!') return 1; //highest precedence
    if(op=='^' || op=='$') return 2;
    if(op=='*' || op=='/' || op=='%') return 3;
    if(op=='+' || op=='-') return 4;
    else return 5;
}

bool CheckPrecedende(char op1, char op2){
    return precedende(op1) < precedende(op2);
}

int whatCharacterIs(char ch){
    if((ch>=65 && ch<=90) || (ch>=97 && ch<=122)) 
        return 1; // if the character is Letter.

    if(ch=='(') return 2;
    if(ch==')') return 3;

    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='$' || ch=='^' || ch=='%')
        return 4;

    return 0;
}

void TableRow(char infix[], char postfix[], int i, int j){
    if(infix[i]=='\0') printf("\n\t...");
    else printf("\n\t%c",infix[i]);

    printf("\t\t");
        if(isempty()) printf("...");
        else 
            for(int a=0; a<=tos;a++)
                printf("%c",stack[a]);

    printf("\t\t");
    if(j==0) printf("...");
    else
        for(int a=0; a<j; a++)
            printf("%c",postfix[a]);
}

int main(){
    char infix[MAX],postfix[MAX];
    int i=0;
    char ch;


    printf("Enter the Infix expression:\n");
    do{
        ch = getch();
        printf("%c",ch);

        if(ch != 13)
            infix[i++] = ch;

    }while(ch != 13);
    infix[i] = '\0'; 

    //print table
    printf("\n\nProcess Table\n");
    printf("\n\tInput\t\tStack\t\tPostfix\n");

    int j = 0;
    for(i=0; infix[i] != '\0'; i++){     
        switch(whatCharacterIs(infix[i])){
            case 1: 
                postfix[j++] = infix[i];
                break;
            case 2:
                push(infix[i]);
                break;
            case 3:
                while(peek()!='(' && !isempty()){
                    postfix[j++] = pop();
                }
                if(!isempty()) pop();
                break;
            case 4:
                if(isempty() || peek()=='(') 
                    push(infix[i]);
                else{
                    
                    if(CheckPrecedende(peek(),infix[i])){
                        postfix[j++] = pop();
                        push(infix[i]);
                    }else{
                        push(infix[i]);
                    }
                }
                
                break;
        }

        TableRow(infix,postfix,i,j);
    }
    while(!isempty()){
        if(peek()!='(')
            postfix[j++] = pop();
        else
            pop();
        TableRow(infix,postfix,i,j);
    }
    TableRow(infix,postfix,i,j);

    postfix[j] = '\0';

    printf("\n\nPostfix Expression is :\n");
    for(i=0; postfix[i]!='\0'; i++)
        printf("%c",postfix[i]);

    getch();
    return 0;
}
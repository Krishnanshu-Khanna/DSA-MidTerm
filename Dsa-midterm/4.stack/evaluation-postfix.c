#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100
struct Stack {
    int data[MAX_SIZE];
    int top;
};

void push(struct Stack *stack, int element) 
{
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        exit(0);
    }
    stack->top++;
    stack->data[stack->top] = element;
}

int pop(struct Stack *stack) 
{
    if (stack->top == -1) {
        printf("Stack Underflow!\n");
        exit(0);
    }
    int element = stack->data[stack->top];
    stack->top--;
    return element;
}

int isOperator(char ch) 
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return 1;
    }
    return 0;
}

int evaluatePostfix(char *postfix) {
    struct Stack stack;
    stack.top = -1;
    int i, operand1, operand2, result;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isOperator(postfix[i])) {
            operand2 = pop(&stack);
            operand1 = pop(&stack);
            switch (postfix[i]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }
            push(&stack,result);
        }
        else {
            switch (postfix[i]) {
                case 'a': push(&stack, 8); break;
                case 'b': push(&stack, 2); break;
                case 'c': push(&stack, 2); break;
                case 'd': push(&stack, 1); break;
                case 'e': push(&stack, 3); break;
                case 'f': push(&stack, 4); break;
                case 'g': push(&stack, 2); break;
            }
        }
    }
    result = pop(&stack);
    return result;
}


int main() 
{
    char postfix[MAX_SIZE];
    int result;
    scanf("%s", postfix);
    result = evaluatePostfix(postfix);
    printf("The value of the expression is %d\n", result);
    return 0;
}

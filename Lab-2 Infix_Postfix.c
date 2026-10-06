#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if (top == -1)
        return '\0';
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default:  return 0;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    int i = 0, j = 0;
    char c;

    top = -1;

    while (infix[i] != '\0') {
        c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(')
                postfix[j++] = pop();
            if (!isEmpty() && peek() == '(')
                pop();
        }
        else if (isOperator(c)) {
            if (c == '^') {
                while (!isEmpty() && precedence(peek()) > precedence(c))
                    postfix[j++] = pop();
            } else {
                while (!isEmpty() && precedence(peek()) >= precedence(c))
                    postfix[j++] = pop();
            }
            push(c);
        }
        i++;
    }

    while (!isEmpty())
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n')
        infix[len - 1] = '\0';

    infixToPostfix(infix, postfix);

    printf("Infix   : %s\n", infix);
    printf("Postfix : %s\n", postfix);

    return 0;
}

#include <stdio.h>

#define SIZE 3

// Stack structure
typedef struct {
    int data[SIZE];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Push an element into the stack
void push(Stack *stack, int value) {
    if (stack->top < SIZE - 1) {
        stack->data[++stack->top] = value;
    }
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return -1; // Should not reach here as input is valid
}

// Function to find the missing brother using a stack
int findMissingBrother(int a, int b) {
    Stack stack;
    initStack(&stack);

    // Push all three brothers' numbers onto the stack (1, 2, 3)
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    // Pop all elements and check which one is missing
    int x = pop(&stack);
    int y = pop(&stack);
    int z = pop(&stack);

    // If x is not in the input, it's the missing brother.
    if (x != a && x != b) {
        return x;
    }
    // If y is not in the input, it's the missing brother.
    else if (y != a && y != b) {
        return y;
    }
    // Otherwise, z is the missing brother.
    else {
        return z;
    }
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    // Find and print the missing brother
    int missingBrother = findMissingBrother(a, b);
    printf("%d\n", missingBrother);

    return 0;
}
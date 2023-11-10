#include <stdio.h>
#define MAX_SIZE 1000

struct Stack {
    int top;
    int Nums[MAX_SIZE];
};

void initializeStack(struct Stack *S);
void push(struct Stack *S, int element);
int pop(struct Stack *S);
int isEmpty(struct Stack *S);
int nextGreaterElement(int Nums[], int N);

int main() {
    int N;
    printf("Enter the size of the array (1 <= N <= 1000): ");
    scanf("%d", &N);
    int Nums[MAX_SIZE];

    printf("Enter the array of %d elements: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &Nums[i]);
    }

    nextGreaterElement(Nums, N);
    return 0;
}

void initializeStack(struct Stack *S) {
    S->top = -1;
}

void push(struct Stack *S, int element) {
    S->top++;
    S->Nums[S->top] = element;
}

int pop(struct Stack *S) {
    return S->Nums[(S->top)--];
}

int isEmpty(struct Stack *S) {
    return (S->top == -1) ? 1 : 0;
}

int nextGreaterElement(int Nums[], int N) {
    struct Stack S;
    initializeStack(&S);
    int result[MAX_SIZE];

    for (int i = 0; i < N; i++) {
        result[i] = -1;

        while (!isEmpty(&S) && Nums[i] > Nums[S.NumS[S.top]]) {
            result[S.NumS[S.top]] = Nums[i];
            pop(&S);
        }

        push(&S, i);
    }

    // Print the result array
    for (int i = 0; i < N; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}

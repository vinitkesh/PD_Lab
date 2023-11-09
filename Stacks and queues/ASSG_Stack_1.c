// PD lab assigment 5 Q1 
// we use a struct to keep a attribute S.top 
//(which is the index of the top element of the stack)

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Stack
{
    int top;
    int arr[MAX_SIZE];
};

int StackEmpty(struct Stack *S);
int StackFull(struct Stack *S);
void Push(struct Stack *S, int k);
void Pop(struct Stack *S);
int Peek(struct Stack *S);

// Main function
int main() {
    struct Stack S;
    S.top = -1;  // Initialize stack top

    char choice;

    do {
        printf("\nMenu:\n");
        printf("i - Push\n");
        printf("d - Pop\n");
        printf("p - Peek\n");
        printf("t - Terminate\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'i':
                if (StackFull(&S)) {
                    printf("Stack is full. Cannot push.\n");
                } else {
                    int value;
                    printf("Enter the value to push: ");
                    scanf("%d", &value);
                    Push(&S, value);
                    printf("%d pushed onto the stack.\n", value);
                }
                break;

            case 'd':
                if (StackEmpty(&S)) {
                    printf("Stack is empty. Cannot pop.\n");
                } else {
                    Pop(&S);
                }
                break;

            case 'p':
                if (StackEmpty(&S)) {
                    printf("Stack is empty. Cannot peek.\n");
                } else {
                    printf("Top element: %d\n", Peek(&S));
                }
                break;

            case 't':
                printf("Terminating the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter i, d, p, or t.\n");
        }

    } while (choice != 't');

    return 0;
}
///////////ALL FUNCTIONS/////////////////////
int StackEmpty(struct Stack *S){
    if(S->top==-1){ return 1; }
    else{ return 0; }
}
int StackFull(struct Stack *S){
    {if(S->top==MAX_SIZE-1){return 1;}
    else{return 0;}}
}

void Push(struct Stack *S, int k){
    S->top++;
    S->arr[S->top]=k;

}
void Pop(struct Stack *S){
    S->top--;
}
int Peek(struct Stack *S){
    return S->arr[S->top];
}

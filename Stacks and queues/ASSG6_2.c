#include <stdio.h>
#define MAX_SIZE 1000

struct Stack {
    int top;
    int Nums[MAX_SIZE];
};

void initializeStack(struct Stack *S);            
void            push(struct Stack *S, int element);
int              pop(struct Stack *S);      //returns the popped element
int          isEmpty(struct Stack *S);      //returns 1 if stack is empty, 0 otherwise
int nextGreaterElement(int Nums[], int N);
///////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    int N;
    printf("Enter the size of the array (1 <= N <= 1000): ");
    scanf("%d", &N);
    int Nums[MAX_SIZE];

    printf("Enter the array of %d elements: ", N);////Inputting the array
    for (int i = 0; i < N; i++) {scanf("%d", &Nums[i]);}

    nextGreaterElement(Nums, N);// calling the answer function
    return 0;
}


////////  FUNCTIONS  //////////////////////////////////////////////////

void initializeStack(struct Stack *S) {
    S->top = -1;
}

void push(struct Stack *S, int element) {
    S->top++;
    S->Nums[S->top] = element;
}

int pop(struct Stack *S) {
    S->top--;
}

int isEmpty(struct Stack *S) {
    return (S->top == -1) ? 1 : 0;
}

int nextGreaterElement(int Nums[], int N) {
    struct Stack S;
    initializeStack(&S);
    int result[MAX_SIZE];

    for(int i=0;i<N;i++){
        result[i]=-1;
    }

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(Nums[j]>Nums[i]){
                result[i]=Nums[j];
                break;
            }

        }
    }

    // Print the result array
    for (int i = 0; i < N; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
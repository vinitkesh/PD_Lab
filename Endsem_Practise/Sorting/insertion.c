// Date: 2021/7/9

//Insertion sort: O(n^2)
// take i from 1 to n-1
// j from i-1 to 0 and compare arr[j] with key
// until arr[j] is greater than key, shift it to the right


#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void insertionsort(int arr[], int n){
    int i=1, j, key;
    while(i<n){
        key = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){//if arr[j] is greater than key, shift it to the right
            swap(arr+j, arr+j+1);
            j--;
        }
        i++;
    }
    
}

int main()
{
    int arr[] = {5, 4, 7, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionsort(arr, n);

    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
        
    return 0;
}

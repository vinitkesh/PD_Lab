
// Selection sort: O(n^2)
// take i from 0 to n-2
// j from i+1 to n-1 and compare arr[j] with arr[i]
// if arr[j] is smaller than arr[i], swap them

#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void selectionsort(int arr[], int n){
    int i, j, min;
    for (i=0; i<n-1; i++){
        min = i;
        for (j=i+1; j<n; j++){
            if (arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr+i, arr+min);
    }
}



int main()
{
    int arr[] = {5, 4, 7, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr, n);
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

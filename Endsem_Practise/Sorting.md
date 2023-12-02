# Sorting methods:
---
## 1. [Insertion Sort](https://github.com/vinitkesh/PD_Lab/blob/main/Endsem_Practise/Sorting/insertion.c) O(n^2)
   1. take i from 0 to n-1
   2. j from i-1 to 0 and compare arr[j] with key
   3. until arr[j] is greater than key, shift it to the right
   ![insertion sort](https://media.geeksforgeeks.org/wp-content/uploads/insertionsort.png)
---
## 2. [Selection Sort](https://github.com/vinitkesh/PD_Lab/blob/main/Endsem_Practise/Sorting/selection.c) O(n^2)
      i: 1 to n-1
      Find min element from i+1 to n-1 
      And replace it with arr[i]
      i++
   ![Selection sort gfg](https://media.geeksforgeeks.org/wp-content/uploads/20230526165200/3.webp)
---
## 3. [Merge Sort]() O(nlogn) 
   - Divide and conquer algorithm
   - Has 2 important functions: merge and merge sort
   ### Mergesort(arr,l,r)
         if(l<r)
            mergesort(arr,l,m)
            mergesort(arr,m+1,r)
            merge(arr,l,m,r)
   ### Merge
      - Create temp arrays L[n1] and R[n2] and copy the data
      - i,j-0
         k = l;
          while (i <n1 && j < n2) {
              if (L[i] <= R[j]) {
                  arr[k] = L[i];
                  i++;
              }
              else {
                  arr[k] = R[j];
                  j++;
              }
              k++;
          }
      - paste left out of the bigger array(L or R) in arr
---
## 4. [Quick Sort]()
---
## 5. [Heap Sort]()
---

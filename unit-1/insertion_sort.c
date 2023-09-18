// https://youtu.be/XBfH1Qy1JGY

#include <stdio.h>

void printArray(int len, int arr[len]){
    for (int i=0; i < len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main(){
    // insertion sort
    int arr[5] = {5, 3, 2, 4, 1};
    printf("Unsorted array: ");
    printArray(5, arr);
    int len = 5;

    for (int i=1; i < len; i++){
        int current = arr[i];
        int j = i-1;
        while (arr[j] > current && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }

    // print array
    printf("Sorted array: ");
    printArray(5, arr);
}
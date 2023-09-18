// https://youtu.be/ZHCP9vFOJiU

#include <stdio.h>

void main(){
    // binary search requires a sorted array
    int arr[5] = {1, 2, 3, 4, 5};
    int start = 0;
    int end = 4;

    int search = 5;
    int found = 0;  // 0 = false, 1 = true

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == search){
            printf("Found at index %d\n", mid);
            found = 1;
            break;
        }
        else if (arr[mid] > search){
            end = mid - 1;
        }
        else if (arr[mid] < search){
            start = mid + 1;
        }
        else {
            printf("Not found\n");
        }
    }
    

}
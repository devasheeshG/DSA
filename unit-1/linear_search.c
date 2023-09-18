// https://youtu.be/ZHCP9vFOJiU

#include <stdio.h>

void main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int search = 3;
    int found = 0;  // 0 = false, 1 = true

    for (int i=0; i < 5; i++){
        if (arr[i] == search){
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (found == 0){
        printf("Not found\n");
    }
}
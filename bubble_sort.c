// https://youtu.be/CkXjf6_8DLU

int main(){
    int arr[5] = {5, 3, 2, 4, 1};
    int len = 5;

    for (int i=0; i < len; i++){
        for (int j=0; j < len-1; j++){  // if we sort first 4 elements, 5th will be sorted automatically
            if (arr[j] > arr[j+1]){
                // swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        // print array
        printf("Pass %d: ", i+1);
        for (int k=0; k < len; k++){
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}
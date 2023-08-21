// https://youtu.be/7QX_vwJMsL0
#include <stdio.h>

void printMatrix(int rows, int columns, int matrix[rows][columns]){
    // code to print any sized matrix
    for (int i=0; i < rows; i++){
        for (int j=0; j < columns; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void main(){
    printf("Matrix Multiplication\n");

    // rows x columns
    int mat1[2][3] = {
        {1, 2, 3},
        {2, 3, 4}
    };
    printf("Matrix 1 \n");
    printMatrix(2, 3, mat1);

    int mat2[3][2] = {
        {2, 3},
        {3, 2},
        {1, 2}
    };
    printf("Matrix 2 \n");
    printMatrix(3, 2, mat2);

    int result[2][2], sum=0;

    for (int i=0; i < 2; i++){  // for mat 1
        // at i=0, we get 1st row of mat 1
        for (int j=0; j < 3; j++){  // for mat 2
            // at j=0, we get 1st row of mat 2, but we need columns
            for (int k=0; k < 3; k++){
                // now we can access elements of mat 1 using i&j and mat 2 using j&k
                sum += mat1[i][k] * mat2[k][j];
            }
            result[i][j] = sum;
            sum=0;
        }
    }

    printf("Result Matrix \n");
    printMatrix(2, 2, result);
}
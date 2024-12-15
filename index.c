#include <stdio.h>
#include <stdbool.h>

void bubbleSort(float arr[], int arrLength) {
    for (int i = 0; i < arrLength - 1; i++) {
        for (int j = 0; j < arrLength - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int columns = 6;
    const int rows = 4;
    float startArray[24] = {
        10, 30, 10, 70, 65, 72,
        50, 72, 11, -49, -32, 18,
        98, -99, -12, 56, 65, 92,
        21, 86, 43, -45, 76, -98
    };
    float matrix[rows][columns] = {};
    float resultArr[columns] = {};

    for (int col = 0; col < columns; col++) {
        float product = 1;
        bool hasNegative = false;

        for (int row = 0; row < rows; row++) {
            if (matrix[row][col] < 0) {
                product *= matrix[row][col];
                hasNegative = true;
            }
        }

        if (hasNegative) {
            resultArr[col] = product;
        } else {
            resultArr[col] = 0;
        }
    }

    printf("Resultant array: ");
    for (int i = 0; i < columns; i++) {
        printf("%.1f ", resultArr[i]);
    }

    bubbleSort(resultArr, columns);
    printf("\n");
    for (int i = 0; i < columns; i++) {
        printf("%.1f ", resultArr[i]);
    }

    return 0;
}

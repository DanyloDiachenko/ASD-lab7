#include <stdio.h>
#include <stdbool.h>

#define ROWS 4
#define COLUMNS 6

void bubbleSort(float arr[], int arrLength)
{
    for (int i = 0; i < arrLength - 1; i++)
    {
        for (int j = 0; j < arrLength - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printMatrix(float matrix[ROWS][COLUMNS], bool visited[ROWS][COLUMNS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (visited[i][j])
            {
                printf("%6.1f ", matrix[i][j]);
            }
            else
            {
                printf("   x   ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void moveAndFill(float matrix[ROWS][COLUMNS], bool visited[ROWS][COLUMNS],
                 float startArray[], int *filledElements, int *currentRow, int *currentCol, int directionRow, int directionCol, int stepLimit)
{
    for (int step = 0; step < stepLimit; step++)
    {
        int newRow = *currentRow + directionRow;
        int newCol = *currentCol + directionCol;
        if (newRow < 0 || newRow >= ROWS || newCol < 0 || newCol >= COLUMNS || visited[newRow][newCol])
        {
            break;
        }
        *currentRow = newRow;
        *currentCol = newCol;
        matrix[*currentRow][*currentCol] = startArray[(*filledElements)++];
        visited[*currentRow][*currentCol] = true;
        printMatrix(matrix, visited);
    }
}

int main()
{
    float startArray[ROWS * COLUMNS] = {
        10, 30, 10, 70, 65, 72,
        50, 72, 11, -49, -32, 18,
        98, -99, -12, 56, 65, 92,
        21, 86, 43, -45, 76, -98};
    float matrix[ROWS][COLUMNS] = {0};
    float resultArr[COLUMNS] = {};
    bool visited[ROWS][COLUMNS] = {false};
    int row = 2;
    int col = 4;
    int filled = 0;

    matrix[row][col] = startArray[filled++];
    visited[row][col] = true;
    printMatrix(matrix, visited);

    moveAndFill(matrix, visited, startArray, &filled, &row, &col, 0, -1, 3);
    moveAndFill(matrix, visited, startArray, &filled, &row, &col, -1, 0, 1);
    moveAndFill(matrix, visited, startArray, &filled, &row, &col, 0, 1, COLUMNS - col - 1);
    moveAndFill(matrix, visited, startArray, &filled, &row, &col, 1, 0, ROWS - row - 1);
    moveAndFill(matrix, visited, startArray, &filled, &row, &col, 0, -1, col);
    moveAndFill(matrix, visited, startArray, &filled, &row, &col, -1, 0, row);
    moveAndFill(matrix, visited, startArray, &filled, &row, &col, 0, 1, COLUMNS - col - 1);

    for (int col = 0; col < COLUMNS; col++)
    {
        float product = 1.0;
        bool hasNegative = false;

        for (int row = 0; row < ROWS; row++)
        {
            if (matrix[row][col] < 0)
            {
                product *= matrix[row][col];
                hasNegative = true;
            }
        }

        resultArr[col] = hasNegative ? product : 0;
    }

    printf("Resultant array: ");
    for (int i = 0; i < COLUMNS; i++)
    {
        printf("%.1f ", resultArr[i]);
    }

    bubbleSort(resultArr, COLUMNS);
    printf("\nSorted array: ");
    for (int i = 0; i < COLUMNS; i++)
    {
        printf("%.1f ", resultArr[i]);
    }

    return 0;
}

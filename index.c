#include <stdio.h>
#include <stdbool.h>

#define ROWS 4
#define COLUMNS 6

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

int main()
{
    float startArray[ROWS * COLUMNS] = {
        10, 30, 10, 70, 65, 72,
        50, 72, 11, -49, -32, 18,
        98, -99, -12, 56, 65, 92,
        21, 86, 43, -45, 76, -98};
    float matrix[ROWS][COLUMNS] = {0};
    bool visited[ROWS][COLUMNS] = {false};

    int row = 2, col = 4; // Начальная позиция: 3-й ряд, 5-й столбец
    int filled = 0;       // Личильник заполненных клеток

    // 1. ТРИ шага влево
    for (int i = 0; i < 4 && col >= 0 && !visited[row][col]; i++)
    {
        matrix[row][col] = startArray[filled++];
        visited[row][col] = true;
        printf("Step %d:\n", filled);
        printMatrix(matrix, visited);
        col--;
    }

    // 2. ОДИН шаг вверх
    if (row > 0 && !visited[row - 1][col + 1])
    {          // Убедиться, что можно подняться вверх
        row--; // Поднимаемся на одну клетку вверх
        col++; // Корректируем позицию для последующего движения вправо
        matrix[row][col] = startArray[filled++];
        visited[row][col] = true;
        printf("Step %d:\n", filled);
        printMatrix(matrix, visited);
    }

    // 3. ВПРАВО до упора
    while (col < COLUMNS - 1 && !visited[row][col + 1])
    {
        col++; // Двигаемся вправо
        matrix[row][col] = startArray[filled++];
        visited[row][col] = true;
        printf("Step %d:\n", filled);
        printMatrix(matrix, visited);
    }

    // 4. ВНИЗ до упора
    while (row < ROWS - 1 && !visited[row + 1][col])
    {
        row++; // Двигаемся вниз
        matrix[row][col] = startArray[filled++];
        visited[row][col] = true;
        printf("Step %d:\n", filled);
        printMatrix(matrix, visited);
    }

    // 6. ВЛЕВО до упора
    while (col > 0 && !visited[row][col - 1])
    {
        col--; // Двигаемся влево
        matrix[row][col] = startArray[filled++];
        visited[row][col] = true;
        printf("Step %d:\n", filled);
        printMatrix(matrix, visited);
    }

    // 7. ВВЕРХ до упора
    while (row > 0 && !visited[row - 1][col])
    {
        row--; // Двигаемся вверх
        matrix[row][col] = startArray[filled++];
        visited[row][col] = true;
        printf("Step %d:\n", filled);
        printMatrix(matrix, visited);
    }

    // 8. ВПРАВО до упора
    while (col < COLUMNS - 1 && !visited[row][col + 1])
    {
        col++; // Двигаемся вправо
        matrix[row][col] = startArray[filled++];
        visited[row][col] = true;
        printf("Step %d:\n", filled);
        printMatrix(matrix, visited);
    }

    return 0;
}

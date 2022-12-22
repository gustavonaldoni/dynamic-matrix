#include <stdlib.h>
#include "matrix.h"

void CreateIntegerMatrix(IntegerMatrix *matrix, int lines, int columns)
{
    int *content = NULL;

    if (lines <= 0)
        lines = 1;

    if (columns <= 0)
        columns = 1;

    content = (int *)malloc(lines * columns * sizeof(int));

    if (content == NULL)
        exit(1);

    matrix->content = content;
}

void SetValueOnIntegerMatrix(IntegerMatrix *matrix, int i, int j, int newValue)
{
    int correctIndex = 0;
    correctIndex = i * matrix->lines + j * matrix->columns;

    matrix->content[correctIndex] = newValue;
}

void ZeroIntegerMatrix(IntegerMatrix *matrix)
{
    int i, j;

    for (i = 0; i < matrix->lines; i++)
    {
        for (j = 0; j < matrix->columns; j++)
        {
            SetValueOnIntegerMatrix(matrix, i, j, 0);
        }
    }
}

void DestroyIntegerMatrix(IntegerMatrix *matrix)
{
    ZeroIntegerMatrix(matrix);
    free(matrix->content);
    matrix->content = NULL;
}
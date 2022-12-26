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

    matrix->lines = lines;
    matrix->columns = columns;
    matrix->content = content;
}

void DestroyIntegerMatrix(IntegerMatrix *matrix)
{
    ZeroIntegerMatrix(matrix);
    matrix->lines = 0;
    matrix->columns = 0;
    free(matrix->content);
    matrix->content = NULL;
}

int SetValueOnIntegerMatrix(IntegerMatrix *matrix, int i, int j, int newValue)
{
    int correctIndex = 0;

    if (i >= 0 && i <= matrix->lines - 1 &&
        j >= 0 && j <= matrix->columns - 1)
    {
        correctIndex = i * matrix->columns + j;
        matrix->content[correctIndex] = newValue;

        return 1;
    }

    return 0;
}

int *GetValueFromIntegerMatrix(IntegerMatrix *matrix, int i, int j)
{
    int *value = NULL;
    int correctIndex = 0;

    if (i >= 0 && i <= matrix->lines - 1 &&
        j >= 0 && j <= matrix->columns - 1)
    {
        correctIndex = i * matrix->columns + j;
        value = &(matrix->content[correctIndex]);
    }

    return value;
}

void ZeroIntegerMatrix(IntegerMatrix *matrix)
{
    int i, j;

    for (i = 0; i < matrix->lines; i++)
        for (j = 0; j < matrix->columns; j++)
            SetValueOnIntegerMatrix(matrix, i, j, 0);
}

void CreateIdentityIntegerMatrix(IntegerMatrix *matrix, int size)
{
    int i, j;

    CreateIntegerMatrix(matrix, size, size);

    for (i = 0; i < matrix->lines; i++)
    {
        for (j = 0; j < matrix->columns; j++)
        {
            if (i == j)
                SetValueOnIntegerMatrix(matrix, i, j, 1);
            else
                SetValueOnIntegerMatrix(matrix, i, j, 0);
        }
    }
}

int IsIdentity(IntegerMatrix *matrix)
{
    int i, j;

    if (matrix->lines != matrix->columns)
        return 0;

    for (i = 0; i < matrix->lines; i++)
    {
        for (j = 0; j < matrix->columns; j++)
        {
            if (i == j)
            {
                if (*GetValueFromIntegerMatrix(matrix, i, j) != 1)
                    return 0;
            }
            else
            {
                if (*GetValueFromIntegerMatrix(matrix, i, j) != 0)
                    return 0;
            }
        }
    }

    return 1;
}

int IsSquare(IntegerMatrix *matrix)
{
    return matrix->lines == matrix->columns &&
           matrix->lines != 0 && matrix->columns != 0;
}

int SumIntegerMatrices(IntegerMatrix *matrix1, IntegerMatrix *matrix2, IntegerMatrix *result)
{
    int i, j;
    int sum;

    if (matrix1->lines != matrix2->lines ||
        matrix1->columns != matrix2->columns)
    {
        result = NULL;
        return 0;
    }

    result->lines = matrix1->lines;
    result->columns = matrix1->columns;

    for (i = 0; i < result->lines; i++)
    {
        for (j = 0; j < result->columns; j++)
        {
            sum = *GetValueFromIntegerMatrix(matrix1, i, j) + *GetValueFromIntegerMatrix(matrix2, i, j);
            SetValueOnIntegerMatrix(result, i, j, sum);
        }
    }

    return 1;
}

int MultiplyMatrixByConstant(IntegerMatrix *matrix, IntegerMatrix *result, int constant)
{
    int i, j;
    int newValue;

    if (result->lines != matrix->lines ||
        result->columns != matrix->columns)
        return 0;

    for (i = 0; i < result->lines; i++)
    {
        for (j = 0; j < result->columns; j++)
        {
            newValue = *GetValueFromIntegerMatrix(matrix, i, j) * constant;
            SetValueOnIntegerMatrix(result, i, j, newValue);
        }
    }

    return 1;
}

int MultiplyIntegerMatrices(IntegerMatrix *matrix1, IntegerMatrix *matrix2, IntegerMatrix *result)
{
    return 1;
}
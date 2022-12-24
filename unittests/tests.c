#include <stdlib.h>
#include <time.h>
#include "criterion/criterion.h"
#include "matrix.h"

Test(integerMatrixTests, create)
{
    IntegerMatrix matrix = {0};
    matrix.content = NULL;

    CreateIntegerMatrix(&matrix, 5, 10);
    cr_expect(matrix.content != NULL);
    DestroyIntegerMatrix(&matrix);
}

Test(integerMatrixTests, destroy)
{
    IntegerMatrix matrix = {0};

    CreateIntegerMatrix(&matrix, 54, 2);

    DestroyIntegerMatrix(&matrix);
    cr_expect(matrix.content == NULL);
}

Test(integerMatrixTests, setValue)
{
    int i, j;
    IntegerMatrix matrix = {0};

    CreateIntegerMatrix(&matrix, 3, 3);

    for (i = 0; i < matrix.lines; i++)
        for (j = 0; j < matrix.columns; j++)
            SetValueOnIntegerMatrix(&matrix, i, j, i + j);

    for (i = 0; i < matrix.lines; i++)
        for (j = 0; j < matrix.columns; j++)
            cr_expect(*GetValueFromIntegerMatrix(&matrix, i, j) == i + j);

    DestroyIntegerMatrix(&matrix);
}

Test(integerMatrixTests, getValue)
{
    int i, j;
    IntegerMatrix matrix = {0};

    CreateIntegerMatrix(&matrix, 45, 33);

    for (i = 0; i < matrix.lines; i++)
        for (j = 0; j < matrix.columns; j++)
            SetValueOnIntegerMatrix(&matrix, i, j, i * j);

    for (i = 0; i < matrix.lines; i++)
        for (j = 0; j < matrix.columns; j++)
            cr_expect(*GetValueFromIntegerMatrix(&matrix, i, j) == i * j);

    DestroyIntegerMatrix(&matrix);
}

Test(integerMatrixTests, zero)
{
    int i, j;
    IntegerMatrix matrix = {0};

    CreateIntegerMatrix(&matrix, 54, 2);
    ZeroIntegerMatrix(&matrix);

    for (i = 0; i < matrix.lines; i++)
        for (j = 0; j < matrix.columns; j++)
            cr_expect(*GetValueFromIntegerMatrix(&matrix, i, j) == 0);

    DestroyIntegerMatrix(&matrix);
}

Test(integerMatrixTests, createIdentity)
{
    int i, j;
    IntegerMatrix matrix = {0};

    CreateIdentityIntegerMatrix(&matrix, 22);

    srand(time(NULL));

    for (i = 0; i < matrix.lines; i++)
    {
        for (j = 0; j < matrix.columns; j++)
        {
            if (i == j)
                cr_expect(*GetValueFromIntegerMatrix(&matrix, i, j) == 1);
            else
                cr_expect(*GetValueFromIntegerMatrix(&matrix, i, j) == 0);
        }
    }

    DestroyIntegerMatrix(&matrix);
}

Test(integerMatrixTests, sum)
{
    int i, j;
    IntegerMatrix matrix1 = {0}, matrix2 = {0}, result = {0};

    CreateIntegerMatrix(&matrix1, 23, 45);
    CreateIntegerMatrix(&matrix2, 23, 45);

    for (i = 0; i < matrix1.lines; i++)
    {
        for (j = 0; j < matrix1.columns; j++)
        {
            SetValueOnIntegerMatrix(&matrix1, i, j, rand() % 10);
            SetValueOnIntegerMatrix(&matrix2, i, j, rand() % 10);
        }
    }

    for (i = 0; i < result.lines; i++)
        for (j = 0; j < result.columns; j++)
            cr_expect(*GetValueFromIntegerMatrix(&result, i, j) == *GetValueFromIntegerMatrix(&matrix1, i, j) + *GetValueFromIntegerMatrix(&matrix2, i, j));

    DestroyIntegerMatrix(&matrix1);
    DestroyIntegerMatrix(&matrix2);
    DestroyIntegerMatrix(&result);
}

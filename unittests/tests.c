#include <stdlib.h>
#include <time.h>
#include "criterion/criterion.h"
#include "matrix.h"

Test(integerMatrixTests, create)
{
    IntegerMatrix matrix1 = {0}, matrix2 = {0}, matrix3 = {0};
    matrix1.content = NULL;
    matrix2.content = NULL;
    matrix3.content = NULL;

    CreateIntegerMatrix(&matrix1, 5, 10);
    CreateIntegerMatrix(&matrix2, -1, 0);
    CreateIntegerMatrix(&matrix3, -56456, -768);

    cr_expect(matrix1.content != NULL);
    cr_expect(matrix1.lines == 5);
    cr_expect(matrix1.columns == 10);

    cr_expect(matrix2.content != NULL);
    cr_expect(matrix2.lines == 1);
    cr_expect(matrix2.columns == 1);

    cr_expect(matrix3.content != NULL);
    cr_expect(matrix3.lines == 1);
    cr_expect(matrix3.columns == 1);

    DestroyIntegerMatrix(&matrix1);
    DestroyIntegerMatrix(&matrix2);
    DestroyIntegerMatrix(&matrix3);
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

Test(integerMatrixTests, isIdentity)
{
    IntegerMatrix matrix1 = {0}, matrix2 = {0}, matrix3 = {0}, matrix4 = {0};

    CreateIdentityIntegerMatrix(&matrix1, 5);
    CreateIdentityIntegerMatrix(&matrix2, 78);
    CreateIntegerMatrix(&matrix3, 21, 22);
    CreateIntegerMatrix(&matrix4, 4, 12);

    ZeroIntegerMatrix(&matrix4);

    cr_expect(IsIdentity(&matrix1) == 1);
    cr_expect(IsIdentity(&matrix2) == 1);
    cr_expect(IsIdentity(&matrix3) == 0);
    cr_expect(IsIdentity(&matrix4) == 0);

    DestroyIntegerMatrix(&matrix1);
    DestroyIntegerMatrix(&matrix2);
    DestroyIntegerMatrix(&matrix3);
    DestroyIntegerMatrix(&matrix4);
}

Test(integerMatrixTests, isSquare)
{
    IntegerMatrix matrix1 = {0}, matrix2 = {0}, matrix3 = {0}, matrix4 = {0};

    CreateIdentityIntegerMatrix(&matrix1, 12);
    CreateIdentityIntegerMatrix(&matrix2, 44);
    CreateIntegerMatrix(&matrix3, 21, 2);
    CreateIntegerMatrix(&matrix4, 4, 6);

    ZeroIntegerMatrix(&matrix3);

    cr_expect(IsSquare(&matrix1) == 1);
    cr_expect(IsSquare(&matrix2) == 1);
    cr_expect(IsSquare(&matrix3) == 0);
    cr_expect(IsSquare(&matrix4) == 0);

    DestroyIntegerMatrix(&matrix1);
    DestroyIntegerMatrix(&matrix2);
    DestroyIntegerMatrix(&matrix3);
    DestroyIntegerMatrix(&matrix4);
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

Test(integerMatrixTests, multiplyConstant)
{
    int i, j;
    const int constant = 32;
    IntegerMatrix matrix1 = {0}, result = {0};

    CreateIntegerMatrix(&matrix1, 32, 12);
    CreateIntegerMatrix(&result, 32, 12);

    srand(time(NULL));

    for (i = 0; i < matrix1.lines; i++)
        for (j = 0; j < matrix1.columns; j++)
            SetValueOnIntegerMatrix(&matrix1, i, j, rand() % 10);

    MultiplyMatrixByConstant(&matrix1, &result, constant);

    for (i = 0; i < result.lines; i++)
        for (j = 0; j < result.columns; j++)
            cr_expect(*GetValueFromIntegerMatrix(&result, i, j) == *GetValueFromIntegerMatrix(&matrix1, i, j) * constant);

    DestroyIntegerMatrix(&matrix1);
    DestroyIntegerMatrix(&result);
}

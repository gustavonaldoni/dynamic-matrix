#include "criterion/criterion.h"
#include "matrix.h"

Test(integerMatrixTests, create)
{
    IntegerMatrix matrix;
    matrix.content = NULL;

    CreateIntegerMatrix(&matrix, 5, 10);
    cr_expect(matrix.content != NULL);
    DestroyIntegerMatrix(&matrix);
}

Test(integerMatrixTests, destroy)
{
    IntegerMatrix matrix;

    CreateIntegerMatrix(&matrix, 54, 2);
    cr_expect(matrix.content != NULL);

    DestroyIntegerMatrix(&matrix);
    cr_expect(matrix.content == NULL);
}

Test(integerMatrixTests, zero)
{
    int i, j;

    IntegerMatrix matrix;

    CreateIntegerMatrix(&matrix, 54, 2);
    ZeroIntegerMatrix(&matrix);

    for (i = 0; i < matrix.lines; i++)
    {
        for (j = 0; j < matrix.columns; j++)
        {
            cr_expect(*GetValueFromIntegerMatrix(&matrix, i, j) == 0);
        }
    }

    DestroyIntegerMatrix(&matrix);
}
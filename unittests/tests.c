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
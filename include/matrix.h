typedef struct
{
    int lines, columns;
    int *content;
} IntegerMatrix;

void CreateIntegerMatrix(IntegerMatrix *, int, int);
void DestroyIntegerMatrix(IntegerMatrix *);
int SetValueOnIntegerMatrix(IntegerMatrix *, int, int, int);
int *GetValueFromIntegerMatrix(IntegerMatrix *, int, int);
void ZeroIntegerMatrix(IntegerMatrix *);

void CreateIdentityIntegerMatrix(IntegerMatrix *, int);
int IsIdentity(IntegerMatrix *);
int IsSquare(IntegerMatrix *);
int SumIntegerMatrices(IntegerMatrix *, IntegerMatrix *, IntegerMatrix *);
void MultiplyMatrixByConstant(IntegerMatrix *, IntegerMatrix*, int);
int MultiplyIntegerMatrices(IntegerMatrix *, IntegerMatrix *, IntegerMatrix *);
typedef struct
{
    int lines, columns;
    int *content;
} IntegerMatrix;

void CreateIntegerMatrix(IntegerMatrix *, int, int);
void ZeroIntegerMatrix(IntegerMatrix *);
void SetValueOnIntegerMatrix(IntegerMatrix *, int, int, int);
void DestroyIntegerMatrix(IntegerMatrix *);

//ADD
matrixType MatrixADT::add(matrixType M1, matrixType M2)
{
    int i, j;

    for (i = 0; i < M1.matDimension; i++)
        for (j = 0; j < M1.matDimension; j++)
            resultMatrix.matValues[i][j] = M1.matValues[i][j] + M2.matValues[i][j];

    return resultMatrix;
}

//SUBTRACT
matrixType MatrixADT::subtract(matrixType M1, matrixType M2)
{
    int i, j;

    for (i = 0; i < M1.matDimension; i++)
        for (j = 0; j < M1.matDimension; j++)
            resultMatrix.matValues[i][j] = M1.matValues[i][j] - M2.matValues[i][j];

    return resultMatrix;
}

//MULTIPLY
matrixType MatrixADT::multiply(matrixType M1, matrixType M2)
{
    int i, j, k, sum = 0;

    for (i = 0; i < M1.matDimension; i++)
    {
        for (j = 0; j < M1.matDimension; j++)
        {
            for (k = 0; k < M1.matDimension; k++)
                sum = sum + M1.matValues[i][k] * M2.matValues[k][j];

            resultMatrix.matValues[i][j] = sum;
            sum = 0;
        }
    }
    return resultMatrix;
}

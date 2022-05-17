#include "ProcessFunction.h"
#include "matrix.h"

//void ProcessFunctionInit()
//{
//}

/* MAIN FUNCTION */
void ProcessFunction(double *input1, double *input2, double *output, double *result)
{
    Matrix matrixInput1, matrixInput2, matrixOutput;
    *result = 0;
    //int8t setMatrix(Matrix *a, float64t *data, uint16t nrows, uint16t ncols);
    if(0 != setMatrix(&matrixInput1, input1, 2, 1))
    {
        *result = 1;
        return;
    }
    if(0 != setMatrix(&matrixInput2, input2, 2, 1))
    {
        *result = 1;
        return;
    }
    if(0 != setMatrix(&matrixOutput, output, 2, 1))
    {
        *result = 1;
        return;
    }
    //int8t sumMatrix(Matrix const *a, Matrix const *b, Matrix *s);
    sumMatrix(&matrixInput1, &matrixInput2, &matrixOutput);
	//output[0] = input1[0] + input2[0];
    //output[1] = input1[1] + input2[1];
}
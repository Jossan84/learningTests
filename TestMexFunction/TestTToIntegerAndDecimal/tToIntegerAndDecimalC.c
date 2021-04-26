#include "mex.h"
//#include <math.h>

int tToIntegerAndDecimal(double t, int16_T maxInteger, int16_T *tInt, double *tDec)
{
/*    double tTr = min(t % (2.F * (double)maxInteger), (2.F * (double)maxInteger - t) % (2.F * (double)maxInteger));
    double tIntAux = max((double)maxInteger - (int16_T)((double)(maxInteger + 1) - tTr), 0.F);
    *tDec = tTr - tIntAux;
    *tInt = (int16_T)tIntAux;
*/
    return 0;
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    // Declarations at the top of the function
    double *p_t = NULL;
    int16_T *p_maxInteger = NULL;
    int16_T *p_tInt = NULL;
    double *p_tDec = NULL;

    mexPrintf("%d inputs and %d outputs\n", nrhs, nlhs);
    
    // Check number of inputs
    if(2 != nrhs)
    {
        mexErrMsgTxt("Wrong number of inputs\n");
        return;
    }
    
    // Check inputs types
    if(!mxIsClass(prhs[0], "double"))
    {
        mexErrMsgTxt("First input argument wrong type\n");
        return;
    }
    
    if(!mxIsClass(prhs[1], "int16"))
    {
        mexErrMsgTxt("Second input argument wrong type\n");
        return;
    }
    
    // Check number of outputs
    if(2 != nlhs)
    {
        mexErrMsgTxt("Wrong number of outputs\n");
        return;
    }
    
    // Point input variables
    p_t = (double *)mxGetData(prhs[0]);
    p_maxInteger = (int16_T *)mxGetData(prhs[1]);
    
    // Point output variables
    //mxArray *mxCreateNumericMatrix(mwSize m, mwSize n, mxClassID classid, mxComplexity ComplexFlag)
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT16_CLASS, mxREAL);
    plhs[1] = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
    p_tInt = (int16_T *)mxGetData(plhs[0]);
    p_tDec = (double *)mxGetData(plhs[1]);
    
    // Function call
    if(0 != tToIntegerAndDecimal(*p_t, *p_maxInteger, p_tInt, p_tDec))
    {
        mexErrMsgTxt("Error tToIntegerAndDecimal\n");
    }
}
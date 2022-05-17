#ifndef _PROCESS_FUNCTION_H_
#define _PROCESS_FUNCTION_H_

#include "rtwtypes.h"

void ProcessFunctionInit(void);
// void ProcessFunction(const double *input1, const double *input2, double *output, double *result);
void ProcessFunction(const real_T *input1, const real_T *input2, real_T *output, real_T *result);
#endif


/*
 * Code generation for system model 'sumDouble'
 *
 * Model                      : sumDouble
 * Model version              : 1.9
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Thu Jul 02 18:31:26 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "sumDouble.h"
#include "sumDouble_private.h"

/* Output and update for referenced model: 'sumDouble' */
void sumDouble(const real_T *rtu_num1, const real_T *rtu_num2, real_T
               *rty_result)
{
  /* Sum: '<Root>/Add' */
  *rty_result = *rtu_num1 + *rtu_num2;
}

/* Model initialize function */
void sumDouble_initialize(const char_T **rt_errorStatus, RT_MODEL_sumDouble_T *
  const sumDouble_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(sumDouble_M, rt_errorStatus);
}

/*
 * TestSFunctionLib.c
 *
 * Code generation for model "TestSFunctionLib".
 *
 * Model version              : 1.32
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Tue Jun 23 18:20:05 2020
 *
 * Target selection: rti1401.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TestSFunctionLib_trc_ptr.h"
#include "TestSFunctionLib.h"
#include "TestSFunctionLib_private.h"

/* Block signals (auto storage) */
B_TestSFunctionLib_T TestSFunctionLib_B;

/* Block states (auto storage) */
DW_TestSFunctionLib_T TestSFunctionLib_DW;

/* Real-time model */
RT_MODEL_TestSFunctionLib_T TestSFunctionLib_M_;
RT_MODEL_TestSFunctionLib_T *const TestSFunctionLib_M = &TestSFunctionLib_M_;

/* Model output function */
void TestSFunctionLib_output(void)
{
  /* S-Function (SfcnProcessFunction): '<Root>/S-Function' */
  ProcessFunction( (real_T*)&TestSFunctionLib_P.Constant_Value[0], (real_T*)
                  &TestSFunctionLib_P.Constant1_Value[0],
                  &TestSFunctionLib_B.SFunction_o1[0],
                  &TestSFunctionLib_B.SFunction_o2);
}

/* Model update function */
void TestSFunctionLib_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++TestSFunctionLib_M->Timing.clockTick0)) {
    ++TestSFunctionLib_M->Timing.clockTickH0;
  }

  TestSFunctionLib_M->Timing.taskTime0 = TestSFunctionLib_M->Timing.clockTick0 *
    TestSFunctionLib_M->Timing.stepSize0 +
    TestSFunctionLib_M->Timing.clockTickH0 *
    TestSFunctionLib_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void TestSFunctionLib_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)TestSFunctionLib_M, 0,
                sizeof(RT_MODEL_TestSFunctionLib_T));
  TestSFunctionLib_M->Timing.stepSize0 = 1.0;

  /* block I/O */
  (void) memset(((void *) &TestSFunctionLib_B), 0,
                sizeof(B_TestSFunctionLib_T));

  /* states (dwork) */
  (void) memset((void *)&TestSFunctionLib_DW, 0,
                sizeof(DW_TestSFunctionLib_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    TestSFunctionLib_rti_init_trc_pointers();
  }
}

/* Model terminate function */
void TestSFunctionLib_terminate(void)
{
  /* (no terminate code required) */
}

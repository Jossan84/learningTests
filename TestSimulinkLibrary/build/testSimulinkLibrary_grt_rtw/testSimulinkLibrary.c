/*
 * testSimulinkLibrary.c
 *
 * Code generation for model "testSimulinkLibrary".
 *
 * Model version              : 1.13
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Thu Jul 02 18:31:31 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testSimulinkLibrary.h"
#include "testSimulinkLibrary_private.h"

/* Block states (auto storage) */
DW_testSimulinkLibrary_T testSimulinkLibrary_DW;

/* Real-time model */
RT_MODEL_testSimulinkLibrary_T testSimulinkLibrary_M_;
RT_MODEL_testSimulinkLibrary_T *const testSimulinkLibrary_M =
  &testSimulinkLibrary_M_;

/* Model step function */
void testSimulinkLibrary_step(void)
{
  /* local block i/o variables */
  real_T rtb_Model;

  /* ModelReference: '<Root>/Model' */
  sumDouble(&testSimulinkLibrary_P.Constant_Value,
            &testSimulinkLibrary_P.Constant1_Value, &rtb_Model);

  /* Matfile logging */
  rt_UpdateTXYLogVars(testSimulinkLibrary_M->rtwLogInfo,
                      (&testSimulinkLibrary_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(testSimulinkLibrary_M)!=-1) &&
        !((rtmGetTFinal(testSimulinkLibrary_M)-
           testSimulinkLibrary_M->Timing.taskTime0) >
          testSimulinkLibrary_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(testSimulinkLibrary_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++testSimulinkLibrary_M->Timing.clockTick0)) {
    ++testSimulinkLibrary_M->Timing.clockTickH0;
  }

  testSimulinkLibrary_M->Timing.taskTime0 =
    testSimulinkLibrary_M->Timing.clockTick0 *
    testSimulinkLibrary_M->Timing.stepSize0 +
    testSimulinkLibrary_M->Timing.clockTickH0 *
    testSimulinkLibrary_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void testSimulinkLibrary_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)testSimulinkLibrary_M, 0,
                sizeof(RT_MODEL_testSimulinkLibrary_T));
  rtmSetTFinal(testSimulinkLibrary_M, 10.0);
  testSimulinkLibrary_M->Timing.stepSize0 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    testSimulinkLibrary_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(testSimulinkLibrary_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(testSimulinkLibrary_M->rtwLogInfo, (NULL));
    rtliSetLogT(testSimulinkLibrary_M->rtwLogInfo, "tout");
    rtliSetLogX(testSimulinkLibrary_M->rtwLogInfo, "");
    rtliSetLogXFinal(testSimulinkLibrary_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(testSimulinkLibrary_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(testSimulinkLibrary_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(testSimulinkLibrary_M->rtwLogInfo, 0);
    rtliSetLogDecimation(testSimulinkLibrary_M->rtwLogInfo, 1);
    rtliSetLogY(testSimulinkLibrary_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(testSimulinkLibrary_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(testSimulinkLibrary_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&testSimulinkLibrary_DW, 0,
                sizeof(DW_testSimulinkLibrary_T));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model' */
  sumDouble_initialize(rtmGetErrorStatusPointer(testSimulinkLibrary_M),
                       &(testSimulinkLibrary_DW.Model_DWORK1.rtm));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(testSimulinkLibrary_M->rtwLogInfo, 0.0,
    rtmGetTFinal(testSimulinkLibrary_M), testSimulinkLibrary_M->Timing.stepSize0,
    (&rtmGetErrorStatus(testSimulinkLibrary_M)));
}

/* Model terminate function */
void testSimulinkLibrary_terminate(void)
{
  /* (no terminate code required) */
}

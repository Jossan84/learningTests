/*
 * TestSFunctionLib.h
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

#ifndef RTW_HEADER_TestSFunctionLib_h_
#define RTW_HEADER_TestSFunctionLib_h_
#include <string.h>
#ifndef TestSFunctionLib_COMMON_INCLUDES_
# define TestSFunctionLib_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ProcessFunction.h"
#endif                                 /* TestSFunctionLib_COMMON_INCLUDES_ */

#include "TestSFunctionLib_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T SFunction_o1[2];              /* '<Root>/S-Function' */
  real_T SFunction_o2;                 /* '<Root>/S-Function' */
} B_TestSFunctionLib_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData[4];
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_TestSFunctionLib_T;

/* Parameters (auto storage) */
struct P_TestSFunctionLib_T_ {
  real_T Constant_Value[2];            /* Expression: [1; 2]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value[2];           /* Expression: [3, 4]
                                        * Referenced by: '<Root>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_TestSFunctionLib_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_TestSFunctionLib_T TestSFunctionLib_P;

/* Block signals (auto storage) */
extern B_TestSFunctionLib_T TestSFunctionLib_B;

/* Block states (auto storage) */
extern DW_TestSFunctionLib_T TestSFunctionLib_DW;

/* Model entry point functions */
extern void TestSFunctionLib_initialize(void);
extern void TestSFunctionLib_output(void);
extern void TestSFunctionLib_update(void);
extern void TestSFunctionLib_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TestSFunctionLib_T *const TestSFunctionLib_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TestSFunctionLib'
 * '<S1>'   : 'TestSFunctionLib/RTI Data'
 * '<S2>'   : 'TestSFunctionLib/RTI Data/RTI Data Store'
 * '<S3>'   : 'TestSFunctionLib/RTI Data/RTI Data Store/RTI Data Store'
 * '<S4>'   : 'TestSFunctionLib/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                                 /* RTW_HEADER_TestSFunctionLib_h_ */

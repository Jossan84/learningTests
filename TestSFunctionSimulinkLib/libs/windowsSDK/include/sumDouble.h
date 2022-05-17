/*
 * Code generation for system model 'sumDouble'
 * For more details, see corresponding source file sumDouble.c
 *
 */

#ifndef RTW_HEADER_sumDouble_h_
#define RTW_HEADER_sumDouble_h_
#ifndef sumDouble_COMMON_INCLUDES_
# define sumDouble_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* sumDouble_COMMON_INCLUDES_ */

#include "sumDouble_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "model_reference_types.h"

/* Real-time Model Data Structure */
struct tag_RTM_sumDouble_T {
  const char_T **errorStatus;
};

typedef struct {
  RT_MODEL_sumDouble_T rtm;
} MdlrefDW_sumDouble_T;

/* Model reference registration function */
extern void sumDouble_initialize(const char_T **rt_errorStatus,
  RT_MODEL_sumDouble_T *const sumDouble_M);
extern void sumDouble(const real_T *rtu_num1, const real_T *rtu_num2, real_T
                      *rty_result);

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
 * '<Root>' : 'sumDouble'
 * '<S1>'   : 'sumDouble/RTI Data'
 * '<S2>'   : 'sumDouble/RTI Data/RTI Data Store'
 * '<S3>'   : 'sumDouble/RTI Data/RTI Data Store/RTI Data Store'
 * '<S4>'   : 'sumDouble/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                                 /* RTW_HEADER_sumDouble_h_ */

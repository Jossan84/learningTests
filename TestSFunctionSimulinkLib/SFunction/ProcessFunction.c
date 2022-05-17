#include "ProcessFunction.h"
#include "sumDouble.h"
#include "sumDouble_private.h"


/* Block states (auto storage) for system '<Root>' */
typedef struct {
  MdlrefDW_sumDouble_T Model_DWORK1;   /* '<Root>/Model' */
} DW_processFunctions_T;

/* Block states (default storage) */
static DW_processFunctions_T processFunctions_DW;/* Observable states */

/* Real-time model */
static RT_MODEL_sumDouble_T processFunctions_M_;
static RT_MODEL_sumDouble_T *const processFunctions_M = &processFunctions_M_;/* Real-time model */
    

void ProcessFunctionInit(void)
{         
    
    /* Model Initialize function for ModelReference Block: '<Root>/Model' */
    sumDouble_initialize(rtmGetErrorStatusPointer(processFunctions_M),
                         &(processFunctions_DW.Model_DWORK1.rtm)); 
}

/* MAIN FUNCTION */
//void ProcessFunction(const double *input1, const double *input2, double *output, double *result)
void ProcessFunction(const real_T *input1,const real_T *input2, const real_T *output, real_T *result)
{
        
	/* ModelReference: '<Root>/Model' */
    sumDouble(input1, input2, result);
     
}
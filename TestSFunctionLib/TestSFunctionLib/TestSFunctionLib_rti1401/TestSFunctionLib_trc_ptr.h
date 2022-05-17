  /*********************** dSPACE target specific file *************************

   Header file TestSFunctionLib_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1401 7.7 (02-Nov-2016)
   Tue Jun 23 18:20:05 2020

   Copyright 2020, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_TestSFunctionLib_trc_ptr_h_
  #define RTI_HEADER_TestSFunctionLib_trc_ptr_h_
  /* Include the model header file. */
  #include "TestSFunctionLib.h"
  #include "TestSFunctionLib_private.h"

  #ifdef EXTERN_C
  #undef EXTERN_C
  #endif

  #ifdef __cplusplus
  #define EXTERN_C                       extern "C"
  #else
  #define EXTERN_C                       extern
  #endif

  /*
   *  Declare the global TRC pointers
   */
              EXTERN_C volatile  real_T *p_0_TestSFunctionLib_real_T_0;
              EXTERN_C volatile  real_T *p_1_TestSFunctionLib_real_T_0;

  /*
   *  Declare the general function for TRC pointer initialization
   */
  EXTERN_C void TestSFunctionLib_rti_init_trc_pointers(void);
   #endif                       /* RTI_HEADER_TestSFunctionLib_trc_ptr_h_ */

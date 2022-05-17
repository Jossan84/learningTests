/***************************************************************************

   Source file TestSFunctionLib_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1401 7.7 (02-Nov-2016)
   Tue Jun 23 18:20:05 2020

   Copyright 2020, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "TestSFunctionLib_trc_ptr.h"
#include "TestSFunctionLib.h"
#include "TestSFunctionLib_private.h"

/* Compiler options to turn off optimization. */
#if !defined(DS_OPTIMIZE_INIT_TRC_POINTERS)
#ifdef _MCCPPC

#pragma options -nOt -nOr -nOi -nOx

#endif

#ifdef __GNUC__

#pragma GCC optimize ("O0")

#endif

#ifdef _MSC_VER

#pragma optimize ("", off)

#endif
#endif

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_0_TestSFunctionLib_real_T_0 = NULL;
volatile real_T *p_1_TestSFunctionLib_real_T_0 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_TestSFunctionLib_real_T_0 = &TestSFunctionLib_B.SFunction_o1[0];
  p_1_TestSFunctionLib_real_T_0 = &TestSFunctionLib_P.Constant_Value[0];
}

void TestSFunctionLib_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}

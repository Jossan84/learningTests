
/*
 * User legacy code
*/

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif
        
real_T rad2Deg(real_T u)
{
    return(u * 57.295779513082323);
}


#ifndef _TYPES_H
#define _TYPES_H

#include <stdint.h>

#ifndef _STDINT_H

#define MINUINT8 0U
#define MINUINT16 0U
#define MINUINT32 0U
#define MINUINT64 0UL

#define MAXUINT8 255U
#define MAXUINT16 65535U
#define MAXUINT32 4294967295U
#define MAXUINT64 18446744073709551615UL

#define MININT8 -128
#define MININT16 -32768
#define MININT32 -2147483648
#define MININT64 -9223372036854775808L

#define MAXINT8 127
#define MAXINT16 32767
#define MAXINT32 2147483647
#define MAXINT64 9223372036854775807L

typedef unsigned char uint8t;
typedef unsigned short int uint16t;
typedef unsigned int uint32t;
typedef unsigned long int uint64t;

typedef char int8t;
typedef short int int16t;
typedef int int32t;
typedef long int int64t;

typedef float float32t;
typedef double float64t;

#else//ifndef _STDINT_H

#define MINUINT8 UINT8_MIN
#define MINUINT16 UINT16_MIN
#define MINUINT32 UINT32_MIN
#define MINUINT64 UINT64_MIN

#define MAXUINT8 INT8_MAX
#define MAXUINT16 INT16_MAX
#define MAXUINT32 INT32_MAX
#define MAXUINT64 INT64_MAX

#define MININT8 INT8_MIN
#define MININT16 INT16_MIN
#define MININT32 INT32_MIN
#define MININT64 INT64_MIN

#define MAXINT8 INT8_MAX
#define MAXINT16 INT16_MAX
#define MAXINT32 INT32_MAX
#define MAXINT64 INT64_MAX

typedef unsigned char uint8t;
typedef unsigned short int uint16t;
typedef unsigned int uint32t;
typedef unsigned long int uint64t;

typedef char int8t;
typedef short int int16t;
typedef int int32t;
typedef long int int64t;

typedef float float32t;
typedef double float64t;

#endif//ifndef _STDINT_H

#endif

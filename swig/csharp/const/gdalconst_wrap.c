/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.12
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

#define SWIGCSHARP

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif



#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/* Support for throwing C# exceptions from C/C++. There are two types: 
 * Exceptions that take a message and ArgumentExceptions that take a message and a parameter name. */
typedef enum {
  SWIG_CSharpApplicationException,
  SWIG_CSharpArithmeticException,
  SWIG_CSharpDivideByZeroException,
  SWIG_CSharpIndexOutOfRangeException,
  SWIG_CSharpInvalidCastException,
  SWIG_CSharpInvalidOperationException,
  SWIG_CSharpIOException,
  SWIG_CSharpNullReferenceException,
  SWIG_CSharpOutOfMemoryException,
  SWIG_CSharpOverflowException,
  SWIG_CSharpSystemException
} SWIG_CSharpExceptionCodes;

typedef enum {
  SWIG_CSharpArgumentException,
  SWIG_CSharpArgumentNullException,
  SWIG_CSharpArgumentOutOfRangeException
} SWIG_CSharpExceptionArgumentCodes;

typedef void (SWIGSTDCALL* SWIG_CSharpExceptionCallback_t)(const char *);
typedef void (SWIGSTDCALL* SWIG_CSharpExceptionArgumentCallback_t)(const char *, const char *);

typedef struct {
  SWIG_CSharpExceptionCodes code;
  SWIG_CSharpExceptionCallback_t callback;
} SWIG_CSharpException_t;

typedef struct {
  SWIG_CSharpExceptionArgumentCodes code;
  SWIG_CSharpExceptionArgumentCallback_t callback;
} SWIG_CSharpExceptionArgument_t;

static SWIG_CSharpException_t SWIG_csharp_exceptions[] = {
  { SWIG_CSharpApplicationException, NULL },
  { SWIG_CSharpArithmeticException, NULL },
  { SWIG_CSharpDivideByZeroException, NULL },
  { SWIG_CSharpIndexOutOfRangeException, NULL },
  { SWIG_CSharpInvalidCastException, NULL },
  { SWIG_CSharpInvalidOperationException, NULL },
  { SWIG_CSharpIOException, NULL },
  { SWIG_CSharpNullReferenceException, NULL },
  { SWIG_CSharpOutOfMemoryException, NULL },
  { SWIG_CSharpOverflowException, NULL },
  { SWIG_CSharpSystemException, NULL }
};

static SWIG_CSharpExceptionArgument_t SWIG_csharp_exceptions_argument[] = {
  { SWIG_CSharpArgumentException, NULL },
  { SWIG_CSharpArgumentNullException, NULL },
  { SWIG_CSharpArgumentOutOfRangeException, NULL }
};

static void SWIGUNUSED SWIG_CSharpSetPendingException(SWIG_CSharpExceptionCodes code, const char *msg) {
  SWIG_CSharpExceptionCallback_t callback = SWIG_csharp_exceptions[SWIG_CSharpApplicationException].callback;
  if ((size_t)code < sizeof(SWIG_csharp_exceptions)/sizeof(SWIG_CSharpException_t)) {
    callback = SWIG_csharp_exceptions[code].callback;
  }
  callback(msg);
}

static void SWIGUNUSED SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpExceptionArgumentCodes code, const char *msg, const char *param_name) {
  SWIG_CSharpExceptionArgumentCallback_t callback = SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentException].callback;
  if ((size_t)code < sizeof(SWIG_csharp_exceptions_argument)/sizeof(SWIG_CSharpExceptionArgument_t)) {
    callback = SWIG_csharp_exceptions_argument[code].callback;
  }
  callback(msg, param_name);
}


#ifdef __cplusplus
extern "C" 
#endif
SWIGEXPORT void SWIGSTDCALL SWIGRegisterExceptionCallbacks_GdalConst(
                                                SWIG_CSharpExceptionCallback_t applicationCallback,
                                                SWIG_CSharpExceptionCallback_t arithmeticCallback,
                                                SWIG_CSharpExceptionCallback_t divideByZeroCallback, 
                                                SWIG_CSharpExceptionCallback_t indexOutOfRangeCallback, 
                                                SWIG_CSharpExceptionCallback_t invalidCastCallback,
                                                SWIG_CSharpExceptionCallback_t invalidOperationCallback,
                                                SWIG_CSharpExceptionCallback_t ioCallback,
                                                SWIG_CSharpExceptionCallback_t nullReferenceCallback,
                                                SWIG_CSharpExceptionCallback_t outOfMemoryCallback, 
                                                SWIG_CSharpExceptionCallback_t overflowCallback, 
                                                SWIG_CSharpExceptionCallback_t systemCallback) {
  SWIG_csharp_exceptions[SWIG_CSharpApplicationException].callback = applicationCallback;
  SWIG_csharp_exceptions[SWIG_CSharpArithmeticException].callback = arithmeticCallback;
  SWIG_csharp_exceptions[SWIG_CSharpDivideByZeroException].callback = divideByZeroCallback;
  SWIG_csharp_exceptions[SWIG_CSharpIndexOutOfRangeException].callback = indexOutOfRangeCallback;
  SWIG_csharp_exceptions[SWIG_CSharpInvalidCastException].callback = invalidCastCallback;
  SWIG_csharp_exceptions[SWIG_CSharpInvalidOperationException].callback = invalidOperationCallback;
  SWIG_csharp_exceptions[SWIG_CSharpIOException].callback = ioCallback;
  SWIG_csharp_exceptions[SWIG_CSharpNullReferenceException].callback = nullReferenceCallback;
  SWIG_csharp_exceptions[SWIG_CSharpOutOfMemoryException].callback = outOfMemoryCallback;
  SWIG_csharp_exceptions[SWIG_CSharpOverflowException].callback = overflowCallback;
  SWIG_csharp_exceptions[SWIG_CSharpSystemException].callback = systemCallback;
}

#ifdef __cplusplus
extern "C" 
#endif
SWIGEXPORT void SWIGSTDCALL SWIGRegisterExceptionArgumentCallbacks_GdalConst(
                                                SWIG_CSharpExceptionArgumentCallback_t argumentCallback,
                                                SWIG_CSharpExceptionArgumentCallback_t argumentNullCallback,
                                                SWIG_CSharpExceptionArgumentCallback_t argumentOutOfRangeCallback) {
  SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentException].callback = argumentCallback;
  SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentNullException].callback = argumentNullCallback;
  SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentOutOfRangeException].callback = argumentOutOfRangeCallback;
}


/* Callback for returning strings to C# without leaking memory */
typedef char * (SWIGSTDCALL* SWIG_CSharpStringHelperCallback)(const char *);
static SWIG_CSharpStringHelperCallback SWIG_csharp_string_callback = NULL;


#ifdef __cplusplus
extern "C" 
#endif
SWIGEXPORT void SWIGSTDCALL SWIGRegisterStringCallback_GdalConst(SWIG_CSharpStringHelperCallback callback) {
  SWIG_csharp_string_callback = callback;
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentOutOfRangeException, msg, ""); return nullreturn; } else


#include "gdal.h"
#include "gdalwarper.h"
#include "cpl_string.h"
#include "cpl_minixml.h"


#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT int SWIGSTDCALL CSharp_GDT_Unknown_get() {
  int jresult ;
  int result;
  
  result = (int)(GDT_Unknown);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GDT_Byte_get() {
  int jresult ;
  int result;
  
  result = (int)(GDT_Byte);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GDT_UInt16_get() {
  int jresult ;
  int result;
  
  result = (int)(GDT_UInt16);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GDT_Int16_get() {
  int jresult ;
  int result;
  
  result = (int)(GDT_Int16);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GDT_UInt32_get() {
  int jresult ;
  int result;
  
  result = (int)(GDT_UInt32);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GDT_Int32_get() {
  int jresult ;
  int result;
  
  result = (int)(GDT_Int32);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GDT_Float32_get() {
  int jresult ;
  int result;
  
  result = (int)(GDT_Float32);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GDT_Float64_get() {
  int jresult ;
  int result;
  
  result = (int)(GDT_Float64);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GDT_CInt16_get() {
  int jresult ;
  int result;
  
  result = (int)(GDT_CInt16);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GDT_CInt32_get() {
  int jresult ;
  int result;
  
  result = (int)(GDT_CInt32);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GDT_CFloat32_get() {
  int jresult ;
  int result;
  
  result = (int)(GDT_CFloat32);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GDT_CFloat64_get() {
  int jresult ;
  int result;
  
  result = (int)(GDT_CFloat64);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GDT_TypeCount_get() {
  int jresult ;
  int result;
  
  result = (int)(GDT_TypeCount);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GA_ReadOnly_get() {
  int jresult ;
  int result;
  
  result = (int)(GA_ReadOnly);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GA_Update_get() {
  int jresult ;
  int result;
  
  result = (int)(GA_Update);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GF_Read_get() {
  int jresult ;
  int result;
  
  result = (int)(GF_Read);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GF_Write_get() {
  int jresult ;
  int result;
  
  result = (int)(GF_Write);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GRIORA_NearestNeighbour_get() {
  int jresult ;
  int result;
  
  result = (int)(GRIORA_NearestNeighbour);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GRIORA_Bilinear_get() {
  int jresult ;
  int result;
  
  result = (int)(GRIORA_Bilinear);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GRIORA_Cubic_get() {
  int jresult ;
  int result;
  
  result = (int)(GRIORA_Cubic);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GRIORA_CubicSpline_get() {
  int jresult ;
  int result;
  
  result = (int)(GRIORA_CubicSpline);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GRIORA_Lanczos_get() {
  int jresult ;
  int result;
  
  result = (int)(GRIORA_Lanczos);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GRIORA_Average_get() {
  int jresult ;
  int result;
  
  result = (int)(GRIORA_Average);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GRIORA_Mode_get() {
  int jresult ;
  int result;
  
  result = (int)(GRIORA_Mode);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GRIORA_Gauss_get() {
  int jresult ;
  int result;
  
  result = (int)(GRIORA_Gauss);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GCI_Undefined_get() {
  int jresult ;
  int result;
  
  result = (int)(GCI_Undefined);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GCI_GrayIndex_get() {
  int jresult ;
  int result;
  
  result = (int)(GCI_GrayIndex);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GCI_PaletteIndex_get() {
  int jresult ;
  int result;
  
  result = (int)(GCI_PaletteIndex);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GCI_RedBand_get() {
  int jresult ;
  int result;
  
  result = (int)(GCI_RedBand);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GCI_GreenBand_get() {
  int jresult ;
  int result;
  
  result = (int)(GCI_GreenBand);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GCI_BlueBand_get() {
  int jresult ;
  int result;
  
  result = (int)(GCI_BlueBand);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GCI_AlphaBand_get() {
  int jresult ;
  int result;
  
  result = (int)(GCI_AlphaBand);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GCI_HueBand_get() {
  int jresult ;
  int result;
  
  result = (int)(GCI_HueBand);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GCI_SaturationBand_get() {
  int jresult ;
  int result;
  
  result = (int)(GCI_SaturationBand);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GCI_LightnessBand_get() {
  int jresult ;
  int result;
  
  result = (int)(GCI_LightnessBand);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GCI_CyanBand_get() {
  int jresult ;
  int result;
  
  result = (int)(GCI_CyanBand);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GCI_MagentaBand_get() {
  int jresult ;
  int result;
  
  result = (int)(GCI_MagentaBand);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GCI_YellowBand_get() {
  int jresult ;
  int result;
  
  result = (int)(GCI_YellowBand);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GCI_BlackBand_get() {
  int jresult ;
  int result;
  
  result = (int)(GCI_BlackBand);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GCI_YCbCr_YBand_get() {
  int jresult ;
  int result;
  
  result = (int)(GCI_YCbCr_YBand);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GCI_YCbCr_CrBand_get() {
  int jresult ;
  int result;
  
  result = (int)(GCI_YCbCr_CrBand);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GCI_YCbCr_CbBand_get() {
  int jresult ;
  int result;
  
  result = (int)(GCI_YCbCr_CbBand);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GRA_NearestNeighbour_get() {
  int jresult ;
  int result;
  
  result = (int)(GRA_NearestNeighbour);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GRA_Bilinear_get() {
  int jresult ;
  int result;
  
  result = (int)(GRA_Bilinear);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GRA_Cubic_get() {
  int jresult ;
  int result;
  
  result = (int)(GRA_Cubic);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GRA_CubicSpline_get() {
  int jresult ;
  int result;
  
  result = (int)(GRA_CubicSpline);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GRA_Lanczos_get() {
  int jresult ;
  int result;
  
  result = (int)(GRA_Lanczos);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GRA_Average_get() {
  int jresult ;
  int result;
  
  result = (int)(GRA_Average);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GRA_Mode_get() {
  int jresult ;
  int result;
  
  result = (int)(GRA_Mode);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GPI_Gray_get() {
  int jresult ;
  int result;
  
  result = (int)(GPI_Gray);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GPI_RGB_get() {
  int jresult ;
  int result;
  
  result = (int)(GPI_RGB);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GPI_CMYK_get() {
  int jresult ;
  int result;
  
  result = (int)(GPI_CMYK);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GPI_HLS_get() {
  int jresult ;
  int result;
  
  result = (int)(GPI_HLS);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CXT_Element_get() {
  int jresult ;
  int result;
  
  result = (int)(CXT_Element);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CXT_Text_get() {
  int jresult ;
  int result;
  
  result = (int)(CXT_Text);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CXT_Attribute_get() {
  int jresult ;
  int result;
  
  result = (int)(CXT_Attribute);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CXT_Comment_get() {
  int jresult ;
  int result;
  
  result = (int)(CXT_Comment);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CXT_Literal_get() {
  int jresult ;
  int result;
  
  result = (int)(CXT_Literal);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CE_None_get() {
  int jresult ;
  int result;
  
  result = (int)(CE_None);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CE_Debug_get() {
  int jresult ;
  int result;
  
  result = (int)(CE_Debug);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CE_Warning_get() {
  int jresult ;
  int result;
  
  result = (int)(CE_Warning);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CE_Failure_get() {
  int jresult ;
  int result;
  
  result = (int)(CE_Failure);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CE_Fatal_get() {
  int jresult ;
  int result;
  
  result = (int)(CE_Fatal);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CPLE_None_get() {
  int jresult ;
  int result;
  
  result = (int)(CPLE_None);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CPLE_AppDefined_get() {
  int jresult ;
  int result;
  
  result = (int)(CPLE_AppDefined);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CPLE_OutOfMemory_get() {
  int jresult ;
  int result;
  
  result = (int)(CPLE_OutOfMemory);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CPLE_FileIO_get() {
  int jresult ;
  int result;
  
  result = (int)(CPLE_FileIO);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CPLE_OpenFailed_get() {
  int jresult ;
  int result;
  
  result = (int)(CPLE_OpenFailed);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CPLE_IllegalArg_get() {
  int jresult ;
  int result;
  
  result = (int)(CPLE_IllegalArg);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CPLE_NotSupported_get() {
  int jresult ;
  int result;
  
  result = (int)(CPLE_NotSupported);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CPLE_AssertionFailed_get() {
  int jresult ;
  int result;
  
  result = (int)(CPLE_AssertionFailed);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CPLE_NoWriteAccess_get() {
  int jresult ;
  int result;
  
  result = (int)(CPLE_NoWriteAccess);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CPLE_UserInterrupt_get() {
  int jresult ;
  int result;
  
  result = (int)(CPLE_UserInterrupt);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_OF_ALL_get() {
  int jresult ;
  int result;
  
  result = (int)(GDAL_OF_ALL);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_OF_RASTER_get() {
  int jresult ;
  int result;
  
  result = (int)(GDAL_OF_RASTER);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_OF_VECTOR_get() {
  int jresult ;
  int result;
  
  result = (int)(GDAL_OF_VECTOR);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_OF_GNM_get() {
  int jresult ;
  int result;
  
  result = (int)(GDAL_OF_GNM);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_OF_READONLY_get() {
  int jresult ;
  int result;
  
  result = (int)(GDAL_OF_READONLY);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_OF_UPDATE_get() {
  int jresult ;
  int result;
  
  result = (int)(GDAL_OF_UPDATE);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_OF_SHARED_get() {
  int jresult ;
  int result;
  
  result = (int)(GDAL_OF_SHARED);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_OF_VERBOSE_ERROR_get() {
  int jresult ;
  int result;
  
  result = (int)(GDAL_OF_VERBOSE_ERROR);
  jresult = result; 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_GDAL_DMD_LONGNAME_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("DMD_LONGNAME");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_GDAL_DMD_HELPTOPIC_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("DMD_HELPTOPIC");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_GDAL_DMD_MIMETYPE_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("DMD_MIMETYPE");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_GDAL_DMD_EXTENSION_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("DMD_EXTENSION");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_GDAL_DMD_EXTENSIONS_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("DMD_EXTENSIONS");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_DMD_CONNECTION_PREFIX_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("DMD_CONNECTION_PREFIX");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_GDAL_DMD_CREATIONOPTIONLIST_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("DMD_CREATIONOPTIONLIST");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_GDAL_DMD_CREATIONDATATYPES_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("DMD_CREATIONDATATYPES");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_GDAL_DMD_CREATIONFIELDDATATYPES_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("DMD_CREATIONFIELDDATATYPES");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_GDAL_DMD_SUBDATASETS_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("DMD_SUBDATASETS");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_GDAL_DCAP_OPEN_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("DCAP_OPEN");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_GDAL_DCAP_CREATE_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("DCAP_CREATE");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_GDAL_DCAP_CREATECOPY_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("DCAP_CREATECOPY");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_GDAL_DCAP_VIRTUALIO_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("DCAP_VIRTUALIO");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_DCAP_RASTER_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("GDAL_DCAP_RASTER");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_DCAP_VECTOR_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("GDAL_DCAP_VECTOR");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_DCAP_NOTNULL_FIELDS_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("GDAL_DCAP_NOTNULL_FIELDS");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_DCAP_DEFAULT_FIELDS_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("GDAL_DCAP_DEFAULT_FIELDS");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT char * SWIGSTDCALL CSharp_DCAP_NOTNULL_GEOMFIELDS_get() {
  char * jresult ;
  char *result = 0 ;
  
  result = (char *)("GDAL_DCAP_NOTNULL_GEOMFIELDS");
  jresult = SWIG_csharp_string_callback((const char *)result); 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CPLES_BackslashQuotable_get() {
  int jresult ;
  int result;
  
  result = (int)(CPLES_BackslashQuotable);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CPLES_XML_get() {
  int jresult ;
  int result;
  
  result = (int)(CPLES_XML);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CPLES_URL_get() {
  int jresult ;
  int result;
  
  result = (int)(CPLES_URL);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CPLES_SQL_get() {
  int jresult ;
  int result;
  
  result = (int)(CPLES_SQL);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_CPLES_CSV_get() {
  int jresult ;
  int result;
  
  result = (int)(CPLES_CSV);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFT_Integer_get() {
  int jresult ;
  int result;
  
  result = (int)(GFT_Integer);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFT_Real_get() {
  int jresult ;
  int result;
  
  result = (int)(GFT_Real);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFT_String_get() {
  int jresult ;
  int result;
  
  result = (int)(GFT_String);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_Generic_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_Generic);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_PixelCount_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_PixelCount);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_Name_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_Name);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_Min_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_Min);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_Max_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_Max);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_MinMax_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_MinMax);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_Red_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_Red);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_Green_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_Green);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_Blue_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_Blue);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_Alpha_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_Alpha);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_RedMin_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_RedMin);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_GreenMin_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_GreenMin);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_BlueMin_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_BlueMin);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_AlphaMin_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_AlphaMin);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_RedMax_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_RedMax);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_GreenMax_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_GreenMax);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_BlueMax_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_BlueMax);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_AlphaMax_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_AlphaMax);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GFU_MaxCount_get() {
  int jresult ;
  int result;
  
  result = (int)(GFU_MaxCount);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GMF_ALL_VALID_get() {
  int jresult ;
  int result;
  
  result = (int)(0x01);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GMF_PER_DATASET_get() {
  int jresult ;
  int result;
  
  result = (int)(0x02);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GMF_ALPHA_get() {
  int jresult ;
  int result;
  
  result = (int)(0x04);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GMF_NODATA_get() {
  int jresult ;
  int result;
  
  result = (int)(0x08);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GDAL_DATA_COVERAGE_STATUS_UNIMPLEMENTED_get() {
  int jresult ;
  int result;
  
  result = (int)(0x01);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GDAL_DATA_COVERAGE_STATUS_DATA_get() {
  int jresult ;
  int result;
  
  result = (int)(0x02);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GDAL_DATA_COVERAGE_STATUS_EMPTY_get() {
  int jresult ;
  int result;
  
  result = (int)(0x04);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GARIO_PENDING_get() {
  int jresult ;
  int result;
  
  result = (int)(GARIO_PENDING);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GARIO_UPDATE_get() {
  int jresult ;
  int result;
  
  result = (int)(GARIO_UPDATE);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GARIO_ERROR_get() {
  int jresult ;
  int result;
  
  result = (int)(GARIO_ERROR);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GARIO_COMPLETE_get() {
  int jresult ;
  int result;
  
  result = (int)(GARIO_COMPLETE);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GTO_TIP_get() {
  int jresult ;
  int result;
  
  result = (int)(GTO_TIP);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GTO_BIT_get() {
  int jresult ;
  int result;
  
  result = (int)(GTO_BIT);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_GTO_BSQ_get() {
  int jresult ;
  int result;
  
  result = (int)(GTO_BSQ);
  jresult = result; 
  return jresult;
}


#ifdef __cplusplus
}
#endif


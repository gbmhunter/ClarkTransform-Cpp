//!
//! @file 		ClarkTransform.cpp
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @edited 	n/a
//! @date 		2012/10/09
//! @brief 		Implements field orientated control for BLDC motors.
//! @details
//!				See README.rst


//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

extern "C" {

// PSoC
#include <device.h>

// GCC
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// FreeRTOS includes
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

}

// User
#include "PublicDefinesAndTypeDefs.h"
#include "Config.h"
#include "./FixedPoint/FP.h"
#include "Bldc.h"
#include "Foc.h"
#include "UartDebug.h"
#include "Svm.h"

//===============================================================================================//
//================================== PRECOMPILER CHECKS =========================================//
//===============================================================================================//

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

#ifndef configPRINT_DEBUG_CLARK_TRANSFORM
	#error Please define the switch configPRINT_DEBUG_CLARK_TRANSFORM
#endif

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace ClarkTransform
{

using namespace Fp;

#if(configPRINT_DEBUG_CLARK_TRANSFORM == 1)
	static char _debugBuff[100];
#endif

//===============================================================================================//
//====================================  FUNCTION PROTOTYPES =====================================//
//===============================================================================================//

//! @brief		The Clark transformation implemented with fixed-point numbers
//! @details	Uses a scaling factor of sqrt(2/3). Calculations:
//! 				alpha = sqrt(2/3)*(a-0.5b-0.5c)
//! 				beta = 1/sqrt(2)*(b-c)
//!				Execution Time: 72 clock cycles (1.5us @ 48MHz) (including function call)
void Forward(fp<CDP> a, fp<CDP> b, fp<CDP> c, 
	fp<CDP> *alpha ,fp<CDP> *beta)
{
	// Used to hold intermediary results
	fp<CDP> tempVar;
	
	tempVar = b - c;
	#if(configPRINT_DEBUG_CLARK_TRANSFORM == 1)
		snprintf(_debugBuff, sizeof(_debugBuff), "CLARK: b-c = %fA\r\n", Fix2Float<CDP>(tempVar.intValue));
		UartDebug::PutString(_debugBuff);
	#endif
	
	beta->intValue = (tempVar.intValue>>1) - (tempVar.intValue>>5) + (tempVar.intValue>>2);
	#if(configPRINT_DEBUG_CLARK_TRANSFORM == 1)
		snprintf(_debugBuff, sizeof(_debugBuff), "CLARK: beta = %fA\r\n", Fix2Float<CDP>((tempVar.intValue>>1) - (tempVar.intValue>>5) + (tempVar.intValue>>2)));
		UartDebug::PutString(_debugBuff);
	#endif
	
	tempVar.intValue = a.intValue - (b.intValue>>1) - (c.intValue>>1);
	#if(configPRINT_DEBUG_CLARK_TRANSFORM == 1)
		snprintf(_debugBuff, sizeof(_debugBuff), "CLARK: a - 0.5b - 0.5c = %fA\r\n", Fix2Float<CDP>(tempVar.intValue));
		UartDebug::PutString(_debugBuff);
	#endif
	
	alpha->intValue = (tempVar.intValue>>1) + (tempVar.intValue>>2) + (tempVar.intValue>>4);
}

//! @brief		The Clark transformation implemented with doubles.
void ClarkTransform_Forward(double a, double b, double c, double *alpha ,double *beta)
{
	// alpha = sqrt(2/3)*(a-0.5b-0.5c)
	// beta = 1/sqrt(2)*(b-c)
	*alpha = sqrt(2.0/3.0)*(a - 0.5*b - 0.5*c);
	*beta = (1.0/sqrt(2.0))*(b - c);
}

void ClarkTransform_Inverse()
{
	// not implemented
}

} //namespace ClarkTransform

// EOF
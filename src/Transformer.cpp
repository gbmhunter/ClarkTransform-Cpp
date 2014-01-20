//!
//! @file 				Transformer.cpp
//! @author 			Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @edited 			n/a
//! @created			2012/10/09
//! @last-modified 		2014/01/21
//! @brief 				Provides functions to perform the clark transform. Useful for BLDC motor FOC.
//! @details
//!						See the README in the repo root dir for more info.

//===============================================================================================//
//================================== PRECOMPILER CHECKS =========================================//
//===============================================================================================//

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

// System headers
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// User headers
#include "../include/Transformer.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace ClarkTransform
{

	
	#if(configPRINT_DEBUG_CLARK_TRANSFORM == 1)
		static char _debugBuff[100];
	#endif

	//===============================================================================================//
	//====================================  FUNCTION PROTOTYPES =====================================//
	//===============================================================================================//

	//! @brief		The Clark transformation implemented with doubles.
	void Transformer::Forward(double a, double b, double c, double *alpha ,double *beta)
	{
		// alpha = sqrt(2/3)*(a-0.5b-0.5c)
		// beta = 1/sqrt(2)*(b-c)
		*alpha = sqrt(2.0/3.0)*(a - 0.5*b - 0.5*c);
		*beta = (1.0/sqrt(2.0))*(b - c);
	}

#if(config_ENABLE_FIXED_POINT_FUNCTIONS == 1)

	void Transformer::Forward(Fp::fp<CDP> a, Fp::fp<CDP> b, Fp::fp<CDP> c,
		Fp::fp<CDP> *alpha , Fp::fp<CDP> *beta)
	{
		// Used to hold intermediary results
		Fp::fp<CDP> tempVar;

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
#endif

} //namespace ClarkTransform

// EOF

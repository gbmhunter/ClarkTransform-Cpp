//!
//! @file 		ClarkTransform.h
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @edited 	n/a
//! @date 		12/10/2012
//! @brief 		Header file for ClarkTransform.cpp
//! @details
//!		<b>Last Modified:			</b> 20/11/2012					\n
//!		<b>Version:					</b> v1.0.0						\n
//!		<b>Company:					</b> CladLabs					\n
//!		<b>Project:					</b> Free code libraries		\n
//!		<b>Language:				</b> C++						\n
//!		<b>Compiler:				</b> GCC						\n
//! 	<b>uC Model:				</b> PSoC5						\n
//!		<b>Computer Architecture:	</b> ARM						\n
//! 	<b>Operating System:		</b> FreeRTOS v7.2.0			\n
//!		<b>Documentation Format:	</b> Doxygen					\n
//!		<b>License:					</b> GPLv3						\n
//!		

//===============================================================================================//
//====================================== HEADER GUARD ===========================================//
//===============================================================================================//

#ifndef _CLARK_TRANSFORM_H
#define _CLARK_TRANSFORM_H

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace ClarkTransform
{

using namespace Fp;

//===============================================================================================//
//=================================== PUBLIC FUNCTION PROTOTYPES ================================//
//===============================================================================================//

// See the function definitions in ClarkTransform.c for more information

//void ClarkTransform_ForwardFp(int32_t a, int32_t b, int32_t c, int32_t *alpha ,int32_t *beta);
//void ClarkTransform_ForwardDbl(double a, double b, double c, double *alpha ,double *beta);
void Forward(fp<CDP> a, fp<CDP> b, fp<CDP> c, 
	fp<CDP> *alpha ,fp<CDP> *beta);

} // namespace ClarkTransform

#endif // #define _CLARK_TRANSFORM_H

// EOF
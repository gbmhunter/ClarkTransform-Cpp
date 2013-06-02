//!
//! @file 		ClarkTransform.h
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @edited 	n/a
//! @date 		2012/10/12
//! @brief 		Header file for the ClarkTransform library.
//! @details
//!				See README.rst	

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
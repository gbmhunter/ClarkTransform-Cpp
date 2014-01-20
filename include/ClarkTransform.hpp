//!
//! @file 				ClarkTransform.hpp
//! @author 			Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @edited 			n/a
//! @created			2012/10/09
//! @last-modified 		2014/01/14
//! @brief 				Header file for the ClarkTransform library.
//! @details
//!						See the README in the repo root dir for more info.

//===============================================================================================//
//====================================== HEADER GUARD ===========================================//
//===============================================================================================//

#ifndef CLARK_TRANSFORM_H
#define CLARK_TRANSFORM_H

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

// Library headers
#include "Config.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace ClarkTransform
{

	//===============================================================================================//
	//=================================== PUBLIC FUNCTION PROTOTYPES ================================//
	//===============================================================================================//

	// See the function definitions in ClarkTransform.c for more information

	//void ClarkTransform_ForwardFp(int32_t a, int32_t b, int32_t c, int32_t *alpha ,int32_t *beta);
	//void ClarkTransform_ForwardDbl(double a, double b, double c, double *alpha ,double *beta);

#if(config_ENABLE_FIXED_POINT_FUNCTIONS == 1)
	void Forward(Fp::fp<CDP> a, Fp::fp<CDP> b, Fp::fp<CDP> c,
			Fp::fp<CDP> *alpha ,Fp::fp<CDP> *beta);
#endif

} // namespace ClarkTransform

#endif // #define _CLARK_TRANSFORM_H

// EOF

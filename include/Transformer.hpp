//!
//! @file 				Transformer.hpp
//! @author 			Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @edited 			n/a
//! @created			2012/10/09
//! @last-modified 		2014/01/21
//! @brief				Provides functions to perform the clark transform. Useful for BLDC motor FOC.
//! @details
//!						See the README in the repo root dir for more info.

//===============================================================================================//
//====================================== HEADER GUARD ===========================================//
//===============================================================================================//

#ifndef CLARK_TRANSFORM_TRANSFORMER_H
#define CLARK_TRANSFORM_TRANSFORMER_H

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

	//! @brief		Class that performs Clark transformations
	class Transformer
	{
	public:

		//! @brief		Forward Clark transform using doubles.
		//! @param		a 		The magnitude of phase A (typically voltage or current)
		//! @param		b		The magnitude of phase B (typically voltage or current)
		//! @param		c		The magnitude of phase C (typically voltage or current)
		//! @param		alpha	Pointer to where the result alpha will be stored.
		//! @param		beta	Pointer to where the result beta will be stored.
		void Forward(
			double a,
			double b,
			double c,
			double *alpha,
			double *beta);

#if(config_ENABLE_FIXED_POINT_FUNCTIONS == 1)
		//! @brief		The forward Clark transformation implemented with fixed-point numbers
		//! @details	Uses a scaling factor of sqrt(2/3). Calculations:
		//! 				alpha = sqrt(2/3)*(a-0.5b-0.5c)
		//! 				beta = 1/sqrt(2)*(b-c)
		//!				Execution Time: 72 clock cycles (1.5us @ 48MHz) (including function call) on 32-bit microcontroller.
		//! @param		a 		The magnitude of phase A (typically voltage or current)
		//! @param		b		The magnitude of phase B (typically voltage or current)
		//! @param		c		The magnitude of phase C (typically voltage or current)
		//! @param		alpha	Pointer to where the result alpha will be stored.
		//! @param		beta	Pointer to where the result beta will be stored.
		void Forward(
			Fp::fp<CDP> a,
			Fp::fp<CDP> b,
			Fp::fp<CDP> c,
			Fp::fp<CDP> *alpha,
			Fp::fp<CDP> *beta);
#endif

	};


} // namespace ClarkTransform

#endif // #define _CLARK_TRANSFORM_H

// EOF

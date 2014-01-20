//!
//! @file 			BaiscTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/01/21
//! @last-modified 	2014/01/21
//! @brief			Basic Clark transformation tests.
//! @details
//!					See README.rst in root dir for more info.

#include "../api/ClarkTransform.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace ClarkTransformTest
{
	SUITE(BaiscTests)
	{

		TEST(BasicTest1)
		{
			ClarkTransform::Transformer clarkTransformer;

			double alpha;
			double beta;

			// When a=1, b=1, c=1 then alpha=0, beta=0
			clarkTransformer.Forward(1, 1, 1, &alpha, &beta);
			CHECK_CLOSE(0, alpha, 0.05);
			CHECK_CLOSE(0, beta, 0.05);
		}
		
		TEST(BasicTest2)
		{
			ClarkTransform::Transformer clarkTransformer;

			double alpha;
			double beta;

			// When a=1, b=2, c=0 then alpha=0, beta=1.414
			clarkTransformer.Forward(1, 2, 0, &alpha, &beta);
			CHECK_CLOSE(0, alpha, 0.05);
			CHECK_CLOSE(1.414, beta, 0.05);
		}

	} // SUITE(BaiscTests)
} // namespace ClarkTransformTest

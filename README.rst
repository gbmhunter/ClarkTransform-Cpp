============================
clark-transform-cpp
============================

----------------------------
Clark Transformation Library
----------------------------

- Author: gbmhunter <gbmhunter@gmail.com> (http://www.cladlab.com)
- Created: 2012/10/12
- Last Modified: 2014/01/21
- Version: v2.0.0.0
- Company: CladLabs
- Project: n/a
- Language: C++
- Compiler: GCC	
- uC Model: All
- Computer Architecture: All
- Operating System: n/a
- Documentation Format: Doxygen
- License: GPLv3

Description
-----------

Library for performing the Clark transformation, a mathematical transformation commonly used for BLDC motor control.

Can be used with the fixed point library fixed-point-cpp, for ultra fast computations.

Internal Dependencies
---------------------
	
- None
		
External Dependencies
---------------------

- (optional) FixedPoint library. Required if you want to use fixed-point number types with the PID control loops.

Usage
-----

::
	
	Coming soon.
	
See `test/ClarkTransformTest.cpp` for more examples.
	
Issues
------

For known bugs, desired enhancements e.t.c, see GitHub issues section.
	
Changelog
---------

======== ========== ===================================================================================================
Version  Date       Comment
======== ========== ===================================================================================================
v2.0.0.0 2014/01/21 Added makefile, closes #8. Makefile has automatic dependancy generation, closes #9. Added unit test library and unit tests, closes #3. Removed unneccessary includes from source files, closes #10. Removed underscore from header guard name in ClideTransform.hpp, closes #11. Added examples to 'example/', closes #13. Added config file, closes #14.
v1.1.0.0 2014/01/21 Moved 'src/include' files to 'include/' to follow new file convention. Updated title in README and changed name from 'Cpp-ClarkTransform' to 'clark-transform-cpp' to follow new project naming convention. Updated reference to fixed-point-cpp in README.
v1.0.1.1 2013/06/08 README Changelog now in table format.
v1.0.1.0 2013/06/03 Renamed incorrect extension .cs to .cpp. Moved .h files into 'src/include/' and renamed to .hpp.
v1.0.0.1 2013/06/03 Removed Mercurial repo files (.hgingnore, .hgtags).
v1.0.0.0 2013/06/03 First versioned commit. Added README.rst.
======== ========== ===================================================================================================
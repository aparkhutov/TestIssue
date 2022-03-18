# CMakeList.txt : CMake project for TestProject, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("TestProject")

# Add source to this project's executable.
#	 "oldCode.cpp"
add_executable (TestProject 
	 "main.cpp"
	 "TypeUtils.h"
	 "Utils.h"
	 "TestMethods/BaseMethod.h"
	 "TestMethods/TestMethodsFactory.h"
	 "TestMethods/CalculateChecksumMethod.cpp"
	 "TestMethods/CalculateWordMethod.cpp"
	 "TestMethods/CalculateWordMethod.h"
	 "TypeUtils.cpp")
target_compile_features(TestProject PUBLIC cxx_std_17)

add_compile_options(/Wall)
add_compile_options(/Wextra)




# TODO: Add tests and install targets if needed.

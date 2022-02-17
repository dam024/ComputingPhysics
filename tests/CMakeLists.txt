cmake_minimum_required(VERSION 3.16.3)
project(ComputingPhysicsTests)

set(CMAKE_CXX_STANDARD 17)


file(GLOB SRC_FILES
	"*.cpp" "../classes/*.cpp"
)
set(INC_TESTS_FILES #set a variable
	../
	../classes/
)

include_directories(
	${INC_TESTS_FILES}
)
add_executable(ComputingPhysicsTests
	${SRC_FILES}
)
cmake_minimum_required(VERSION 3.16.3)
project(ComputingPhysicsTests)


file(GLOB SRC_FILES
	"*.cpp"
)
set(INC_TESTS_FILES #set a variable
	"../classes/*.cpp"
)

include_directories(
	${INC_TESTS_FILES}
)
add_executable(ComputingPhysicsTests
	${SRC_FILES}
)
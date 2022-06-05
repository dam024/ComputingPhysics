cmake_minimum_required(VERSION 3.16.3)
project(ComputingPhysicsTests)

set(CMAKE_CXX_STANDARD 17)


file(GLOB SRC_FILES
	"../src/*.cpp"
	"functions/*.cpp"
)
set(INC_TESTS_FILES #set a variable
	../include
	../private
	functions
)

include_directories(
	${INC_TESTS_FILES}
)
add_executable(ComputingPhysicsTests
	${SRC_FILES} "main.cpp"
)

add_executable(TestExemple
	${SRC_FILES} "testExemple.cpp"
)

add_executable(TestUtils
	${SRC_FILES} "testUtils.cpp"
)
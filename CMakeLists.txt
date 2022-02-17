cmake_minimum_required(VERSION 3.16.3)
project(ComputingPhysics)

option(BUILD_TESTS "Turn on build for tests of Exercice4" OFF)

file(GLOB SRC_FILES
	"classes/*.cpp"
)

if (BUILD_TESTS)
	add_subdirectory(tests)
endif()
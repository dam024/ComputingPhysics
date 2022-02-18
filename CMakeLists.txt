#Réalisé selon : https://stackoverflow.com/questions/17511496/how-to-create-a-shared-library-with-cmake
cmake_minimum_required(VERSION 3.16.3)
project(ComputingPhysics VERSION 1.0 DESCRIPTION "ComputingPhysics is a project which aimed to integrate differential equations")

# OPTIONS
option(BUILD_TESTS "Turn on build for tests of Exercice4" OFF)

# PROJECT PROPERTIES
set(PROJETCT_VERSION
	1.0
)


#if (BUILD_TESTS)
#	add_subdirectory(tests)
#endif()

#set_target_properties(ComputingPhysics PROPERTIES VERSION ${PROJECT_VERSION})
#set_target_properties(ComputingPhysics PROPERTIES PUBLIC_HEADER #ComputingPhysics.hpp)
#
#
#add_library(ComputingPhysics SHARED
#    classes/*.cpp
#)




file(GLOB SOURCES classes/*.cpp)

include_directories(
	classes/
)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

file(GLOB HEADERS "classes/*.hpp" "ComputingPhysics.hpp")
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})
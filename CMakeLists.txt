cmake_minimum_required(VERSION 3.8)

project(ReCpp-filesystem
	VERSION			0.0.0
	DESCRIPTION		"Reactive programing library for filesystem manipulation using C++"
	HOMEPAGE_URL	"https://github.com/pribault/ReCpp-filesystem"
	LANGUAGES		CXX
)

option(RECPP_FILESYSTEM_BUILD_EXAMPLES "Compile ReCpp-filesystem examples" ON)
option(RECPP_FILESYSTEM_BUILD_TESTS "Compile ReCpp-filesystem tests" ON)

include(FetchContent)

FetchContent_Declare(
	ReCpp
	GIT_REPOSITORY	https://github.com/pribault/ReCpp.git
	GIT_TAG			fa725834059fe436a66e5e972db9247368cf0d0b
)
set(RSCPP_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(RSCPP_BUILD_TESTS  CACHE BOOL "" FORCE)
set(RECPP_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(RECPP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(ReCpp)

set(SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/include/recpp/filesystem/FileSystem.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/FileSystem.cpp
)

add_library(ReCpp-filesystem ${SOURCES})

target_include_directories(ReCpp-filesystem PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(ReCpp-filesystem PUBLIC ReCpp)

set_property(TARGET ReCpp-filesystem PROPERTY CXX_STANDARD 17)

if(RECPP_FILESYSTEM_BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

# if(RECPP_FILESYSTEM_BUILD_TESTS)
# 	add_subdirectory(tests)
# endif()

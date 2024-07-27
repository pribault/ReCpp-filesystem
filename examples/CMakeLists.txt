cmake_minimum_required(VERSION 3.8)

project(ReCpp-filesystem-test
	VERSION			0.0.0
	DESCRIPTION		"ReCpp-filesystem test example"
	HOMEPAGE_URL	"https://github.com/pribault/ReCpp-filesystem"
	LANGUAGES		CXX
)

set(SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(ReCpp-filesystem-test ${SOURCES})

set_property(TARGET ReCpp-filesystem-test PROPERTY CXX_STANDARD 17)

target_link_libraries(ReCpp-filesystem-test ReCpp-filesystem)

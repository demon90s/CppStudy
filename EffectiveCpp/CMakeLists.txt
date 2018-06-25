cmake_minimum_required(VERSION 2.8)

PROJECT(EffectiveCpp)

# VS设定
if (MSVC)
	ADD_DEFINITIONS(/W3 /wd"4819")
endif(MSVC)

# Linux设定
if (CMAKE_COMPILER_IS_GNUCXX)
	SET(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")
endif(CMAKE_COMPILER_IS_GNUCXX)

INCLUDE_DIRECTORIES(src/rules)

AUX_SOURCE_DIRECTORY(src SRC_FILES)
FILE(GLOB_RECURSE RULE_FILES "src/rules/*.cpp" "src/rules/*.h")

source_group(src FILES ${SRC_FILES})
source_group(rules FILES ${RULE_FILES})

ADD_EXECUTABLE(main ${SRC_FILES} ${RULE_FILES})
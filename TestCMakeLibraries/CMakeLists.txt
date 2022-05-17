cmake_minimum_required(VERSION 3.18.0)

project(testCMakeLibraries VERSION 1.0.0 DESCRIPTION "Math library")

# Include header files
set(HEADERS_DIR include)
set(HEADERS ${HEADERS_DIR}/sumDouble.h)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add sources of the library
add_library(sumDouble STATIC src/sumDouble.c)

# Add executable
add_executable(${PROJECT_NAME} src/main.c)

target_link_libraries(${PROJECT_NAME} PRIVATE sumDouble)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-m64" LINK_FLAGS "-m64")
	set(LIBRARIES_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/mingw/lib)
	set(BINARIES_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/mingw/bin)
	set(HEADERS_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/mingw/include)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "dSPACE")
	# Add dSPACE Platform settings
	include(Platform/dSPACE.cmake)
	set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-K0 -QmsA0314 -QmsA0407 -QmeA0307 -QmeA0329")	
	set(LIBRARIES_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/dspace/lib)
	set(BINARIES_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/dspace/bin)
	set(HEADERS_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/dspace/include)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")	
	set(LIBRARIES_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/unix/lib)
	set(BINARIES_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/unix/bin)
	set(HEADERS_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/unix/include)
else()
	message("Selected wrong target toolchain")
endif()

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 99)


install(TARGETS sumDouble DESTINATION ${LIBRARIES_OUTPUT_DIR})
install(TARGETS ${PROJECT_NAME} DESTINATION ${BINARIES_OUTPUT_DIR})
install (FILES ${HEADERS} DESTINATION ${HEADERS_OUTPUT_DIR})


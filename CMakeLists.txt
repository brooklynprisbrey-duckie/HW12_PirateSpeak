cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(PirateSpeak)

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( APP_EXECUTABLE PirateSpeak )

include_directories( inc )

ADD_EXECUTABLE(PirateSpeak "src/PirateSpeak.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT ${APP_EXECUTABLE} )

#add_custom_command(
#        TARGET ${APP_EXECUTABLE} POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy
#                ${CMAKE_SOURCE_DIR}/files/pirate.csv
#                ${CMAKE_CURRENT_BINARY_DIR}/pirate.csv
#)

find_program(VALGRIND "valgrind")
if(VALGRIND)
	add_custom_target(valgrind
    COMMAND "${VALGRIND}" --tool=memcheck --leak-check=yes --show-reachable=yes --error-exitcode=1 $<TARGET_FILE:${APP_EXECUTABLE}>)
endif()
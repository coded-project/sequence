cmake_minimum_required(VERSION 2.8.11)

option( VERBOSE "Show information about CMake build configuration." )

include( CMakeScripts/make_check_macros.cmake )

project( Sequence )

set( sequence_INCLUDE_DIR ${Sequence_SOURCE_DIR}/include )

add_definitions( -std=c++11 )

if( VERBOSE )
    message( "Adding directories:" )
endif()

setup_make_check()
add_subdirectory( gtest EXCLUDE_FROM_ALL )
add_subdirectory( tests EXCLUDE_FROM_ALL )

if( VERBOSE )
    message( "" )
endif()

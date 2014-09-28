if( VERBOSE )
    message( "-tests" )
endif()

include_directories( ${sequence_INCLUDE_DIR} ${GTEST_INCLUDE_DIRS} )

set( sequence_tests_SRC
        sequence_arithmetic_operator_tests.cpp
        sequence_assignment_operator_tests.cpp
        sequence_compound_assignment_operator_tests.cpp
        sequence_constructor_tests.cpp
        sequence_nested_expression_tests.cpp
   )

add_executable( sequence_tests ${sequence_tests_SRC} )
target_link_libraries( sequence_tests ${GTEST_LIBRARIES} )
add_test_to_make_check( sequence_tests )

#define COMPOUND_ASSIGNMENT_OPERATOR +=
#define TEST_FIXTURE_NAME SequencePlusEqualsTest
#include "sequence_compound_assignment_operator_test_template.hpp"
#undef COMPOUND_ASSIGNMENT_OPERATOR 
#undef TEST_FIXTURE_NAME

#define COMPOUND_ASSIGNMENT_OPERATOR -=
#define TEST_FIXTURE_NAME SequenceMinusEqualsTest
#include "sequence_compound_assignment_operator_test_template.hpp"
#undef COMPOUND_ASSIGNMENT_OPERATOR 
#undef TEST_FIXTURE_NAME

#define COMPOUND_ASSIGNMENT_OPERATOR *=
#define TEST_FIXTURE_NAME SequenceTimesEqualsTest
#include "sequence_compound_assignment_operator_test_template.hpp"
#undef COMPOUND_ASSIGNMENT_OPERATOR 
#undef TEST_FIXTURE_NAME

#define COMPOUND_ASSIGNMENT_OPERATOR /=
#define TEST_FIXTURE_NAME SequenceDivideEqualsTest
#include "sequence_compound_assignment_operator_test_template.hpp"
#undef COMPOUND_ASSIGNMENT_OPERATOR 
#undef TEST_FIXTURE_NAME
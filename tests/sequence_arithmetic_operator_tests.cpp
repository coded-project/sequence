#define ARITHMETIC_OPERATOR +
#define TEST_FIXTURE_NAME SequencePlusOperatorTest
#include "sequence_arithmetic_operator_test_template.hpp"
#undef ARITHMETIC_OPERATOR
#undef TEST_FIXTURE_NAME

#define ARITHMETIC_OPERATOR -
#define TEST_FIXTURE_NAME SequenceMinusOperatorTest
//#include "sequence_arithmetic_operator_test_template.hpp"
#undef ARITHMETIC_OPERATOR
#undef TEST_FIXTURE_NAME

#define ARITHMETIC_OPERATOR *
#define TEST_FIXTURE_NAME SequenceTimesOperatorTest
//#include "sequence_arithmetic_operator_test_template.hpp"
#undef ARITHMETIC_OPERATOR
#undef TEST_FIXTURE_NAME

#define ARITHMETIC_OPERATOR /
#define TEST_FIXTURE_NAME SequenceDivideOperatorTest
//#include "sequence_arithmetic_operator_test_template.hpp"
#undef ARITHMETIC_OPERATOR
#undef TEST_FIXTURE_NAME

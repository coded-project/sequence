/* Note: The lack of ifndef/define includsion guard is intentional!
 *
 * This file defines the template for the sequence compound assignment tests.
 * It is included with the preprocessor vairables 'COMPOUND_ASSIGNMENT_OPERATOR'
 * and 'TEST_FIXTURE_NAME' defined before it in order to setup this set
 * of tests in the appropriate way.
 * (It's an egregious hack to reduce test duplication, but we like it becuase it
 *  works!)
 */

#if defined COMPOUND_ASSIGNMENT_OPERATOR && defined TEST_FIXTURE_NAME

#include <gtest/gtest.h>

#include <sequence/sequence.hpp>

using namespace CodedProject;

class TEST_FIXTURE_NAME : public ::testing::Test
{
};

TEST_F(TEST_FIXTURE_NAME, built_in_type)
{
    auto lhs = Sequence<int>{10, 20, 30, 40};
    auto rhs = 2;

    auto expected = lhs;
    for(auto& element : expected)
        element COMPOUND_ASSIGNMENT_OPERATOR rhs;

    lhs COMPOUND_ASSIGNMENT_OPERATOR rhs;
    EXPECT_EQ( expected, lhs );
}

TEST_F(TEST_FIXTURE_NAME, sequence_type)
{
    auto lhs = Sequence<int>{10, 21, 24, 35};
    auto rhs = Sequence<int>{2, 3, 4, 5};

    auto expected = lhs;
    auto rhs_element = rhs.begin();
    for(auto& expected_element : expected)
    {
        expected_element COMPOUND_ASSIGNMENT_OPERATOR *rhs_element;
        ++rhs_element;
    }

    lhs COMPOUND_ASSIGNMENT_OPERATOR rhs;
    EXPECT_EQ( expected, lhs );
}

#endif

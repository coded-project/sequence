/* Copyright (c) 2014, Coded Project
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * * Neither the name of the Coded Project nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

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
    EXPECT_EQ(expected, lhs);
}

TEST_F(TEST_FIXTURE_NAME, sequence_binary_expression)
{
    auto lhs = Sequence<int>{10, 21, 24, 35};
    auto rhs1 = Sequence<int>{1,2,1,2} ;
    auto rhs2 = Sequence<int>{1,1,3,3};
    auto rhs_sequence_binary_expression = rhs1 + rhs2;

    auto expected = lhs;
    auto i=0;
    for( auto& expected_element : expected)
    {
        expected_element COMPOUND_ASSIGNMENT_OPERATOR rhs_sequence_binary_expression.at(i);
        ++i;
    }

    lhs COMPOUND_ASSIGNMENT_OPERATOR rhs_sequence_binary_expression;
    EXPECT_EQ(expected, lhs);
}

#endif

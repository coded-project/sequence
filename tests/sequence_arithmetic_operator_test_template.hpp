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
 * It is included with the preprocessor vairables 'ARITHMETIC_OPERATOR'
 * and 'TEST_FIXTURE_NAME' defined before it in order to setup this set
 * of tests in the appropriate way.
 * (It's an egregious hack to reduce test duplication, but we like it becuase it
 *  works!)
 */

#if defined ARITHMETIC_OPERATOR && defined TEST_FIXTURE_NAME

#include <gtest/gtest.h>

#include <sequence/sequence.hpp>

using namespace CodedProject;

class TEST_FIXTURE_NAME : public ::testing::Test
{
};

TEST_F(TEST_FIXTURE_NAME, Sequence_with_Sequence )
{
    auto seq1 = Sequence<int>{10, 21, 36};
    auto seq2 = Sequence<int>{2, 3, 4};
    
    auto expected = seq1;
    auto seq2_element = seq2.begin();
    for(auto& expected_element : expected)
    {
        expected_element = expected_element ARITHMETIC_OPERATOR *seq2_element;
        ++seq2_element;
    }

    Sequence<int> seq3 = seq1 ARITHMETIC_OPERATOR seq2;
    EXPECT_EQ( expected, seq3 );
}
TEST_F(TEST_FIXTURE_NAME, Sequence_with_temporary_Sequence )
{
    auto seq1 = Sequence<int>{10, 21, 36};
    auto seq2 = Sequence<int>{2, 3, 4};
    
    auto expected = seq1;
    auto seq2_element = seq2.begin();
    for(auto& expected_element : expected)
    {
        expected_element = expected_element ARITHMETIC_OPERATOR *seq2_element;
        ++seq2_element;
    }

    Sequence<int> seq3 = seq1 ARITHMETIC_OPERATOR Sequence<int>{2, 3, 4};
    EXPECT_EQ( expected, seq3 );
}

TEST_F(TEST_FIXTURE_NAME, Sequence_With_SequenceExpression )
{
    auto sequence1 = Sequence<int>{20, 63, 144};
    auto sequence2 = Sequence<int>{4, 9, 16};
    auto sequence3 = Sequence<int>{2, 3, 4};

    auto sequenceExpression = sequence2 ARITHMETIC_OPERATOR sequence3;

    auto expected = sequence1;
    for(size_t i=0; i<sequence1.size(); ++i)
    {
        expected[i] = sequence1.at(i) ARITHMETIC_OPERATOR (sequence2.at(i) ARITHMETIC_OPERATOR sequence3.at(i));
    }

    Sequence<int> result = sequence1 ARITHMETIC_OPERATOR sequenceExpression;
    EXPECT_EQ( expected, result );
}

TEST_F(TEST_FIXTURE_NAME, SequenceExpression_With_Sequence)
{
    auto sequence1 = Sequence<int>{20, 63, 144};
    auto sequence2 = Sequence<int>{4, 9, 16};
    auto sequence3 = Sequence<int>{2, 3, 4};

    auto sequenceExpression = sequence1 ARITHMETIC_OPERATOR sequence2;

    auto expected = sequence1;
    for(size_t i=0; i<sequence1.size(); ++i)
    {
        expected[i] = (sequence1.at(i) ARITHMETIC_OPERATOR sequence2.at(i)) ARITHMETIC_OPERATOR sequence3.at(i);
    }

    Sequence<int> result = sequenceExpression ARITHMETIC_OPERATOR sequence3;
    EXPECT_EQ(expected, result);
}

TEST_F(TEST_FIXTURE_NAME, assign_expression_result_to_variable)
{
    auto sequence1 = Sequence<int>{20, 63, 144};
    auto sequence2 = Sequence<int>{2, 3, 4};
    auto result = Sequence<int>();

    auto expected = sequence1;
    for(size_t i=0; i<sequence1.size(); ++i)
    {
        expected[i] = sequence1.at(i) ARITHMETIC_OPERATOR sequence2.at(i);
    }

    result = sequence1 ARITHMETIC_OPERATOR sequence2;
    EXPECT_EQ(expected, result);
}

#endif

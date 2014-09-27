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

#include <gtest/gtest.h>

#include <sequence/sequence.hpp>

#include <iostream>

using namespace CodedProject;

class SequenceTest : public ::testing::Test
{
};

TEST_F(SequenceTest, default_construct)
{
    auto seq = Sequence<int>();
}

TEST_F(SequenceTest, default_fill_constructor)
{
    auto seq = Sequence<double>(2);
    EXPECT_EQ(2, seq.size());
}

TEST_F(SequenceTest, fille_construtor)
{
    auto seq = Sequence<float>(3, 4.0);
    EXPECT_DOUBLE_EQ(4.0, seq.at(2));
}

TEST_F(SequenceTest, range_constructor)
{
    auto otherSeq = Sequence<float>(3, 4.0);
    auto seq = Sequence<float>(otherSeq.begin(), otherSeq.end());
    EXPECT_DOUBLE_EQ(4.0, seq.at(1));
}

TEST_F(SequenceTest, initialiser_list_contructor)
{
    auto seq = Sequence<int>{1, 2, 3, 4, 5};
    EXPECT_EQ(5, seq.back());
}

TEST_F(SequenceTest, assign_from_built_in_type)
{
    auto sequence = Sequence<int>(3);
    sequence = 10;
    EXPECT_EQ(3, sequence.size());
    for(auto const& element : sequence)
        EXPECT_EQ(10, element);
}

TEST_F(SequenceTest, assign_from_another_built_in_type)
{
    auto lhs = Sequence<short>{10, 20, 30, 40};
    auto rhs = Sequence<int>{1, 2, 3, 4, 5};
    lhs = rhs;
    ASSERT_EQ(rhs.size(), lhs.size());
    auto rhs_element = rhs.begin();
    for(auto const& lhs_element : lhs)
    {
        EXPECT_DOUBLE_EQ( *rhs_element, lhs_element );
        ++rhs_element;
    }
}

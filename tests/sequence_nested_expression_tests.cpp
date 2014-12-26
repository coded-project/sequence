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

using namespace CodedProject;

class SequenceNestedExpressionTest : public ::testing::Test
{
};

/*
 * The nested expression tests here don't test anything new...
 * They're only useful as a way to profile the performance of
 * different versions of CodedProject::Sequence.
 * In the future a proper method for profiling should probably
 * be introduced...
 */

TEST_F(SequenceNestedExpressionTest, binary_expression)
{
    int n=100000;
    auto a = Sequence<double>(n, 10);
    auto b = Sequence<double>(n, 10);

    //auto r = a+b;

    Sequence<double> result = a+b;
    //EXPECT_EQ(20, result.at(0));
}

TEST_F(SequenceNestedExpressionTest, ternary_expression)
{
    int n=100000;
    auto a = Sequence<double>(n, 10);
    auto b = Sequence<double>(n, 10);
    auto c = Sequence<double>(n, 5);
    Sequence<double> result = a+b-c;
    EXPECT_EQ(15, result.at(0));
}

TEST_F(SequenceNestedExpressionTest, very_long_expression)
{
    int n = 10000000;

    auto a = Sequence<double>(n, 10);
    auto b = Sequence<double>(n, 10);
    auto c = Sequence<double>(n, 10);
    auto d = Sequence<double>(n, 10);
    auto e = Sequence<double>(n, 10);
    auto f = Sequence<double>(n, 10);
    auto g = Sequence<double>(n, 10);
    auto h = Sequence<double>(n, 10);
    auto i = Sequence<double>(n, 10);
    auto j = Sequence<double>(n, 10);
    auto k = Sequence<double>(n, 10);
    auto l = Sequence<double>(n, 10);

    auto result = Sequence<double>();
    result = (a+b+c+d+e)*((f+g+h)-(i+j+k)/l);
    EXPECT_EQ( result.at(0), 50*(30-3) );
}

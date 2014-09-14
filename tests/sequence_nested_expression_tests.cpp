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
    int n = 100000;

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

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

#ifndef CODEDPROJECT_SEQUENCE_EXPRESSION_TRAITS_HPP
#define CODEDPROJECT_SEQUENCE_EXPRESSION_TRAITS_HPP

namespace CodedProject
{

template<typename T>
struct SequenceExpressionTraits
{
    static bool const is_sequence = std::false_type::value;
    typedef T value_type;
    // The size_type of a vector is used here since this will only
    // be accessed if a non-Sequence is being used as part of a
    // SequenceExpression (i.e. it will become a sequence).
    // Therefore we want it's size type to be the same as that of a
    // Sequence (i.e. a vector's size_type).
    typedef typename std::vector<T>::size_type size_type;
};

template<typename T>
struct SequenceExpressionTraits<Sequence<T>>
{
    static bool const is_sequence = std::true_type::value;
    typedef typename std::vector<T>::value_type value_type;
    typedef typename std::vector<T>::size_type size_type;
};

template<typename LHS, typename RHS, typename OperationType>
struct SequenceExpressionTraits<SequenceBinaryExpression<LHS,RHS,OperationType>>
{
    static bool const is_sequence = std::true_type::value;
    typedef typename LHS::value_type value_type;
    typedef typename LHS::size_type size_type;
};

template<typename LHS, typename RHS, typename OperationType>
struct SequenceExpressionTraits<SequenceBinaryExpressionWithConstantRHS<LHS,RHS,OperationType>>
{
    static bool const is_sequence = std::true_type::value;
    typedef typename LHS::value_type value_type;
    typedef typename LHS::size_type size_type;
};

template<typename LHS, typename RHS, typename OperationType>
struct SequenceExpressionTraits<SequenceBinaryExpressionWithConstantLHS<LHS,RHS,OperationType>>
{
    static bool const is_sequence = std::true_type::value;
    typedef typename RHS::value_type value_type;
    typedef typename RHS::size_type size_type;
};

}

#endif

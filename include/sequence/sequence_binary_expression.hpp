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

#ifndef CODEDPROJECT_SEQUENCE_BINARY_EXPRESSION_HPP
#define CODEDPROJECT_SEQUENCE_BINARY_EXPRESSION_HPP

#include "sequence_binary_expression_traits.hpp"

namespace CodedProject
{

template<typename LHS, typename RHS, typename OperationTypem, typename EnableSpeicialisation=void>
class SequenceBinaryExpression;

template<typename LHS, typename RHS, typename OperationType>
class SequenceBinaryExpression<LHS,
                               RHS,
                               OperationType,
                               typename std::enable_if< SequenceExpressionTraits<LHS>::is_sequence
                                                     && SequenceExpressionTraits<RHS>::is_sequence >::type>
    : public SequenceExpression<SequenceBinaryExpression<LHS,RHS,OperationType>>
{
    LHS const& lhs_;
    RHS const& rhs_;
    OperationType const& operation_;
public:
    typedef typename SequenceBinaryExpressionTraits<LHS,RHS>::value_type value_type;
    typedef typename SequenceBinaryExpressionTraits<LHS,RHS>::size_type size_type;

    SequenceBinaryExpression(LHS const& lhs,
                             RHS const& rhs,
                             OperationType const& operation=OperationType()) :
        lhs_(lhs),
        rhs_(rhs),
        operation_(operation)
    {
        assert(lhs_.size()==rhs_.size());
    }

    size_type size() const
    {
        return lhs_.size();
    }

    value_type at(size_type i) const
    {
        return operation_(lhs_.at(i), rhs_.at(i));
    }
};

template<typename LHS, typename RHS, typename OperationType>
class SequenceBinaryExpression<LHS,
                               RHS,
                               OperationType,
                               typename std::enable_if< SequenceExpressionTraits<LHS>::is_sequence
                                                     && !SequenceExpressionTraits<RHS>::is_sequence >::type>
    : public SequenceExpression<SequenceBinaryExpression<LHS,RHS,OperationType>>
{
    LHS const& lhs_;
    RHS const& rhs_;
    OperationType const& operation_;
public:
    typedef typename SequenceBinaryExpressionTraits<LHS,RHS>::value_type value_type;
    typedef typename SequenceBinaryExpressionTraits<LHS,RHS>::size_type size_type;

    SequenceBinaryExpression(LHS const& lhs,
                             RHS const& rhs,
                             OperationType const& operation=OperationType()) :
        lhs_(lhs),
        rhs_(rhs),
        operation_(operation)
    {
    }

    size_type size() const
    {
        return lhs_.size();
    }

    value_type at(size_type i) const
    {
        return operation_(lhs_.at(i), rhs_);
    }
};

template<typename LHS, typename RHS, typename OperationType>
class SequenceBinaryExpression<LHS,
                               RHS,
                               OperationType,
                               typename std::enable_if< !SequenceExpressionTraits<LHS>::is_sequence
                                                     && SequenceExpressionTraits<RHS>::is_sequence >::type>
    : public SequenceExpression<SequenceBinaryExpression<LHS,RHS,OperationType>>
{
    LHS const& lhs_;
    RHS const& rhs_;
    OperationType const& operation_;
public:
    typedef typename SequenceBinaryExpressionTraits<LHS,RHS>::value_type value_type;
    typedef typename SequenceBinaryExpressionTraits<LHS,RHS>::size_type size_type;

    SequenceBinaryExpression(LHS const& lhs,
                             RHS const& rhs,
                             OperationType const& operation=OperationType()) :
        lhs_(lhs),
        rhs_(rhs),
        operation_(operation)
    {
    }

    size_type size() const
    {
        return rhs_.size();
    }

    value_type at(size_type i) const
    {
        return operation_(lhs_, rhs_.at(i));
    }
};

}

#endif

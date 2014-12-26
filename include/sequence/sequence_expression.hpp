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

#ifndef CODEDPROJECT_SEQUENCE_EXPRESSION_HPP
#define CODEDPROJECT_SEQUENCE_EXPRESSION_HPP

namespace CodedProject
{

template<typename E>
class SequenceExpression
{
public:
    typedef typename SequenceExpressionTraits<E>::value_type value_type;
    typedef typename SequenceExpressionTraits<E>::size_type size_type;

    size_type size() const;
    value_type at(size_type i) const;
    value_type operator[] (size_type i) const;
    operator E const& () const;
};

template<typename E>
typename SequenceExpression<E>::size_type SequenceExpression<E>::size() const
{
    return static_cast<E const&>(*this).size();
}

template<typename E>
typename SequenceExpression<E>::value_type SequenceExpression<E>::at(size_type i) const
{
    return static_cast<E const&>(*this).at(i);
}

template<typename E>
typename SequenceExpression<E>::value_type SequenceExpression<E>::operator[] (size_type i) const
{
  return static_cast<E const&>(*this)[i];
}

template<typename E>
SequenceExpression<E>::operator E const&() const
{
    return static_cast<E const&>(*this);
}

}

#endif

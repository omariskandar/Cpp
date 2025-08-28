/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:52:14 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/28 16:34:49 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& rhs);
        ~Span();

        void addNumber(int nb);

        template <typename InputIterator>
        void addRange(InputIterator begin, InputIterator end) {
            if (_numbers.size() + std::distance(begin, end) > _capacity)
                throw std::overflow_error("Not enough space to add range");
            _numbers.insert(_numbers.end(), begin, end);
        }

        int shortestSpan();
        int longestSpan();

        unsigned int size() const { return _numbers.size(); }

    private:
        unsigned int    _capacity;
        std::vector<int> _numbers;
};

#endif

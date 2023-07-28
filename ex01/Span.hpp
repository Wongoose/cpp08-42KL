/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:17:50 by zwong             #+#    #+#             */
/*   Updated: 2023/07/28 15:39:13 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <vector>

#define RESET "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class Span {
    public:
        // Constructors
        Span();
        Span(const unsigned int &n); // the only
        Span(const Span &copy);

        // Destructor
        ~Span();

        // Operators
        Span &operator=(const Span &other);

        // Getters
        int size(void) const;

        // Setters

        // Functions
        void addNumber(const int &num);
        void fillNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end);
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void printContents();

        // Exceptions
        class OutOfCapacityException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class NoPossibleSpanException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

    private:
        unsigned int _size;
        std::vector<int> _container;
};
#endif
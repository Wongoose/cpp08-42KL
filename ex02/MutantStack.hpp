/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:25:05 by zwong             #+#    #+#             */
/*   Updated: 2023/08/08 13:36:50 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <stack>
#include <list>

#define RESET "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        // Constructors
        MutantStack() {};
        MutantStack(const MutantStack &copy) { *this = copy; };

        // Destructor
        virtual ~MutantStack() {};

        // Operators
        MutantStack &operator=(const MutantStack &other) {
            std::stack<T>::operator=(other); // don't understand this part
            return (*this);
        };

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        // Getters

        // Setters

        // Functions
        iterator begin(void) { return (std::stack<T>::c.begin()); }
        iterator end(void) { return (std::stack<T>::c.end()); }
        const_iterator begin(void) const { return (std::stack<T>::c.begin()); }
        const_iterator end(void) const { return (std::stack<T>::c.end()); }
        reverse_iterator rbegin(void) { return (std::stack<T>::c.rbegin()); }
        reverse_iterator rend(void) { return (std::stack<T>::c.rend()); }
        const_reverse_iterator rbegin(void) const { return (std::stack<T>::c.rbegin()); }
        const_reverse_iterator rend(void) const { return (std::stack<T>::c.rend()); }
};

#endif

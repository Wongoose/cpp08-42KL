/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:17:47 by zwong             #+#    #+#             */
/*   Updated: 2023/07/28 15:17:53 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(const unsigned int &n) : _size(n) {}

Span::Span(const Span &copy) : _size(copy.size()), _container(copy._container) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
    _size = other.size();
    this->_container = other._container; // why error when using std::swap
    return (*this);
}

// Getters
int Span::size(void) const { return (_size); };

// Functions
void Span::addNumber(const int &num) {
    if (_container.size() >= _size)
        throw (OutOfCapacityException()); // throw exception
    this->_container.push_back(num);
}

unsigned int Span::shortestSpan() {
    if (_container.size() < 2) throw (NoPossibleSpanException());
    unsigned int shortestSpan;
    std::vector<int> sorted = _container;
    std::sort(sorted.begin(), sorted.end()); // at this point it is sorted
    // Iterators
    std::vector<int>::iterator head = sorted.begin(); // using sorted from now on
    std::vector<int>::iterator end = sorted.end();
    shortestSpan = *(head + 1) - *head; // difference of the first 2 smallest numbers in the sorted vector
    head++; // Check if there are other smaller spans (e.g. [1, 12, 13])
    for (; head < end; head++) {
        unsigned int diff = *(head + 1) - *head;
        if (diff < shortestSpan)
            shortestSpan = diff;
    }
    return (shortestSpan);
}

unsigned int Span::longestSpan() {
    if (_container.size() < 2) throw (NoPossibleSpanException());
    int min = *std::min_element(_container.begin(), _container.end());
    int max = *std::max_element(_container.begin(), _container.end());
    
    return (static_cast<unsigned int>(max - min));
}

void Span::printContents() {
  std::vector<int>::const_iterator it;
  std::vector<int>::const_iterator end = this->_container.end();
  std::cout << CYAN << "Container contents:" << std::endl << RESET;
  for (it = this->_container.begin(); it < end; it++) {
    std::cout << *it << std::endl;
  }
}

// Exceptions
const char *Span::OutOfCapacityException::what() const throw() {
  return "Capacity is full bro!";
}

const char *Span::NoPossibleSpanException::what() const throw() {
  return "Less than 2 number, cannot calculate span!";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:35:20 by zwong             #+#    #+#             */
/*   Updated: 2023/07/28 15:22:36 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Learning how to use iterator and algorithm logic
// Span is basically just the range between a set of numbers
// Hence, shortestSpan() will compare all the numbers and find the smallest difference in value
int main() {
    std::cout << MAGENTA << "----- TESTING BASICS -----" << std::endl << RESET;
    std::cout << YELLOW << "Adding number into span..." << std::endl << RESET;
    Span span = Span(10);
    std::cout << GREEN << "Span created with size: " << span.size() << std::endl << RESET;
    try {
        span.addNumber(15);
        span.addNumber(10);
        span.addNumber(17);
        span.addNumber(8);
        span.addNumber(6);
        span.addNumber(6);
        span.addNumber(-10);
    } catch (std::exception &err) {
        std::cout << RED << "Failed with catch error: " << err.what() << std::endl << RESET;
    }
    span.printContents();
    std::cout << YELLOW << "Calculating shortest and longest span..." << std::endl << RESET;
    std::cout << GREEN << "Shortest span is: " << span.shortestSpan() << std::endl << RESET;
    std::cout << GREEN << "Longest span is: " << span.longestSpan() << std::endl << RESET;
    std::cout << std::endl;

    std::cout << MAGENTA << "----- TESTING DEEP COPY -----" << std::endl << RESET;
    Span copy = span;
    std::cout << YELLOW << "Adding number to copy..." << std::endl << RESET;
    try {
        copy.addNumber(42);
    } catch (std::exception &err) {
        std::cout << RED << "Failed with catch error: " << err.what() << std::endl << RESET;
    }
    std::cout << YELLOW << "Original span contents..." << std::endl << RESET;
    span.printContents();
    std::cout << YELLOW << "Copy span contents..." << std::endl << RESET;
    copy.printContents();
    std::cout << GREEN << "YES, it is deep copy!" << std::endl << RESET;
    std::cout << std::endl;
    return (0);
}

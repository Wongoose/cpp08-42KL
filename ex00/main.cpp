/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:35:20 by zwong             #+#    #+#             */
/*   Updated: 2023/10/18 14:48:37 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

// Learning about iterator and algorthims
// Container is just a term used in the subject to describe an group of content
// Vector vs list?
// std::vector/list (library) comes with it's own iterator (aka. librarian) *which helps to look for books
// Agree on one standard e.g. begin(), end()... (in base::iterator)
// Linklist vs iterator (generic, doesn't hold value)
int main() {
    std::cout << MAGENTA << "----- TESTING WITH VECTOR -----" << std::endl << RESET;
    std::vector<int> vector; // what is std::vector?
    std::cout << YELLOW << "Pushing integers into vector container..." << std::endl << RESET;
    vector.push_back(0);
    vector.push_back(2);
    vector.push_back(42);
    vector.push_back(3);
    vector.push_back(4);
    vector.push_back(5);
    vector.push_back(6);
    vector.push_back(7);
    std::cout << YELLOW << "Finding number '42' in vector container..." << std::endl << RESET;
    try {
        std::cout << GREEN << "Found number: " << *easyfind(vector, 42) << std::endl << RESET;
        std::cout << GREEN << "Found number (+ 2 steps): " << *(easyfind(vector, 42) += 2) << std::endl << RESET; // adding unto the T::iterator result will move up the list
    } catch (std::exception &err) {
        std::cout << RED << "Failed easyfind() with catch error: " << err.what() << std::endl << RESET;
    }
    std::cout << std::endl;

    std::cout << MAGENTA << "----- TESTING WITH LIST -----" << std::endl << RESET;
    std::list<int> list;
    std::cout << YELLOW << "Pushing integers into list container..." << std::endl << RESET;
    list.push_back(1);
    list.push_back(0);
    list.push_back(2);
    list.push_back(0);
    list.push_back(42);
    list.push_back(7);
    list.push_back(0);
    list.push_back(4);
    std::cout << YELLOW << "Finding number '42' in list container..." << std::endl << RESET;
    try {
        std::cout << GREEN << "Found number: " << *easyfind(list, 42) << std::endl << RESET;
        std::cout << GREEN << "Found number (+ 1 step): " << *(++easyfind(list, 42)) << std::endl << RESET; // increment the T::iterator result will move up the list
    } catch (std::exception &err) {
        std::cout << RED << "Failed easyfind() with catch error: " << err.what() << std::endl << RESET;
    }
    
    // Not in container
    std::cout << YELLOW << "Finding number '1000' in list container..." << std::endl << RESET;
    try {
        std::list<int>::iterator temp = easyfind(list, 1000);
        std::cout << GREEN << "Found number: " << *temp << std::endl << RESET;
        std::cout << GREEN << "Found number: " << *(++temp) << std::endl << RESET; // increment the T::iterator result will move up the list
    } catch (std::exception &err) {
        std::cout << RED << "Failed easyfind() with catch error: " << err.what() << std::endl << RESET;
    }
    std::cout << std::endl;
    return (0);
}

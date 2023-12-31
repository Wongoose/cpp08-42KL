/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:35:20 by zwong             #+#    #+#             */
/*   Updated: 2023/10/18 15:34:16 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// There's vector, list, now stack
// Problem is: std::stack does not have it's own iterator!!! (extra useful feature to loop)
// Objective: Use an iterator for stack, MutantStack extends std::stack
int main() {
    std::cout << MAGENTA << "----- TESTING BASICS OF STACK -----" << std::endl << RESET;
    std::cout << YELLOW << "Adding number into Mutant Stack..." << std::endl << RESET;
    MutantStack<int> mstack;
    
    mstack.push(5); // numbers are pushed to the top of the stack
    mstack.push(17);

    std::cout << YELLOW << "Printing top of Mutant Stack then pop()..." << std::endl << RESET;
    std::cout << mstack.top() << std::endl; // 17 is on top
    mstack.pop(); // will pop top number of the stack

    std::cout << YELLOW << "Printing size of Mutant Stack..." << std::endl << RESET;
    std::cout << GREY << "Size is: " << mstack.size() << std::endl << RESET;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin(); // beginning is bottom of the stack
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << YELLOW << "Printing all numbers in Mutant Stack..." << std::endl << RESET;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack); // this is checking if MutantStack is derived from std::stack
    std::cout << std::endl;

    std::cout << MAGENTA << "----- COMPARING BASICS OF LIST -----" << std::endl << RESET;
    std::cout << YELLOW << "Adding number into List..." << std::endl << RESET;
    std::list<int> list;
    
    list.push_back(5); // numbers are push_backe to the back of the stack
    list.push_back(17);

    std::cout << YELLOW << "Printing end of List then pop()..." << std::endl << RESET;
    std::cout << *--list.end() << std::endl;
    list.pop_back(); // will pop last number of the list

    std::cout << YELLOW << "Printing size of List..." << std::endl << RESET;
    std::cout << GREY << "Size is: " << list.size() << std::endl << RESET;

    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    
    std::list<int>::iterator list_head = list.begin();
    std::list<int>::iterator list_end = list.end();
    ++list_head;
    --list_head;
    std::cout << YELLOW << "Printing all numbers in List..." << std::endl << RESET;
    while (list_head != list_end)
    {
        std::cout << *list_head << std::endl;
        ++list_head;
    }
    return (0);
}

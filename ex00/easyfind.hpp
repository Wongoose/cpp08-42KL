/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:29:35 by zwong             #+#    #+#             */
/*   Updated: 2023/07/28 11:59:13 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <iterator>
#include <algorithm>
#include <iostream>
#include <vector>
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

template<typename T>
typename T::iterator easyfind(T &container, const int &i) {
    typename T::iterator result = std::find(container.begin(), container.end(), i);
    if (result == container.end())
        throw (std::out_of_range("Cannot find target in container!"));
    return (result);
}

#endif

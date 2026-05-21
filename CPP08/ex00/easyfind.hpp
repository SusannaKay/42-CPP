#ifndef EASYFIND_HPP
# define EASYFIND_HPP


#include <algorithm>
#include <exception>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T& container, int toFind) {
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), toFind);
    if (it != container.end())
        return(it);
    throw (std::exception());
}

#endif
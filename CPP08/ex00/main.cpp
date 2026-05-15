#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void)
{
    int value = 42;
    std::vector<int> v = {1, 3, 7, 9};

    try 
    {
        ::easyfind(v, value);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::list<int> d;
    d.push_back(1);
    d.push_back(3);
    d.push_back(42);
    d.push_back(5);
    try 
    {
        ::easyfind(d, value);
        std::cout << "Value " << value << " Found" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}
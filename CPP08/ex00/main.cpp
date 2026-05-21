#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{
    int value = 42;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(7);
    v.push_back(9);

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
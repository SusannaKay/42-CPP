#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));

    try
    {
        Span sp(10000);

        std::vector<int> numbers;

        for (int i = 0; i < 10000; i++)
            numbers.push_back(rand());
        for (int i = 0; i < 10; i++)
            std::cout << numbers[i] << std::endl;

        sp.addRange(numbers.begin(), numbers.end());

        std::cout << "Shortest span: "
                  << sp.shortestSpan() << std::endl;

        std::cout << "Longest span: "
                  << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}
#include "PmergeMe.hpp"
#include <cstdlib>
#include <limits.h>
// static void printPairs(const std::vector<std::pair<int, int> > &pairs)
// {
//     for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin();
//          it != pairs.end();
//          ++it)
//     {
//         std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
//     }
// }

static bool isInvalid(long num)
{
    return (num < 0 || num > INT_MAX);
}

int main(int argc, char **argv)
{

    std::vector<int> input;

    if (argc < 2)
    {
        std::cerr << "Invalid Input" << std::endl;
        return 1;
    }
    for (int i = 1; argv[i]; i++)
    {
        try
        {
            char *end;
            long num = std::strtol(argv[i], &end, 10);
            if (isInvalid(num) || *end != '\0')
                throw PmergeMe::InvalidInput();
            int n = static_cast<int>(num);
            input.push_back(n);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return 1;
        }
    }
    try
    {
        PmergeMe test(input);
        // printPairs(test._vect);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}


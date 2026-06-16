#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
        try
        {
            RPN ss(argv[1]);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    else
    {
        std::cerr << "Invalid Input" << std::endl;
        return 1;
    }
}
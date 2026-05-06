#include "Base.hpp"

int main (void)
{
    Base *p;
    srand(time(NULL));

    p = generate();
    std::cout << "==Test ref==\n";
    identify(*p);
    std::cout << "==Test pointer==\n";
    identify(p);

    delete p;

}
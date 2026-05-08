#include "iter.hpp"

int main (void){

    const int array[4] = { 1, 2, 3, 4};
    iter(array,4, print<int>);

    const std::string ciccio[3] = {"Ciao     \n", "Evaluator  \n", "Come stai?"};
    iter(ciccio,3,print<const std::string>);

}
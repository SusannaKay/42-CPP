#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <utility>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>

class PmergeMe{

    private:

    int _left;
    std::vector<std::pair <int, int> > _vect;
    std::deque<std::pair <int, int> > _deq;

    public:

    PmergeMe();
    PmergeMe(std::vector<int> input);
    PmergeMe(const PmergeMe &other);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &other);

    void process();
    void processVector();
    void processDeque();

    void mainDeque(std::deque<int> &mainchain, std::deque<int> &pending);
    void mainVector(std::vector<int> &mainchain, std::vector<int> &pending);


    class InvalidInput : public std::exception {
        virtual const char *what() const throw();
    };
};

#endif
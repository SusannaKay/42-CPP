#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> input) : _left(-1)
{

    if (input.size() % 2 != 0)
        _left = input[input.size() - 1];
    std::pair<int, int> p;
    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        int a = input[i];
        int b = input[i + 1];
        if (a < b)
            p = std::make_pair(a, b);
        else
            p = std::make_pair(b, a);
        _vect.push_back(p);
        _deq.push_back(p);
    }
}

PmergeMe::PmergeMe(PmergeMe &other)
{
    if (this != &other)
    {
        _vect = other._vect;
        _deq = other._deq;
    }
}

PmergeMe &PmergeMe::operator=(PmergeMe &other)
{

    if (this != &other)
    {
        _vect = other._vect;
        _deq = other._deq;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

static bool comparePair(const std::pair<int, int> &a, const std::pair<int, int> &b){

    return (a.second < b.second);
}

void PmergeMe::mainVector(std::vector<int> &mainchain, std::vector<int> &pending){

    mainchain.push_back(_vect[0].first);
    for (size_t i = 0; i < _vect.size(); i++)
        mainchain.push_back(_vect[i].second);
    for (size_t i = 1; i < _vect.size(); i++)
        pending.push_back(_vect[i].first);
}
void PmergeMe::mainDeque(std::deque<int> &mainchain, std::deque<int> &pending){

    mainchain.push_back(_deq[0].first);
    for (size_t i = 0; i < _deq.size(); i++)
        mainchain.push_back(_deq[i].second);
    for (size_t i = 1; i < _deq.size(); i++)
        pending.push_back(_deq[i].first);
}


void PmergeMe::processVector(){
    std::vector<int> mainchain;
    std::vector<int> pending;

    std::sort(_vect.begin(), _vect.end(), comparePair);
    mainVector(mainchain, pending);
}
void PmergeMe::processDeque(){
    std::deque<int> mainchain;
    std::deque<int> pending;

    std::sort(_deq.begin(), _deq.end(), comparePair);
    mainDeque(mainchain, pending);
}

void PmergeMe::process(){
    processVector();
    processDeque();
}

const char *PmergeMe::InvalidInput::what() const throw()
{
    return ("Invalid Input");
}


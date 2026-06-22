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

PmergeMe::PmergeMe(const PmergeMe &other)
{
    if (this != &other)
    {
        _vect = other._vect;
        _deq = other._deq;
        _left = other._left;
    }
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{

    if (this != &other)
    {
        _vect = other._vect;
        _deq = other._deq;
        _left = other._left;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

template <typename T>
static void printCont(const T &pairs)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::cout << pairs[i] << std::endl;
    }
}

static std::vector<size_t> jacobOrder(size_t size){
    std::vector<size_t> order;
    order.push_back(0);
    order.push_back(1);
    for (size_t i = 2; i <= size; i++){
        size_t n = order[i -1] + (2 * order[i - 2]);
        order.push_back(n);
    }
    printCont(order);
    return order;

}

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
    std::vector<int>::iterator it;

    std::sort(_vect.begin(), _vect.end(), comparePair);
    mainVector(mainchain, pending);
    
    for (size_t i = 0; i < pending.size(); i++){
        it = lower_bound(mainchain.begin(), mainchain.end(), pending[i]);
        mainchain.insert(it, pending[i]);
    }
    if(_left >= 0)
    {
        it = lower_bound(mainchain.begin(), mainchain.end(), _left);
        mainchain.insert(it, _left);
    }
    jacobOrder(pending.size());
}
void PmergeMe::processDeque(){
    std::deque<int> mainchain;
    std::deque<int> pending;
    std::deque<int>::iterator it;

    std::sort(_deq.begin(), _deq.end(), comparePair);
    mainDeque(mainchain, pending);
    for ( size_t i = 0; i < pending.size(); i++){
        it = lower_bound(mainchain.begin(), mainchain.end(), pending[i]);
        mainchain.insert(it, pending[i]);
    }
    if (_left >= 0){
        it = lower_bound(mainchain.begin(), mainchain.end(), _left);
        mainchain.insert(it, _left);
    }
    //printCont(mainchain);

}

void PmergeMe::process(){
    processVector();
    processDeque();
}

const char *PmergeMe::InvalidInput::what() const throw()
{
    return ("Invalid Input");
}


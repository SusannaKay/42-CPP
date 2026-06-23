#include "PmergeMe.hpp"

/*----------------------------------------------------------------------------------*/
/*                                CANONICAL FORM                                    */
/*----------------------------------------------------------------------------------*/

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

/*----------------------------------------------------------------------------------*/
/*                                SORTING  UTILS                                    */
/*----------------------------------------------------------------------------------*/

static bool comparePair(const std::pair<int, int> &a, const std::pair<int, int> &b)
{

    return (a.second < b.second);
}

/*----------------------------------------------------------------------------------*/
/*                                VECTOR SORTING                                    */
/*----------------------------------------------------------------------------------*/



static std::vector<size_t> jacobVect(size_t size)
{
    std::vector<size_t> order;
    std::vector<size_t> final;

    if (size == 0)
        return final;
    order.push_back(0);
    order.push_back(1);
    while (order.back() < size)
    {
        size_t n = order[order.size() - 1] + (2 * order[order.size() - 2]);
        order.push_back(n);
    }
    final.push_back(1);
    for (size_t i = 2; i < order.size(); i++)
    {
        size_t current = order[i];
        size_t prev = order[i - 1];
        if (current > size)
            current = size;
        while (current > prev)
        {
            final.push_back(current);
            current--;
        }
    }
    return final;
}

void PmergeMe::mainVector(std::vector<int> &mainchain, std::vector<int> &pending)
{

    mainchain.push_back(_vect[0].first);
    for (size_t i = 0; i < _vect.size(); i++)
        mainchain.push_back(_vect[i].second);
    for (size_t i = 1; i < _vect.size(); i++)
        pending.push_back(_vect[i].first);
}

std::vector<int> PmergeMe::processVector()
{
    std::vector<int> mainchain;
    std::vector<int> pending;
    std::vector<int>::iterator it;

    std::sort(_vect.begin(), _vect.end(), comparePair);
    mainVector(mainchain, pending);
    std::vector<size_t> jacob = jacobVect(pending.size());

    for (size_t i = 0; i < jacob.size(); i++)
    {
        size_t id = jacob[i] - 1;
        it = lower_bound(mainchain.begin(), mainchain.end(), pending[id]);
        mainchain.insert(it, pending[id]);
    }
    if (_left >= 0)
    {
        it = lower_bound(mainchain.begin(), mainchain.end(), _left);
        mainchain.insert(it, _left);
    }
    return mainchain;
}

/*----------------------------------------------------------------------------------*/
/*                                DEQUE  SORTING                                    */
/*----------------------------------------------------------------------------------*/

static std::deque<size_t> jacobDeq(size_t size)
{
    std::deque<size_t> order;
    std::deque<size_t> final;

    if (size == 0)
        return final;
    order.push_back(0);
    order.push_back(1);
    while (order.back() < size)
    {
        size_t n = order[order.size() - 1] + (2 * order[order.size() - 2]);
        order.push_back(n);
    }
    final.push_back(1);
    for (size_t i = 2; i < order.size(); i++)
    {
        size_t current = order[i];
        size_t prev = order[i - 1];
        if (current > size)
            current = size;
        while (current > prev)
        {
            final.push_back(current);
            current--;
        }
    }
    return final;
}

void PmergeMe::mainDeque(std::deque<int> &mainchain, std::deque<int> &pending)
{

    mainchain.push_back(_deq[0].first);
    for (size_t i = 0; i < _deq.size(); i++)
        mainchain.push_back(_deq[i].second);
    for (size_t i = 1; i < _deq.size(); i++)
        pending.push_back(_deq[i].first);
}

std::deque<int> PmergeMe::processDeque()
{
    std::deque<int> mainchain;
    std::deque<int> pending;
    std::deque<int>::iterator it;

    std::sort(_deq.begin(), _deq.end(), comparePair);
    mainDeque(mainchain, pending);
    std::deque<size_t> jacob = jacobDeq(pending.size());

    for (size_t i = 0; i < jacob.size(); i++)
    {
        size_t id = jacob[i] - 1;
        it = lower_bound(mainchain.begin(), mainchain.end(), pending[id]);
        mainchain.insert(it, pending[id]);
    }
    if (_left >= 0)
    {
        it = lower_bound(mainchain.begin(), mainchain.end(), _left);
        mainchain.insert(it, _left);
    }
    return mainchain;
}

void PmergeMe::process()
{
    clock_t vecTime;
    clock_t deqTime;
    std::vector<int> mainchain;

    vecTime = clock();
    mainchain = processVector();
    vecTime = clock() - vecTime;
    std::cout << "After: ";
    printCont(mainchain);
    std::cout << "Time to process a range of " << mainchain.size() << " elements with std::vector<int> : "
              << (static_cast<double>(vecTime) / CLOCKS_PER_SEC) * 1000000.0 << " us" << std::endl;
    std::deque<int> mainchainDeq;
    deqTime = clock();
    mainchainDeq = processDeque();
    deqTime = clock() - deqTime;
    std::cout << "Time to process a range of " << mainchain.size() << " elements with std::deque<int> : "
              << (static_cast<double>(deqTime) / CLOCKS_PER_SEC) * 1000000.0 << " us" << std::endl;
}

/*----------------------------------------------------------------------------------*/
/*                                EXCEPTIONS                                        */
/*----------------------------------------------------------------------------------*/

const char *PmergeMe::InvalidInput::what() const throw()
{
    return ("Error");
}

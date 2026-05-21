#include "Span.hpp"

Span::Span(unsigned int size): _size(size){
    _numbers.reserve(_size);
    std::sort(_numbers.begin(), _numbers.end());
}

Span::Span(const Span &other){
    if(this != &other){
        _size = other._size;
        _numbers = other._numbers;
    }
}

Span &Span::operator=(const Span &other){
    if(this != &other){
        _size = other._size;
        _numbers = other._numbers;
    }
    return(*this);
}

Span::~Span(){
}

void Span::addNumber(int n){
    if (_numbers.size() != _size)
        _numbers.push_back(n);
    else
        throw SpanFull();
}

int Span::shortestSpan(){

        if (_numbers.size() > 2)
    {
        std::sort(_numbers.begin(), _numbers.end());
        int shortest = _numbers[1] - _numbers[0]; 
        for (size_t i = 1; i < _numbers.size(); i++)
        {
            if (_numbers[i + 1] - _numbers[i] < shortest && _numbers[i + 1])
                shortest = _numbers[i + 1] - _numbers[i];
        }
        return shortest;
    }
    else 
        throw NotEnoughNumbers();
}
int Span::longestSpan(){
    if (_numbers.size() < 2)
        throw NotEnoughNumbers();

    std::sort(_numbers.begin(), _numbers.end());
    int longest = _numbers[1] - _numbers[0]; 
    for (size_t i = 1; i < _numbers.size(); i++)
    {
        if (_numbers[i + 1] - _numbers[i] > longest && _numbers[i + 1])
            longest = _numbers[i + 1] - _numbers[i];
    }
    return longest;
}

const char *Span::NotEnoughNumbers::what() const throw(){
    return "Not enough numbers in span.";
}

const char *Span::SpanFull::what() const throw(){
    return "Span is full.";
}
#include "Span.hpp"

Span::Span(unsigned int size): _size(size){
    _numbers.reserve(_size);
    std::sort(_numbers.begin(), _numbers.end());
}

Span::Span(Span &other){
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




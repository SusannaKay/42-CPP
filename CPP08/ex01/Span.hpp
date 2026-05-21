#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <vector>
#include <algorithm>
# include <iostream>

class Span{

    private:

    unsigned int _size;
    std::vector<int> _numbers;
    
    public:

    Span(unsigned int size);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int n);
    int shortestSpan();
    int longestSpan();
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
        while (begin != end)
        {
            addNumber(*begin);
            ++begin;
        }
    }


    class SpanFull: public std::exception {
        virtual const char *what() const throw();
    };
    class NotEnoughNumbers: public std::exception {
        virtual const char *what() const throw();
    };

};

#endif
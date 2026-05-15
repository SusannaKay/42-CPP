#ifndef SPAN_HPP
# define SPAN_hpp

#include <exception>
#include <vector>
#include <algorithm>


class Span{

    private:

    unsigned int _size;
    std::vector<int> _numbers;
    
    public:

    Span(unsigned int size);
    Span(Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int n);
    int shortestSpan();
    int longestSpan();

    class SpanFull: public std::exception {
        virtual const char *what() const throw();
    };
    class NoSpan: public std::exception {
        virtual const char *what() const throw();
    };

};

#endif
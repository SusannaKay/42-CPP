#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>
#include <cctype>
#include <exception>

class RPN {

    private:

    std::stack<int> _num;
    

    public:

    RPN();
    RPN(std::string args);
    RPN(RPN &other);
    RPN &operator=(RPN &other);
    ~RPN();
    void createStack(std::string args);
    void solveOp(char op);


    class InvalidInput : public std::exception {
        virtual const char *what() const throw();

    };
};

#endif 
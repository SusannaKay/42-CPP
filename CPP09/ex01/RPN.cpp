# include "RPN.hpp"

RPN::RPN(){
}

RPN::RPN(std::string args){
    createStack(args);
}

RPN::RPN(RPN &other){
    if (this != &other)
        _num = other._num;
}

RPN &RPN::operator=(RPN &other){
        if (this != &other)
        _num = other._num;
    return(*this);
}

RPN::~RPN(){

}

static bool is_op(std::string token){
    return (token == "+" || token == "-" || token == "/" || token == "*");
}
int static calculate(int num1, char op, int num2){
    switch (op)
    {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0)
                throw RPN::InvalidInput();
            return num1 / num2;
        default:
            throw RPN::InvalidInput();
    }
}

void RPN::solveOp(char op){
        if(_num.size() >= 2)
        {
            int num2 = _num.top();
            _num.pop();
            int num1 = _num.top();
            _num.pop();
            _num.push(calculate(num1, op, num2));
        }
        else
            throw RPN::InvalidInput();
}

void RPN::createStack(std::string args){

    std::stringstream ss(args);
    std::string tmp;

    while (ss >> tmp){
        if (tmp.length() == 1)  
        {
            if (isdigit(tmp[0]))
                _num.push(tmp[0] - '0');
            else if (is_op(tmp))
                solveOp(tmp[0]);
            else
                throw RPN::InvalidInput();
        }
        else
        {
            throw RPN::InvalidInput();
        }
    }
    if (_num.size() != 1)
        throw RPN::InvalidInput();

    std::cout << _num.top() << std::endl;
}

const char *RPN::InvalidInput::what() const throw(){
    return ("Invalid input");
}
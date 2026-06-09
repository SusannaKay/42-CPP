#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <exception>
#include <sstream>
#include <cstdlib>

class bitExchange{

    private:

    std::map<std::string, double> prices;

    public:

    bitExchange();
    bitExchange(bitExchange &other);
    bitExchange &operator=(bitExchange &other);
    ~bitExchange();

    void parseDb();
    void printRes(std::ifstream &file);
    
    class CouldNotOpen: public std::exception {
        virtual const char *what() const throw();
    };
    class InvalidHeader: public std::exception {
        virtual const char *what() const throw();
    };
    class InvalidLine: public std::exception {
        virtual const char *what() const throw();
    };
    class InvalidYear: public std::exception {
        virtual const char *what() const throw();
    };
    class InvalidMonth: public std::exception {
        virtual const char *what() const throw();
    };
    class InvalidDay: public std::exception {
        virtual const char *what() const throw();
    };
    class InvalidDate: public std::exception {
        virtual const char *what() const throw();
    };
};

#endif

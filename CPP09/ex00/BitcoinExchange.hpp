#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <exception>
#include <sstream>

class bitExchange{

    private:

    std::map<std::string, double> prices;

    public:

    bitExchange(std::string db);
    bitExchange(bitExchange &other);
    bitExchange &operator=(bitExchange &other);
    ~bitExchange();

    std::map<std::string, double>::iterator parseDb();
    
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


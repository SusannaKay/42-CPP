#include "BitcoinExchange.hpp"

static int validateDate(std::string date){

    bool isLeap;
    long year;
    int month;
    int day;
    size_t pos = 0;
    char  *end = 0;

    pos = date.find('-');
    if (pos != 4)
        throw bitExchange::InvalidYear();
    year = std::strtol(date.substr(0, pos).c_str(), &end, 10);
    if (*end != '\0')
            throw bitExchange::InvalidYear();
    //check anno corretto ( atoi + range anno + set leap)
    pos++;
    pos = date.find('-');
    if (pos != 7)
        throw bitExchange::InvalidMonth();
    month = date.substr(pos, pos + 2);
    //check mese corretto 
    pos++;
    day = date.substr(pos, pos + 2);
    if (pos != (date.length() - 1))
        throw bitExchange::InvalidDay();
    //check giorno corretto ( check febbraio, check leap )
    if (isLeap)
    {
        if (month == "02")
        {
            if (day < 0 || day > 29)
                throw bitExchange::InvalidDay();
        }
        else if (month == )
    }




}

void bitExchange::parseDb(){
    
    std::fstream file;
    std::string line;

    file.open("data.csv", std::fstream::in);
    if(!file.is_open())
        throw bitExchange::CouldNotOpen();
    getline(file, line);
    if (line.compare("date,exchange_rate") != 0)
        throw bitExchange::InvalidHeader();
    while(getline(file, line)){
        int pos;
        std::string date;
        std::string valueStr;
        char *end;
        double value;

        pos = line.find(',');
        date = line.substr(0, pos);
        valueStr = line.substr(pos + 1, line.length());
        value = strtod(valueStr.c_str(), &end); 
        if (!validateDate(date) || *end != '\0' || value < 0)
            throw bitExchange::InvalidLine();
        prices[date] = value;
    }
    file.close();
}

const char *bitExchange::CouldNotOpen::what() const throw() {
    return("Failed to open file");
}
const char *bitExchange::InvalidHeader::what() const throw() {
    return("Invalid header in file");
}
const char *bitExchange::InvalidLine::what() const throw() {
    return("Invalid line in file");
}
const char *bitExchange::InvalidYear::what() const throw() {
    return("Invalid Year");
}
const char *bitExchange::InvalidMonth::what() const throw() {
    return("Invalid Month");
}
const char *bitExchange::InvalidDay::what() const throw() {
    return("Invalid Day");
}
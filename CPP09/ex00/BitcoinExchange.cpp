#include "BitcoinExchange.hpp"
static bool checkLeap(long year)
{
    if (year % 4 == 0)
        return (false);
    return (true);
}
static void validateDate(std::string date){

    long year;
    long month;
    long day;
    
    if (date.length() != 10)
        throw bitExchange::InvalidDate();

    if (date[4] != '-')
        throw bitExchange::InvalidYear();

    if (date[7] != '-')
        throw bitExchange::InvalidMonth();
    char  *end = NULL;

    year = std::strtol(date.substr(0, 4).c_str(), &end, 10);
    if (*end != '\0' || year < 2009 || year > 2022)
            throw bitExchange::InvalidYear();
    month = std::strtol(date.substr(5, 2).c_str(), &end, 10);
    if (*end != '\0' || month < 1 || month > 12)
        throw bitExchange::InvalidMonth();
    day = std::strtol(date.substr(8, 2).c_str(), &end, 10);
    if (*end != '\0' || day < 1 || day > 31)
        throw bitExchange::InvalidDay();
    int dayMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (checkLeap(year))
        dayMonth[1] = 29;
    if (day != dayMonth[month - 1])
        throw bitExchange::InvalidDay();
}

std::map<std::string, double>::iterator bitExchange::parseDb(){
    
    std::fstream file;
    std::string line;

    file.open("data.csv", std::fstream::in);
    if(!file.is_open())
        throw bitExchange::CouldNotOpen();
    getline(file, line);
    if (line.compare("date,exchange_rate") != 0)
        throw bitExchange::InvalidHeader();
    while (getline(file, line)){
        int pos;
        std::string date;
        std::string valueStr;
        char *end;
        double value;

        pos = line.find(',');
        date = line.substr(0, pos);
        valueStr = line.substr(pos + 1, line.length());
        value = strtod(valueStr.c_str(), &end); 
        if (*end != '\0' || value < 0)
            throw bitExchange::InvalidLine();
        try
        {
            validateDate(date);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }       
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
const char *bitExchange::InvalidDate::what() const throw() {
    return("Invalid Date");
}
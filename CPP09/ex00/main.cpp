#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main (int argc, char **argv){
	if (argc != 2)
	{
		std::cout << "Error:\n<usage>./btc <filename.txt>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	try
	{
		bitExchange change;
		std::string input;
		input = argv[1];
		change.printRes(file);
	}
	catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } 
	file.close();
	return(0);

}
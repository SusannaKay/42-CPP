#include <iostream>
#include <fstream>

int main (int argc, char **argv){
	if (argc != 2)
	{
		std::cout << "Error:\n<usage>./btc <filename.csv>" << std::endl;
	}
	std::string filename = argv[1];
	std::ofstream file(filename.c_str());
	if(!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
	}
	

}
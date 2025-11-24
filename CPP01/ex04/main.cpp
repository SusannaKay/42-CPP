/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:29:38 by skayed            #+#    #+#             */
/*   Updated: 2025/11/24 12:10:18 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int main (int argc, char**argv){

	std::string line;
	std::string s1;
	std::string s2;
	std::string filename;
	
	if (argc != 4){
		std::cout << "Usage: <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];		
	if (s1.length() == 0)
	{
		std::cout << "s1 should not be empty";
		return 1;
	}
	std::ifstream file(filename.c_str());
	if(!file.is_open()){
		std::cout << "Impossibile aprire il file" << std::endl;
		return 1;
	}
	std::string outname = filename + ".replace";
	std::ofstream new_file(outname.c_str());
	if(!new_file.is_open()){
		std::cout << "Errore new file" << std::endl;
		return (1);
	}
	while (std::getline(file, line)){
		std::string result;
		std::size_t pos = 0;
		std::size_t found = 0;
		while (1){
			found = line.find(s1, found);
			if (found == std::string::npos)
			{
				result += line.substr(pos);
				break;
			}
			result += line.substr(pos, found - pos);
			result += s2;
			pos = found + s1.length();
			found += s1.length();
		}
		new_file << result << std::endl;

	}
	return 0;
}
	
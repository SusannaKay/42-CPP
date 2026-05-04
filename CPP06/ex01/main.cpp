#include "serializer.hpp"
#include <iostream>

int main (void){
	
	Data *ptr = NULL;
	uintptr_t num;

	num = Serializer::serialize(ptr);

	std::cout << num << std::endl;

	ptr = Serializer::deserialize(num);

	std::cout << ptr << std::endl;

}
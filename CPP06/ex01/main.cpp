#include "serializer.hpp"
#include <iostream>

int main (void){
	
	Data* data = new Data;
	data->n = 42;

	uintptr_t serialized = Serializer::serialize(data);
	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "Serialized: " << serialized << std::endl;
	std::cout << "Deserialized: " << Serializer::serialize(deserialized) <<std::endl;
	std::cout << "\tInt: " << deserialized->n << std::endl;

	delete data;
	return 0;

}
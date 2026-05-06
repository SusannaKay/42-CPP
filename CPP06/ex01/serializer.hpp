#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "data.hpp"
#include <stdint.h>

class Serializer{

	private:
	Serializer();
	Serializer(Serializer &other);
	Serializer &operator=(Serializer &other);
	~Serializer();

	public:
	
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
#endif
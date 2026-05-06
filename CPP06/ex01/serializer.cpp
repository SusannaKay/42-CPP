#include "serializer.hpp"

Serializer::Serializer(){}
Serializer::Serializer(Serializer &other){
	if (this != &other)
		return;
	return;
}
Serializer &Serializer::operator=(Serializer &other){
		if (this != &other)
			return (*this);
	return (*this);
}
Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));

}
Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
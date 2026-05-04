#include "serializer.hpp"

static uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));

}
static Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
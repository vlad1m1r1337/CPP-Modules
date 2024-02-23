#ifndef CPPMODULESPROJECT_SERIALIZER_HPP
#define CPPMODULESPROJECT_SERIALIZER_HPP

#include "iostream"
#include "Data.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;

class Serializer {
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	static Data* wrongdeserialize(uintptr_t raw);
};

#endif

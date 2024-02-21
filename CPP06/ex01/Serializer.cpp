#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

Data* Serializer::wrongdeserialize(uintptr_t raw) {
	Data *data;

	data = reinterpret_cast<Data*>(raw);
	data->setName("wrong");
	return data;
}

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer& other) {
	*this = other;
}

Serializer& Serializer::operator=(const Serializer& other) {
	if (this == &other) {
		return *this;
	}
	return *this;
}



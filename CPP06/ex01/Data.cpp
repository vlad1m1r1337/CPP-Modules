#include "Data.hpp"

Data::Data() : name("name"), amount(42), sign(true)  {}

Data::Data(string name, int amount, bool sign) : name(name), amount(amount), sign(sign) {}

Data::~Data() {}

void Data::setName(const string &name) {
	Data::name = name;
}

Data::Data(const Data& other) {
	*this = other;
}

Data& Data::operator=(const Data& other) {
	if (this == &other) {
		return *this;
	}
	name = other.name;
	amount = other.amount;
	sign = other.sign;
	return *this;
}

ostream &operator<<(ostream &ostream, const Data &obj) {
	ostream << "Name: " << obj.name << endl;
	ostream << "Amount: " << obj.amount << endl;
	ostream << "Sign: " << obj.sign << endl;
	return ostream;
}
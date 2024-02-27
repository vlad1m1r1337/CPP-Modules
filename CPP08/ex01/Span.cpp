#include "Span.hpp"

Span::Span(unsigned int n) {
	_n = n;

}

Span::~Span() {}

Span::Span(const Span &copy) {
	*this = copy;
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		this->_n = other._n;
		this->_arr = other._arr;
		*this = other;
	}
	return *this;
}

void Span::addNumber(int number) {
	_arr.push_back(number);
}

std::vector<int> Span::getArr() const {
	return _arr;
}

std::ostream& operator<<(std::ostream &ostream, const Span &obj) {
	for (std::vector<int>::const_iterator it = obj.getArr().begin(); it != obj.getArr().end(); ++it) {
		ostream << *it << " ";
	}
	ostream << std::endl;
	return ostream;
}



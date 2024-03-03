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

int Span::longestSpan() {
	std::vector<int>::iterator max;
	std::vector<int>::iterator min;

	max = std::max_element(_arr.begin(), _arr.end());
	min = std::min_element(_arr.begin(), _arr.end());

	return *max - *min;
}

int Span::shortestSpan() {
	if (_arr.size() < 2) {
		return 0;
	}

	std::sort(_arr.begin(), _arr.end());

	int shortest = _arr[1] - _arr[0];
	int local_diff;

	for(unsigned int i = 0; i < _arr.size() - 1; i++) {
		if ((local_diff = _arr[i + 1] - _arr[i]) < shortest) {
			shortest = local_diff;
		}
	}
	return shortest;
}

std::vector<int> Span::getArr() const {
	return _arr;
}

std::ostream& operator<<(std::ostream &ostream, const Span &obj) {
	unsigned int size = obj.getArr().size();
	for (unsigned int i = 0; i < size; i++) {
		ostream << obj.getArr()[i] << " ";
	}
	ostream << std::endl;
	return ostream;
}



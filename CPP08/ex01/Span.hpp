#ifndef CPPMODULESPROJECT_SPAN_HPP
#define CPPMODULESPROJECT_SPAN_HPP

#include <vector>
#include <iostream>

using std::cout;
using std::endl;

class Span {
private:
	unsigned int _n;
	std::vector<int> _arr;
public:
	Span(unsigned int n);
	Span(const Span &span);
	Span &operator=(const Span &span);
	~Span();

	void addNumber(int number);
	int shortestSpan();
	int longestSpan();

	std::vector<int> getArr() const;
};

std::ostream& operator<<(std::ostream &ostream, const Span &obj);


#endif

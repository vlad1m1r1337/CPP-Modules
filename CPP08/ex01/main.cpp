#include "Span.hpp"

int main() {
	Span sp(5);
	sp.addNumber(4);
	sp.addNumber(45);
	sp.addNumber(69);
	std::cout << sp;
	return 0;
}
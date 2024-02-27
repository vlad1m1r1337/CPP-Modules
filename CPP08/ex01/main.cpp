#include "Span.hpp"

int main() {
	{
		int s = 20;
		Span sp(s);
		for (int i = 0; i < s - 1; i++) {
			sp.addNumber(i);
		}
		std::cout << "span: " << sp;
		cout << "longestSpan: " << sp.longestSpan() << endl;
		cout << "shortestSpan: " << sp.shortestSpan() << endl;
		cout << endl;
	}
	{
		int s = 20000;
		Span sp(s);
		for (int i = 0; i < s - 1; i++) {
			sp.addNumber(i);
		}
		cout << "longestSpan: " << sp.longestSpan() << endl;
		cout << "shortestSpan: " << sp.shortestSpan() << endl;
		cout << endl;
	}
	{
		int s = 7;
		Span sp(s);
		sp.addNumber(4);
		sp.addNumber(7);
		sp.addNumber(67);
		sp.addNumber(346);
		sp.addNumber(40);
		sp.addNumber(34);
		sp.addNumber(14);
		std::cout << "span: " << sp;
		cout << "longestSpan: " << sp.longestSpan() << endl;
		cout << "shortestSpan: " << sp.shortestSpan() << endl;
		cout << endl;
	}
	return 0;
}

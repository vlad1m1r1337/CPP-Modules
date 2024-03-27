#ifndef CPPMODULESPROJECT_RPN_HPP
#define CPPMODULESPROJECT_RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <exception>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::stack;
using std::string;

enum SIGNS {
	PLUS = 1,
	MINUS,
	MULT,
	DIVIDE,
};

class RPN {
private:
	stack<string> _stack;
public:
	RPN();
	~RPN();
	RPN(const RPN& rpn);
	RPN& operator=(const RPN& rpn);

//	void parse_symbol(string str);
	void calculate(char *str);
	void printResult() const;
	void printStack() const;
};
std::string trim(const std::string& str);

#endif

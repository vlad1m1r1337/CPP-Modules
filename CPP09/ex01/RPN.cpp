#include "RPN.hpp"

RPN::RPN() {
}

RPN::~RPN() {
}

RPN::RPN(const RPN& rpn) {
	_stack = rpn._stack;
}

RPN& RPN::operator=(const RPN& rpn) {
	if (this != &rpn) {
		_stack = rpn._stack;
	}
	return *this;
}

void RPN::printStack() const {
	stack<string> temp = _stack;
	while (!temp.empty()) {
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << endl;
}

void parse_symbol(string str) {
	if ((!isdigit(str[0]) && str != "+" && str != "-" && str != "*" && str != "/") || str.size() != 1) {
		throw std::exception();
	}
}

int define_sign(string str) {
	if (str == "+") {return PLUS;}
	else if (str == "-") {return MINUS;}
	else if (str == "*") {return MULT;}
	else if (str == "/") {return DIVIDE;}
	else {
		return 0;
	}
}

void RPN::printResult() const {
	cout << atof(_stack.top().c_str()) << endl;
}

void RPN::calculate(char* str) {
	string parsed;
	std::stringstream input_stringstream(str);
	while (getline(input_stringstream,parsed,' ')) {
		parse_symbol(parsed);
		int symbol;
		if (symbol = define_sign(parsed)) {
			if (_stack.empty()) {throw std::exception();}
			double num1 = atof(_stack.top().c_str());
			_stack.pop();
			double num2 = atof(_stack.top().c_str());
			_stack.pop();
			switch (symbol) {
				double res;
				case PLUS:
					res = num2 + num1;
					_stack.push(std::to_string(res));
					break;
				case MINUS:
					res = num2 - num1;
					_stack.push(std::to_string(res));
					break;
				case MULT:
					res = num2 * num1;
					_stack.push(std::to_string(res));
					break;
				case DIVIDE:
					if (!num1) {throw std::exception();}
					res = num2 / num1;
					_stack.push(std::to_string(res));
					break;
			}
		}
		else {
			_stack.push(parsed);
		}
	}
}

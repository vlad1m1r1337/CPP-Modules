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
		if (parsed.length() == 0) { continue;}
		parse_symbol(parsed);
		int symbol;
		if ((symbol = define_sign(parsed))) {
			if (_stack.empty()) {throw std::exception();}

            if (_stack.empty()) {
                throw std::exception();
            }

			double num1 = atof(_stack.top().c_str());
			_stack.pop();

            if (_stack.empty()) {
                throw std::exception();
            }
			double num2 = atof(_stack.top().c_str());
			_stack.pop();

            double res;
            std::ostringstream oss;
            std::string res_str;

			switch (symbol) {
				case PLUS:
					res = num2 + num1;
                    oss << res;
                    res_str = oss.str();
					_stack.push(res_str);
					break;
				case MINUS:
					res = num2 - num1;
                    oss << res;
                    res_str = oss.str();
                    _stack.push(res_str);
					break;
				case MULT:
					res = num2 * num1;
                    oss << res;
                    res_str = oss.str();
                    _stack.push(res_str);
					break;
				case DIVIDE:
					if (!num1) {throw std::exception();}
					res = num2 / num1;
                    oss << res;
                    res_str = oss.str();
                    _stack.push(res_str);
					break;
			}
		}
		else {
			_stack.push(parsed);
		}
	}
    if (_stack.size() != 1) {
        throw std::exception();
    }
}

//trim functions
bool IsNotSpace(char ch) {
	return !std::isspace(ch);
}

std::string ltrim(const std::string& str) {
	std::string result = str;
	result.erase(result.begin(), std::find_if(result.begin(), result.end(), IsNotSpace));
	return result;
}


std::string rtrim(const std::string& str) {
	std::string result = str;
	result.erase(std::find_if(result.rbegin(), result.rend(), IsNotSpace).base(), result.end());
	return result;
}

std::string trim(const std::string& str) {
	return rtrim(ltrim(str));
}

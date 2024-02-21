#ifndef CPPMODULESPROJECT_DATA_HPP
#define CPPMODULESPROJECT_DATA_HPP

#include "iostream"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::endl;

class Data {
public:
	string name;
	int amount;
	bool sign;
	Data();
	Data(string name, int amount, bool sign);
	~Data();
	void setName(const string &name);
	Data(const Data& other);
	Data& operator=(const Data& other);
};

ostream &operator<<(ostream &ostream, const Data &obj);

#endif

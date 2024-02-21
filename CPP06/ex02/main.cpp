#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Base {
public:
	virtual ~Base() {};
};

class A : public Base {

};

class B : public Base {

};

class C : public Base {

};

Base* generate(void) {
	int i = rand() % 3;
	if (i == 0) {
		return new A;
	} else if (i == 1) {
		return new B;
	} else {
		return new C;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	}
}

//void identify(Base& p) {
//	if (dynamic_cast<A*>(&p)) {
//		std::cout << "A" << std::endl;
//	} else if (dynamic_cast<B*>(&p)) {
//		std::cout << "B" << std::endl;
//	} else if (dynamic_cast<C*>(&p)) {
//		std::cout << "C" << std::endl;
//	}
//}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (std::bad_cast& e) {
		try {
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		} catch (std::bad_cast& e) {
			try {
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			} catch (std::bad_cast& e) {
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	Base* p = generate();
	identify(p);
	identify(*p);
	cout << endl;

	delete p;
	return 0;
}


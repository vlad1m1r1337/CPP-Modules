#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat bureaucrat("VOVA", 13);

		Form form("form", 100, 100);
		cout << form << endl;
		bureaucrat.signForm(form);
		cout << form << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
}

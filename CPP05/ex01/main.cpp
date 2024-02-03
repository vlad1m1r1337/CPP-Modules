#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat bureaucrat("VOVA", 130);

		Form form("form");
		cout << form << endl;
		bureaucrat.signForm(form);
		cout << form << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
}

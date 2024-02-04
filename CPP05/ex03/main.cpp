#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
	try {
		Bureaucrat vovan("Vladimir", 10);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidental pardon", "davavavai");
		vovan.signForm(*rrf);
		vovan.executeForm(*rrf);

	}
	catch(const exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
	try {
		Bureaucrat vovan("Vladimir", 100);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shrubbery request", "davavavai");
		vovan.signForm(*rrf);
		vovan.executeForm(*rrf);
	}
	catch(const exception& e) {
		cout << e.what() << endl;
	}
}

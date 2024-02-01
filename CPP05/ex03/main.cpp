#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	try {
		Bureaucrat vovan("Vladimir", 100);
        ShrubberyCreationForm pres("shrubbery");
		vovan.signForm(pres);
        vovan.executeForm(pres);
    }
	catch (const exception& e) {
		cout << e.what() << endl;
	}
}

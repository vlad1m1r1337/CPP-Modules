#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	try {
		Bureaucrat vovan("Vladimir", 45);
        RobotomyRequestForm pres("pardon");
		vovan.signForm(pres);
        vovan.executeForm(pres);
    }
	catch (const exception& e) {
		cout << e.what() << endl;
	}
}

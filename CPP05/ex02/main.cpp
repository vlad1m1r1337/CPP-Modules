#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	try {
		Bureaucrat vovan("Vladimir", 145);
        ShrubberyCreationForm pres("shrubbery");
		pres.beSigned(vovan);
        vovan.executeForm(pres);
    }
	catch (const NotSignedForm& error1) {
		cout << error1.what() << endl;
	}
	catch (const TooLowGrade& error2) {
		cout << error2.what() << endl;
	}
    catch (const FailedSignForm& error1) {
        cout << error1.what() << endl;
    }
    catch (const TooHighGrade& error3) {
        cout << error3.what() << endl;
    }
}

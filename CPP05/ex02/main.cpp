#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	try {
		Bureaucrat vovan("Vladimir", 100);
		RobotomyRequestForm pres("robotomy");
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

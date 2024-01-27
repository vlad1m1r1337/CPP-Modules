#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	try {
		Bureaucrat vovan("Vladimir", 1);
		PresidentialPardonForm pres("Vladimir");
		pres.beSigned(vovan);
	}
	catch (const NotSignedForm& error1) {
		cout << error1.what() << endl;
	}
	catch (const TooLowGrade& error2) {
		cout << error2.what() << endl;
	}
//    catch (const FailedSignForm& error1) {
//        cout << error1.what() << endl;
//    }
//    catch (const TooLowGrade& error2) {
//        cout << error2.what() << endl;
//    }
//    catch (const TooHighGrade& error3) {
//        cout << error3.what() << endl;
//    }
}

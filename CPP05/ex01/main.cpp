#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    const Bureaucrat bur("Tom", 12);
    Form form("form");
    try {
    	bur.signForm(form);
        form.beSigned(bur);
        cout << form << endl;
    }
    catch (const FailedSignForm& error1) {
        cout << error1.what() << endl;
    }
    catch (const TooLowGrade& error2) {
        cout << error2.what() << endl;
    }
    catch (const TooHighGrade& error3) {
        cout << error3.what() << endl;
    }
}

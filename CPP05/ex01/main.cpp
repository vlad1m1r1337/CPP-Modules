#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat bur("Tom", 100);
    Form form("form");
    try {
    	bur.signForm(form);
        cout << form << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
}

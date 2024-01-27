#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bur_error("Tom", 150);
        cout << bur_error;
        bur_error.setGrade(151);
        Bureaucrat bur_norm("Ed", 70);
        cout << bur_norm;
    }
    catch (const TooHighGrade& error) {
        cout << error.what() << endl;
    }
    catch (const TooLowGrade& err) {
        cout << err.what() << endl;
    }
    return 0;
}

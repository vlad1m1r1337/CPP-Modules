#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bur_error("Tom", 150);
        cout << bur_error;
        Bureaucrat bur_norm("Ed", 70);
        cout << bur_norm;
        Bureaucrat lol;
        lol = bur_norm;
        cout << "lol " << lol;
        Bureaucrat qwe(bur_error);
        cout << qwe;
    }
    catch (const TooHighGrade& error) {
        cout << error.what() << endl;
    }
    catch (const TooLowGrade& err) {
        cout << err.what() << endl;
    }
    return 0;
}

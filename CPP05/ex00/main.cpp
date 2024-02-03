#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bur_error("Tom", 150);
        cout << bur_error;
        Bureaucrat bur_norm("Ed", 5);
        cout << bur_norm;
        bur_norm.decrement();
        cout << bur_norm;
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}

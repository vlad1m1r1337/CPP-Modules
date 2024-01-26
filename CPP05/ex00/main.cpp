#include "Bureaucrat.hpp"

int main() {
    Bureaucrat bur_error("Tom", 150);
    cout << bur_error;
    bur_error.setGrade(151);
    Bureaucrat bur_norm("Ed", 70);
    cout << bur_norm;
    return 0;
}

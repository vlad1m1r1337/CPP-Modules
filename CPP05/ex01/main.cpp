#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat bur("Tom", 30);
    Form form("form");
    form.beSigned(bur);
}

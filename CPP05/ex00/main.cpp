
//class person_error : public std::exception
//{
//public:
//    person_error(const std::string& message) throw() : message(message) {}
//    ~person_error() throw() {}
//
//    const char* what() const throw()
//    {
//        return message.c_str();
//    }
//
//private:
//    std::string message;
//};

#include "Bureaucrat.hpp"

int main() {
    Bureaucrat bur_error("Tom", 155);
    cout << bur_error;
    Bureaucrat bur_norm("Ed", -70);
    cout << bur_norm;
    return 0;
}

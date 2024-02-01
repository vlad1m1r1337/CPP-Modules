#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("name", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const string &target) : AForm(target, 145, 137) {}\

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (&other != this) {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy) {
    *this = copy;
}

void createThree(string name) {
    ofstream  out(name.c_str());
    if (!out.is_open()) {
        std::cerr << "Unable to open file for writing: " << name << std::endl;
        return;
    }
    std::string treeArt =
            "        *\n"
            "       /|\\\n"
            "      /*|*\\\n"
            "     /*/|\\*\\\n"
            "    /*/ | \\*\\\n"
            "   /*/ /|\\ \\*\\\n"
            "    |  |||\n"
            "    |  |||\n"
            "____|__|||____\n"
            "   /    \\\n"
            "  /      \\\n"
            " /        \\\n"
            "============";
    out << treeArt;

    out.close();
}

void ShrubberyCreationForm::execute(const Bureaucrat &bur) {
    if (bur.getGrade() > AForm::getFormExecGrade()) {
        throw Bureaucrat::TooLowGrade();
    }
    if (!AForm::getFormSigned()) {
        cout << "form is not signed" << endl;
		return ;
    }
    createThree(AForm::getFormName());
}

ShrubberyCreationForm* ShrubberyCreationForm::clone() const {
    ShrubberyCreationForm* form = new ShrubberyCreationForm();
    return form;
}
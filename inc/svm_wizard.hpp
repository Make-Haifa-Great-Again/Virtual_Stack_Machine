#ifndef SVM_WIZARD_HPP
#define SVM_WIZARD_HPP

#include <iostream>

namespace svm {

class Wizard {
public:
    explicit Wizard(const char* a_fileName);
    explicit Wizard(std::istream& a_input);
    Wizard(const Wizard& a_other) = delete;
    Wizard& operator=(const Wizard& a_other) = delete;
    ~Wizard();

    std::ostream& Assemble(std::ostream& a_output);

private:
    std::istream& m_input;
    bool m_destroy;
};

} // svm

#include "svm_wizard.hxx"

#endif /* SVM_WIZARD_HPP */
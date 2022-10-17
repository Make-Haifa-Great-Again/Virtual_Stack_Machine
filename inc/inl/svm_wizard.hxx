#ifndef SVM_WIZARD_HXX
#define SVM_WIZARD_HXX

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "svm_stack_vm.hpp"
#include "svm_code_segment.hpp"
#include "fsl_parser.hpp"
#include "svm_compiler.hpp"

namespace svm {

inline Wizard::Wizard(const char* a_fileName)
: m_input(*new std::ifstream{a_fileName})
, m_destroy(true)
{}

inline Wizard::Wizard(std::istream& a_input)
: m_input(a_input)
, m_destroy(false)
{}

inline Wizard::~Wizard()
{
    if (m_destroy) {
        delete &m_input;
    }
}

inline std::ostream& Wizard::Assemble(std::ostream& a_output)
{
    fsl::CleanCode toAssemble = fsl::Parser{}.Parse(m_input);
    CodeSegment<StackVM::word> assembled;
    try {
        assembled = Compiler<StackVM::word>{}.Compile(toAssemble);
    } catch (const svm_compilation_error& e) {
        return a_output << "Compilation Error: " << e.what() << "\n\n";
    }
    return StackVM{a_output}.TurnOnVirtualMachine(assembled);
}

} // svm

#endif /* SVM_WIZARD_HXX */
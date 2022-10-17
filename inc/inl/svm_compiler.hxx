#ifndef SVM_COMPILER_HXX
#define SVM_COMPILER_HXX

#include "svm_compiler.hpp"

#include <string>
#include "fsl_parser.hpp"
#include "svm_code_segment.hpp"
#include "svm_stack_vm.hpp"
#include "fsl_string_manipulations.hpp"
#include "svm_spam.hpp"

namespace svm {

inline svm_compilation_error::svm_compilation_error(const std::string& a_error)
: m_what(a_error)
{}

inline const char* svm_compilation_error::what() const throw()
{
    return m_what.c_str();
}

template<typename T>
CodeSegment<T> Compiler<T>::Compile(fsl::CleanCode a_cleanCode) const
{
    CodeSegment<T> output{};
    CallMap callNames;

    struct FirstPassasge {
    public:
        FirstPassasge(CallMap& a_callNames) 
                : m_callNames(a_callNames), m_index(0) {}

        void operator()(std::string& a_codeUnit) {
            ++m_index;
            if (fsl::IsNumeric(*a_codeUnit.cbegin())) {
                if (fsl::IsNumeric(a_codeUnit)) {
                    return;
                }
                throw svm_compilation_error(std::string{"Invalid Syntax - a function call can't begin with a number - "} += a_codeUnit);
            }
            if (a_codeUnit.length() > (sizeof(T) / sizeof(char))) {
                throw svm_compilation_error(std::string{"Invalid Syntax - name is too long - "} += a_codeUnit);
            }
            if (*(--a_codeUnit.cend()) == ':') {
                if (BON(OpCodeT, isStringValid)(a_codeUnit.c_str())) {
                    throw svm_compilation_error(std::string{"Invalid Syntax - call function defined with a reserved keyword - "} += a_codeUnit);
                }
                a_codeUnit.pop_back();
                try {
                    m_callNames.at(a_codeUnit);
                    throw svm_compilation_error(std::string{"Function Redecleared - "} += a_codeUnit);
                } catch (const std::out_of_range& e) {
                    m_callNames.insert(std::pair(a_codeUnit, m_index));
                }
                a_codeUnit = "NOP";
            }
        }

    private:
        CallMap& m_callNames;
        size_t m_index;
    };

    struct SecondPassage {
    public:
        SecondPassage(CodeSegment<T>& a_compiled, CallMap& a_callNames) 
                : m_compiled(a_compiled), m_callNames(a_callNames) {}

        void operator()(const std::string& a_codeUnit) {
            if (fsl::IsNumeric(*a_codeUnit.cbegin())) {
                m_compiled.Add(fsl::NumFromString<T>(a_codeUnit));
                return;
            }
            if (!BON(OpCodeT, isStringValid)(a_codeUnit.c_str())) {
                try {
                    m_compiled.Add(static_cast<T>(m_callNames.at(a_codeUnit)));
                    return;
                } catch (const std::out_of_range& e) {}
                throw svm_compilation_error(std::string{"Invalid Syntax - "} += a_codeUnit);
            }
            m_compiled.Add(BON(OpCodeT, fromString)(a_codeUnit.c_str()));
        }

    private:
        CodeSegment<T>& m_compiled;
        CallMap& m_callNames;
    };

    std::for_each(a_cleanCode.begin(), a_cleanCode.end(), FirstPassasge{callNames});
    std::for_each(a_cleanCode.cbegin(), a_cleanCode.cend(), SecondPassage{output, callNames});
    return output;
}

} // svm

#endif /* SVM_COMPILER_HXX */
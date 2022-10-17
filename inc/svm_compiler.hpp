#ifndef SVM_COMPILER_HPP
#define SVM_COMPILER_HPP

#include <exception>
#include <unordered_map>
#include "fsl_parser.hpp"
#include "svm_code_segment.hpp"

namespace svm {

class svm_compilation_error: public std::exception {
public:
    svm_compilation_error(const std::string& a_error);
    virtual const char* what() const throw();

private:
    std::string m_what;
};

template<typename T>
class Compiler {
public:
    Compiler() = default;
    Compiler(const Compiler& a_other) = default;
    Compiler& operator=(const Compiler& a_other) = default;
    ~Compiler() = default;

    CodeSegment<T> Compile(fsl::CleanCode a_cleanCode) const;
private:
    typedef std::unordered_map<std::string, size_t> CallMap;
};

} // svm

#include "svm_compiler.hxx"

#endif /* SVM_COMPILER_HPP */
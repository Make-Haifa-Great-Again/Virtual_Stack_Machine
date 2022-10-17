#ifndef SVM_PROCCESSOR_HPP
#define SVM_PROCCESSOR_HPP

#include <ostream>
#include <unordered_map>
#include "fsl_memory.hpp"
#include "fsl_safe_stack.hpp"
#include "svm_code_op.hpp"
#include "svm_code_segment.hpp"

namespace svm {

template<typename T, typename IP>
class Proccessor {
public:
    Proccessor(std::ostream& a_output, fsl::Memory<T>& a_ram, fsl::SafeStack<T>& a_stack, fsl::SafeStack<IP>& a_IPstack);
    Proccessor(const Proccessor& a_other) = default;
    Proccessor& operator=(const Proccessor& a_other) = default;
    ~Proccessor() = default;

    std::ostream& Proccess(CodeSegment<T>& a_codeSegment);

private:
    void loadOperations(CodeSegment<T>& a_codeSegment);
    void destroyOperations();

    std::unordered_map<T, CodeOperation*> m_operations;
    std::ostream& m_output;
    fsl::Memory<T>& m_ram;
    fsl::SafeStack<T>& m_stack;
    fsl::SafeStack<IP>& m_IPstack;
};

} // svm

#include "svm_proccessor.hxx"

#endif /* SVM_PROCCESSOR_HPP */
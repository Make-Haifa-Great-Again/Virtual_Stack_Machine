#ifndef SVM_STACK_VM_HPP
#define SVM_STACK_VM_HPP

#include <cstdint> /* int64_t */
#include <ostream>
#include "fsl_memory.hpp"
#include "fsl_safe_stack.hpp"
#include "svm_code_segment.hpp"

namespace svm {

class StackVM {
public:
    typedef int64_t word;
    typedef int64_t& wordRef;
    typedef unsigned long long IP;

    StackVM(std::ostream& a_output, size_t a_ramSize = 1024, size_t a_stackSize = 1024, size_t a_IPstackSize = 1024);
    StackVM(const StackVM& a_other) = default;
    StackVM& operator=(const StackVM& a_other) = default;
    ~StackVM() = default;

    std::ostream& TurnOnVirtualMachine(CodeSegment<word>& a_codeSegment);

private:

    fsl::Memory<word> m_ram;
    fsl::SafeStack<word> m_stack;
    fsl::SafeStack<IP> m_IPstack;
    std::ostream& m_output;
};

} // svm

#include "svm_stack_vm.hxx"

#endif /* SVM_STACK_VM_HPP */
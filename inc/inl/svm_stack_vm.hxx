#ifndef SVM_STACK_VM_HXX
#define SVM_STACK_VM_HXX

#include <algorithm>
#include "svm_code_op.hpp"

namespace svm {

inline StackVM::StackVM(std::ostream& a_output, size_t a_ramSize, size_t a_stackSize, size_t a_IPstackSize)
: m_ram(a_ramSize)
, m_stack(a_stackSize)
, m_IPstack(a_IPstackSize)
, m_output(a_output)
{}

} // svm

#endif /* SVM_STACK_VM_HXX */
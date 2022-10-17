#ifndef SVM_SAFE_STACK_HXX
#define SVM_SAFE_STACK_HXX

#include <stack>
#include <stdexcept>
#include "svm_stack_vm.hpp"

namespace fsl {

inline safe_stack_error::safe_stack_error(const std::string& a_error)
: m_what(a_error)
{}

inline const char* safe_stack_error::what() const throw()
{
    return m_what.c_str();
}

template<typename T>
SafeStack<T>::SafeStack(size_t a_limit)
: m_stack()
, m_limit(a_limit)
{}

template<typename T>
typename SafeStack<T>::item SafeStack<T>::top()
{
    if (m_stack.empty()) {
        throw safe_stack_error("Can't return the top of an empty stack.");
    }
    return m_stack.top();
}

template<typename T>
void SafeStack<T>::push(item a_item)
{
    if (m_limit && m_limit == m_stack.size()) {
        throw safe_stack_error("Safe Stack Overflow.");
    }
    m_stack.push(a_item);
}

template<typename T>
typename SafeStack<T>::item SafeStack<T>::pop()
{
    if (m_stack.empty()) {
        throw safe_stack_error("Can't pop an empty stack.");
    }
    T popped = m_stack.top();
    m_stack.pop();
    return popped;
}

} // fsl

#endif /* SVM_SAFE_STACK_HXX */
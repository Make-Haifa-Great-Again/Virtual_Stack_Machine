#ifndef FSL_SAFE_STACK_HPP
#define FSL_SAFE_STACK_HPP

#include <stack>
#include <string>
#include <exception>

namespace fsl {

class safe_stack_error: public std::exception {
public:
    safe_stack_error(const std::string& a_error);
    virtual const char* what() const throw();

private:
    std::string m_what;
};

template<typename T>
class SafeStack {
public:
    typedef T item;

    SafeStack(size_t a_limit = 0);
    SafeStack(const SafeStack& a_other) = default;
    SafeStack& operator=(const SafeStack& a_other) = default;
    ~SafeStack() = default;

    item top();

    void push(item a_item);
    item pop();

private:
    std::stack<item> m_stack;
    size_t m_limit;
};

} // fsl

#include "fsl_safe_stack.hxx"

#endif /* FSL_SAFE_STACK_HPP */
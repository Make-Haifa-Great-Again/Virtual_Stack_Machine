#ifndef SVM_OPERATIONS_HXX
#define SVM_OPERATIONS_HXX

#include <iostream>
#include <sstream>

namespace svm {

inline bool OpNOP::Operate()
{
    return true;
}

template<typename T>
OpADD<T>::OpADD(fsl::SafeStack<T>& a_safeStack)
: m_safeStack(a_safeStack)
{}

template<typename T>
bool OpADD<T>::Operate()
{
    m_safeStack.push(m_safeStack.pop() + m_safeStack.pop());
    return true;
}

template<typename T>
OpSUB<T>::OpSUB(fsl::SafeStack<T>& a_safeStack)
: m_safeStack(a_safeStack)
{}

template<typename T>
bool OpSUB<T>::Operate()
{
    m_safeStack.push(m_safeStack.pop() - m_safeStack.pop());
    return true;
}

template<typename T>
OpAND<T>::OpAND(fsl::SafeStack<T>& a_safeStack)
: m_safeStack(a_safeStack)
{}

template<typename T>
bool OpAND<T>::Operate()
{
    m_safeStack.push(m_safeStack.pop() & m_safeStack.pop());
    return true;
}

template<typename T>
OpOR<T>::OpOR(fsl::SafeStack<T>& a_safeStack)
: m_safeStack(a_safeStack)
{}

template<typename T>
bool OpOR<T>::Operate()
{
    m_safeStack.push(m_safeStack.pop() | m_safeStack.pop());
    return true;
}

template<typename T>
OpXOR<T>::OpXOR(fsl::SafeStack<T>& a_safeStack)
: m_safeStack(a_safeStack)
{}

template<typename T>
bool OpXOR<T>::Operate()
{
    m_safeStack.push(m_safeStack.pop() ^ m_safeStack.pop());
    return true;
}

template<typename T>
OpNOT<T>::OpNOT(fsl::SafeStack<T>& a_safeStack)
: m_safeStack(a_safeStack)
{}

template<typename T>
bool OpNOT<T>::Operate()
{
    m_safeStack.push(static_cast<T>(!m_safeStack.pop()));
    return true;
}

template<typename T>
OpIN<T>::OpIN(fsl::SafeStack<T>& a_safeStack)
: m_safeStack(a_safeStack)
{}

template<typename T>
bool OpIN<T>::Operate()
{
    m_safeStack.push(static_cast<T>(getchar()));
    return true;
}

template<typename T>
OpOUT<T>::OpOUT(fsl::SafeStack<T>& a_safeStack, std::ostream& a_stream)
: m_safeStack(a_safeStack)
, m_stream(a_stream)
{}

template<typename T>
bool OpOUT<T>::Operate()
{
    m_stream << static_cast<char>(m_safeStack.pop());
    return true;
}

template<typename T>
OpLOAD<T>::OpLOAD(fsl::SafeStack<T>& a_safeStack, fsl::Memory<T>& a_memory)
: m_safeStack(a_safeStack)
, m_memory(a_memory)
{}

template<typename T>
bool OpLOAD<T>::Operate()
{
    m_safeStack.push(m_memory.at(m_safeStack.pop()));
    return true;
}

template<typename T>
OpSTOR<T>::OpSTOR(fsl::SafeStack<T>& a_safeStack, fsl::Memory<T>& a_memory)
: m_safeStack(a_safeStack)
, m_memory(a_memory)
{}

template<typename T>
bool OpSTOR<T>::Operate()
{
    m_memory.at(m_safeStack.pop()) = m_safeStack.pop();
    return true;
}

template<typename T>
OpJMP<T>::OpJMP(CodeSegment<T>& a_codeSegment, fsl::SafeStack<T>& a_safeStack)
: m_codeSegment(a_codeSegment)
, m_safeStack(a_safeStack)
{}

template<typename T>
bool OpJMP<T>::Operate()
{
    m_codeSegment.GoTo(m_safeStack.pop() - 1);
    return true;
}

template<typename T>
OpJZ<T>::OpJZ(CodeSegment<T>& a_codeSegment, fsl::SafeStack<T>& a_safeStack)
: m_codeSegment(a_codeSegment)
, m_safeStack(a_safeStack)
{}

template<typename T>
bool OpJZ<T>::Operate()
{
    T a = m_safeStack.pop();
    T b = m_safeStack.pop();
    if (a == 0) {
        m_codeSegment.GoTo(b - 1);
    }
    return true;
}

template<typename T>
OpPUSH<T>::OpPUSH(CodeSegment<T>& a_codeSegment, fsl::SafeStack<T>& a_safeStack)
: m_codeSegment(a_codeSegment)
, m_safeStack(a_safeStack)
{}

template<typename T>
bool OpPUSH<T>::Operate()
{
    m_safeStack.push((++m_codeSegment).Get());
    return true;
}

template<typename T>
OpDUP<T>::OpDUP(fsl::SafeStack<T>& a_safeStack)
: m_safeStack(a_safeStack)
{}

template<typename T>
bool OpDUP<T>::Operate()
{
    m_safeStack.push(m_safeStack.top());
    return true;
}

template<typename T>
OpSWAP<T>::OpSWAP(fsl::SafeStack<T>& a_safeStack)
: m_safeStack(a_safeStack)
{}

template<typename T>
bool OpSWAP<T>::Operate()
{
    T a = m_safeStack.pop();
    T b = m_safeStack.pop();
    m_safeStack.push(b);
    m_safeStack.push(a);
    return true;
}

template<typename T>
OpROL3<T>::OpROL3(fsl::SafeStack<T>& a_safeStack)
: m_safeStack(a_safeStack)
{}

template<typename T>
bool OpROL3<T>::Operate()
{
    T a = m_safeStack.pop();
    T b = m_safeStack.pop();
    T c = m_safeStack.pop();
    m_safeStack.push(b);
    m_safeStack.push(c);
    m_safeStack.push(a);
    return true;
}

template<typename T>
OpOUTNUM<T>::OpOUTNUM(fsl::SafeStack<T>& a_safeStack, std::ostream& a_stream)
: m_safeStack(a_safeStack)
, m_stream(a_stream)
{}

template<typename T>
bool OpOUTNUM<T>::Operate()
{
    m_stream << m_safeStack.pop();
    return true;
}

template<typename T>
OpINNUM<T>::OpINNUM(fsl::SafeStack<T>& a_safeStack)
: m_safeStack(a_safeStack)
{}

template<typename T>
bool OpINNUM<T>::Operate()
{
    T num_input;
    std::cin >> num_input;
    m_safeStack.push(num_input);
    return true;
}

template<typename T>
OpJNZ<T>::OpJNZ(CodeSegment<T>& a_codeSegment, fsl::SafeStack<T>& a_safeStack)
: m_codeSegment(a_codeSegment)
, m_safeStack(a_safeStack)
{}

template<typename T>
bool OpJNZ<T>::Operate()
{
    T a = m_safeStack.pop();
    T b = m_safeStack.pop();
    if (a != 0) {
        m_codeSegment.GoTo(b - 1);
    }
    return true;
}

template<typename T>
OpDROP<T>::OpDROP(fsl::SafeStack<T>& a_safeStack)
: m_safeStack(a_safeStack)
{}

template<typename T>
bool OpDROP<T>::Operate()
{
    m_safeStack.pop();
    return true;
}

template<typename T>
OpCOMPL<T>::OpCOMPL(fsl::SafeStack<T>& a_safeStack)
: m_safeStack(a_safeStack)
{}

template<typename T>
bool OpCOMPL<T>::Operate()
{
    m_safeStack.push(~(m_safeStack.pop()));
    return true;
}

inline bool OpHLT::Operate()
{
    return false;
}


    /* Phase Two */


template<typename T, typename IP>
OpPUSHIP<T, IP>::OpPUSHIP(CodeSegment<T>& a_codeSegment, fsl::SafeStack<IP>& a_IPstack)
: m_codeSegment(a_codeSegment) 
, m_IPstack(a_IPstack)
{}

template<typename T, typename IP>
bool OpPUSHIP<T, IP>::Operate()
{
    m_IPstack.push((++m_codeSegment).Get());
    return true;
}

template<typename T, typename IP>
OpPOPIP<T, IP>::OpPOPIP(CodeSegment<T>& a_codeSegment, fsl::SafeStack<IP>& a_IPstack)
: m_codeSegment(a_codeSegment) 
, m_IPstack(a_IPstack)
{}

template<typename T, typename IP>
bool OpPOPIP<T, IP>::Operate()
{
    m_codeSegment.GoTo(m_IPstack.pop() - 1);
    return true;
}

template<typename IP>
OpDROPIP<IP>::OpDROPIP(fsl::SafeStack<IP>& a_IPstack)
: m_IPstack(a_IPstack)
{}

template<typename IP>
bool OpDROPIP<IP>::Operate()
{
    m_IPstack.pop();
    return true;
}

} // svm

#endif /* SVM_OPERATIONS_HXX */
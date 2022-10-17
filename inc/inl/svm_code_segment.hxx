#ifndef SVM_CODE_SEGMENT_HXX
#define SVM_CODE_SEGMENT_HXX

#include <vector>
#include <iterator>
#include <stdexcept>

namespace svm {

inline code_segment_error::code_segment_error(const std::string& a_error)
: m_what(a_error)
{}

inline const char* code_segment_error::what() const throw()
{
    return m_what.c_str();
}

template<typename T>
inline CodeSegment<T>::CodeSegment()
: m_code(1, static_cast<T>(0))
, m_segment(m_code.begin())
{
}

template<typename T>
CodeSegment<T>::CodeSegment(const CodeSegment& a_other)
: m_code(a_other.m_code)
, m_segment(m_code.begin())
{
}

template<typename T>
CodeSegment<T>& CodeSegment<T>::operator=(const CodeSegment& a_other)
{
    m_code = a_other.m_code;
    m_segment = m_code.begin();
    return *this;
}

template<typename T>
inline typename CodeSegment<T>::segmentT CodeSegment<T>::Get() const noexcept
{
    T got = *m_segment;
    return got;
}

template<typename T>
inline void CodeSegment<T>::Add(segmentT a_instruction)
{
    m_code.push_back(a_instruction);
}

template<typename T>
inline CodeSegment<T>& CodeSegment<T>::operator++()
{
    if (std::distance(m_segment, m_code.end()) == 0) {
        throw code_segment_error("Program Ended Without HLT");
    }
    ++m_segment;
    return *this;
}

template<typename T>
inline CodeSegment<T>& CodeSegment<T>::GoTo(size_t a_index)
{
    if (a_index >= m_code.size()) {
        throw code_segment_error("Segmentation Fault: attempt to access out-of-bound IP detected.");
    }
    m_segment = m_code.begin() + a_index;
    return *this;
}   
 
} // svm

#endif /* SVM_CODE_SEGMENT_HXX */
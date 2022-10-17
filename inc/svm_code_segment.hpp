#ifndef SVM_CODE_SEGMENT_HPP
#define SVM_CODE_SEGMENT_HPP

#include <vector>
#include <exception>

namespace svm {

class code_segment_error: public std::exception {
public:
    code_segment_error(const std::string& a_error);
    virtual const char* what() const throw();

private:
    std::string m_what;
};

template<typename T>
class CodeSegment {
public:
    typedef T segmentT;

    CodeSegment();
    CodeSegment(const CodeSegment& a_other);
    CodeSegment& operator=(const CodeSegment& a_other);
    ~CodeSegment() = default;

    segmentT Get() const noexcept;

    void Add(segmentT a_instruction);

    CodeSegment& operator++();
    CodeSegment& GoTo(size_t a_index);    

private:
    typename std::vector<segmentT> m_code;
    typename std::vector<segmentT>::iterator m_segment;
};

} // svm

#include "svm_code_segment.hxx"

#endif /* SVM_CODE_SEGMENT_HPP */
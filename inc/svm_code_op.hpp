#ifndef SVM_OP_CODE_HPP
#define SVM_OP_CODE_HPP

namespace svm {

class CodeOperation {
public:
    virtual bool Operate() = 0;
    virtual ~CodeOperation() = default;
protected:
    CodeOperation() = default;
    CodeOperation(const CodeOperation& a_other) = default;
    CodeOperation& operator=(const CodeOperation& a_other) = default;
};

} // svm

#endif /* SVM_OP_CODE_HPP */
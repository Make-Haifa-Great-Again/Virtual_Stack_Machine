#ifndef SVM_OPERATIONS_HPP
#define SVM_OPERATIONS_HPP

#include <ostream>

#include "svm_code_op.hpp"
#include "svm_code_segment.hpp"
#include "fsl_safe_stack.hpp"

namespace svm {

class OpNOP : public CodeOperation {
public:
    OpNOP() = default;
    OpNOP(const OpNOP& a_other) = default;
    OpNOP& operator=(const OpNOP& a_other) = default;
    ~OpNOP() = default;

    bool Operate() override;
};

template<typename T>
class OpADD : public CodeOperation {
public:
    OpADD(fsl::SafeStack<T>& a_safeStack);
    OpADD(const OpADD& a_other) = default;
    OpADD& operator=(const OpADD& a_other) = default;
    ~OpADD() = default;

    bool Operate() override;

private:
    fsl::SafeStack<T>& m_safeStack;
};

template<typename T>
class OpSUB : public CodeOperation {
public:
    OpSUB(fsl::SafeStack<T>& a_safeStack);
    OpSUB(const OpSUB& a_other) = default;
    OpSUB& operator=(const OpSUB& a_other) = default;
    ~OpSUB() = default;

    bool Operate() override;

private:
    fsl::SafeStack<T>& m_safeStack;
};

template<typename T>
class OpAND : public CodeOperation {
public:
    OpAND(fsl::SafeStack<T>& a_safeStack);
    OpAND(const OpAND& a_other) = default;
    OpAND& operator=(const OpAND& a_other) = default;
    ~OpAND() = default;

    bool Operate() override;

private:
    fsl::SafeStack<T>& m_safeStack;
};

template<typename T>
class OpOR : public CodeOperation {
public:
    OpOR(fsl::SafeStack<T>& a_safeStack);
    OpOR(const OpOR& a_other) = default;
    OpOR& operator=(const OpOR& a_other) = default;
    ~OpOR() = default;

    bool Operate() override;

private:
    fsl::SafeStack<T>& m_safeStack;
};

template<typename T>
class OpXOR : public CodeOperation {
public:
    OpXOR(fsl::SafeStack<T>& a_safeStack);
    OpXOR(const OpXOR& a_other) = default;
    OpXOR& operator=(const OpXOR& a_other) = default;
    ~OpXOR() = default;

    bool Operate() override;

private:
    fsl::SafeStack<T>& m_safeStack;
};

template<typename T>
class OpNOT : public CodeOperation {
public:
    OpNOT(fsl::SafeStack<T>& a_safeStack);
    OpNOT(const OpNOT& a_other) = default;
    OpNOT& operator=(const OpNOT& a_other) = default;
    ~OpNOT() = default;

    bool Operate() override;

private:
    fsl::SafeStack<T>& m_safeStack;
};

template<typename T>
class OpIN : public CodeOperation {
public:
    OpIN(fsl::SafeStack<T>& a_safeStack);
    OpIN(const OpIN& a_other) = default;
    OpIN& operator=(const OpIN& a_other) = default;
    ~OpIN() = default;

    bool Operate() override;

private:
    fsl::SafeStack<T>& m_safeStack;
};

template<typename T>
class OpOUT : public CodeOperation {
public:
    OpOUT(fsl::SafeStack<T>& a_safeStack, std::ostream& a_stream);
    OpOUT(const OpOUT& a_other) = default;
    OpOUT& operator=(const OpOUT& a_other) = default;
    ~OpOUT() = default;

    bool Operate() override;

private:
    fsl::SafeStack<T>& m_safeStack;
    std::ostream& m_stream;
};

template<typename T>
class OpLOAD : public CodeOperation {
public:
    OpLOAD(fsl::SafeStack<T>& a_safeStack, fsl::Memory<T>& a_memory);
    OpLOAD(const OpLOAD& a_other) = default;
    OpLOAD& operator=(const OpLOAD& a_other) = default;
    ~OpLOAD() = default;

    bool Operate() override;

private:
    fsl::SafeStack<T>& m_safeStack;
    fsl::Memory<T>& m_memory;
};

template<typename T>
class OpSTOR : public CodeOperation {
public:
    OpSTOR(fsl::SafeStack<T>& a_safeStack, fsl::Memory<T>& a_memory);
    OpSTOR(const OpSTOR& a_other) = default;
    OpSTOR& operator=(const OpSTOR& a_other) = default;
    ~OpSTOR() = default;

    bool Operate() override;

private:
    fsl::SafeStack<T>& m_safeStack;
    fsl::Memory<T>& m_memory;
};

template<typename T>
class OpJMP : public CodeOperation {
public:
    OpJMP(CodeSegment<T>& a_codeSegment, fsl::SafeStack<T>& a_safeStack);
    OpJMP(const OpJMP& a_other) = default;
    OpJMP& operator=(const OpJMP& a_other) = default;
    ~OpJMP() = default;

    bool Operate() override;

private:
    CodeSegment<T>& m_codeSegment;
    fsl::SafeStack<T>& m_safeStack;
};

template<typename T>
class OpJZ : public CodeOperation {
public:
    OpJZ(CodeSegment<T>& a_codeSegment, fsl::SafeStack<T>& a_safeStack);
    OpJZ(const OpJZ& a_other) = default;
    OpJZ& operator=(const OpJZ& a_other) = default;
    ~OpJZ() = default;

    bool Operate() override;

private:
    CodeSegment<T>& m_codeSegment;
    fsl::SafeStack<T>& m_safeStack;
};

template<typename T>
class OpPUSH : public CodeOperation {
public:
    OpPUSH(CodeSegment<T>& a_codeSegment, fsl::SafeStack<T>& a_safeStack);
    OpPUSH(const OpPUSH& a_other) = default;
    OpPUSH& operator=(const OpPUSH& a_other) = default;
    ~OpPUSH() = default;

    bool Operate() override;

private:
    CodeSegment<T>& m_codeSegment;
    fsl::SafeStack<T>& m_safeStack;
};

template<typename T>
class OpDUP : public CodeOperation {
public:
    OpDUP(fsl::SafeStack<T>& a_safeStack);
    OpDUP(const OpDUP& a_other) = default;
    OpDUP& operator=(const OpDUP& a_other) = default;
    ~OpDUP() = default;

    bool Operate() override;

private:
    fsl::SafeStack<T>& m_safeStack;
};

template<typename T>
class OpSWAP : public CodeOperation {
public:
    OpSWAP(fsl::SafeStack<T>& a_safeStack);
    OpSWAP(const OpSWAP& a_other) = default;
    OpSWAP& operator=(const OpSWAP& a_other) = default;
    ~OpSWAP() = default;

    bool Operate() override;

private:
    fsl::SafeStack<T>& m_safeStack;
};

template<typename T>
class OpROL3 : public CodeOperation {
public:
    OpROL3(fsl::SafeStack<T>& a_safeStack);
    OpROL3(const OpROL3& a_other) = default;
    OpROL3& operator=(const OpROL3& a_other) = default;
    ~OpROL3() = default;

    bool Operate() override;

private:
    fsl::SafeStack<T>& m_safeStack;
};

template<typename T>
class OpOUTNUM : public CodeOperation {
public:
    OpOUTNUM(fsl::SafeStack<T>& a_safeStack, std::ostream& a_stream);
    OpOUTNUM(const OpOUTNUM& a_other) = default;
    OpOUTNUM& operator=(const OpOUTNUM& a_other) = default;
    ~OpOUTNUM() = default;

    bool Operate() override;

private:
    fsl::SafeStack<T>& m_safeStack;
    std::ostream& m_stream;
};

template<typename T>
class OpINNUM : public CodeOperation {
public:
    OpINNUM(fsl::SafeStack<T>& a_safeStack);
    OpINNUM(const OpINNUM& a_other) = default;
    OpINNUM& operator=(const OpINNUM& a_other) = default;
    ~OpINNUM() = default;

    bool Operate() override;

private:
    fsl::SafeStack<T>& m_safeStack;
};

template<typename T>
class OpJNZ : public CodeOperation {
public:
    OpJNZ(CodeSegment<T>& a_codeSegment, fsl::SafeStack<T>& a_safeStack);
    OpJNZ(const OpJNZ& a_other) = default;
    OpJNZ& operator=(const OpJNZ& a_other) = default;
    ~OpJNZ() = default;

    bool Operate() override;

private:
    CodeSegment<T>& m_codeSegment;
    fsl::SafeStack<T>& m_safeStack;
};

template<typename T>
class OpDROP : public CodeOperation {
public:
    OpDROP(fsl::SafeStack<T>& a_safeStack);
    OpDROP(const OpDROP& a_other) = default;
    OpDROP& operator=(const OpDROP& a_other) = default;
    ~OpDROP() = default;

    bool Operate() override;

private:
    fsl::SafeStack<T>& m_safeStack;
};

template<typename T>
class OpCOMPL : public CodeOperation {
public:
    OpCOMPL(fsl::SafeStack<T>& a_safeStack);
    OpCOMPL(const OpCOMPL& a_other) = default;
    OpCOMPL& operator=(const OpCOMPL& a_other) = default;
    ~OpCOMPL() = default;

    bool Operate() override;

private:
    fsl::SafeStack<T>& m_safeStack;
};

class OpHLT : public CodeOperation {
public:
    OpHLT() = default;
    OpHLT(const OpHLT& a_other) = default;
    OpHLT& operator=(const OpHLT& a_other) = default;
    ~OpHLT() = default;

    bool Operate() override;
};

    /* Phase Two */

template<typename T, typename IP>
class OpPUSHIP : public CodeOperation {
public:
    OpPUSHIP(CodeSegment<T>& a_codeSegment, fsl::SafeStack<IP>& a_IPstack);
    OpPUSHIP(const OpPUSHIP& a_other) = default;
    OpPUSHIP& operator=(const OpPUSHIP& a_other) = default;
    ~OpPUSHIP() = default;

    bool Operate() override;

private:
    CodeSegment<T>& m_codeSegment;
    fsl::SafeStack<IP>& m_IPstack;
};

template<typename T, typename IP>
class OpPOPIP : public CodeOperation {
public:
    OpPOPIP(CodeSegment<T>& a_codeSegment, fsl::SafeStack<IP>& a_IPstack);
    OpPOPIP(const OpPOPIP& a_other) = default;
    OpPOPIP& operator=(const OpPOPIP& a_other) = default;
    ~OpPOPIP() = default;

    bool Operate() override;

private:
    CodeSegment<T>& m_codeSegment;
    fsl::SafeStack<IP>& m_IPstack;
};

template<typename IP>
class OpDROPIP : public CodeOperation {
public:
    OpDROPIP(fsl::SafeStack<IP>& a_IPstack);
    OpDROPIP(const OpDROPIP& a_other) = default;
    OpDROPIP& operator=(const OpDROPIP& a_other) = default;
    ~OpDROPIP() = default;

    bool Operate() override;

private:
    fsl::SafeStack<IP>& m_IPstack;
};

} // svm

#include "svm_operations.hxx"

#endif /* SVM_OPERATIONS_HPP */
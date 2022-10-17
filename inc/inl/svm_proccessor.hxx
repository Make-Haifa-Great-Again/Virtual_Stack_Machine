#ifndef SVM_PROCCESSOR_HXX
#define SVM_PROCCESSOR_HXX

#include <ostream>
#include <unordered_map>
#include "fsl_memory.hpp"
#include "fsl_safe_stack.hpp"
#include "svm_code_op.hpp"
#include "svm_code_segment.hpp"
#include "svm_operations.hpp"
#include "svm_spam.hpp"

namespace svm {

template<typename T, typename IP>
Proccessor<T, IP>::Proccessor(std::ostream& a_output, fsl::Memory<T>& a_ram, fsl::SafeStack<T>& a_stack, fsl::SafeStack<IP>& a_IPstack)
: m_operations()
, m_output(a_output)
, m_ram(a_ram)
, m_stack(a_stack)
, m_IPstack(a_IPstack)
{}

template<typename T, typename IP>
void Proccessor<T, IP>::destroyOperations()
{
    struct CleanMap {
        void operator()(std::pair<T, CodeOperation*> a_pair) {
            delete a_pair.second;
        }
    };
    std::for_each(m_operations.begin(), m_operations.end(), CleanMap{});
}

template<typename T, typename IP>
std::ostream& Proccessor<T, IP>::Proccess(CodeSegment<T>& a_codeSegment)
{
    bool run = true;
    loadOperations(a_codeSegment);
    while (run) {
        ++a_codeSegment;
        run = m_operations.at(a_codeSegment.Get())->Operate();
    }
    destroyOperations();
    return m_output;
}

template<typename T, typename IP>
void Proccessor<T, IP>::loadOperations(CodeSegment<T>& a_codeSegment)
{
    m_operations[NOP] = new OpNOP{};
    m_operations[ADD] = new OpADD<T>{m_stack};
    m_operations[SUB] = new OpSUB<T>{m_stack};
    m_operations[AND] = new OpAND<T>{m_stack};
    m_operations[OR] = new OpOR<T>{m_stack};
    m_operations[XOR] = new OpXOR<T>{m_stack};
    m_operations[NOT] = new OpNOT<T>{m_stack};
    m_operations[IN] = new OpIN<T>{m_stack};
    m_operations[OUT] = new OpOUT<T>{m_stack, m_output};
    m_operations[LOAD] = new OpLOAD<T>{m_stack, m_ram};
    m_operations[STOR] = new OpSTOR<T>{m_stack, m_ram};
    m_operations[JMP] = new OpJMP<T>{a_codeSegment, m_stack};
    m_operations[JZ] = new OpJZ<T>{a_codeSegment, m_stack};
    m_operations[PUSH] = new OpPUSH<T>{a_codeSegment, m_stack};
    m_operations[DUP] = new OpDUP<T>{m_stack};
    m_operations[SWAP] = new OpSWAP<T>{m_stack};
    m_operations[ROL3] = new OpROL3<T>{m_stack};
    m_operations[OUTNUM] = new OpOUTNUM<T>{m_stack, m_output};
    m_operations[INNUM] = new OpINNUM<T>{m_stack};
    m_operations[JNZ] = new OpJNZ<T>{a_codeSegment, m_stack};
    m_operations[DROP] = new OpDROP<T>{m_stack};
    m_operations[COMPL] = new OpCOMPL<T>{m_stack};
    m_operations[AND] = new OpAND<T>{m_stack};
    m_operations[HLT] = new OpHLT{};
    /* Phase Two */
    m_operations[PUSHIP] = new OpPUSHIP<T, IP>{a_codeSegment, m_IPstack};
    m_operations[POPIP] = new OpPOPIP<T, IP>{a_codeSegment, m_IPstack};
    m_operations[DROPIP] = new OpDROPIP<IP>{m_IPstack};
}


} // svm

#endif /* SVM_PROCCESSOR_HXX */
#include "svm_stack_vm.hpp"

#include <stdexcept>
#include "svm_code_op.hpp"
#include "svm_proccessor.hpp"


namespace svm {

std::ostream& StackVM::TurnOnVirtualMachine(CodeSegment<word>& a_codeSegment)
{
    try {
        Proccessor<word, IP>{m_output, m_ram, m_stack, m_IPstack}.Proccess(a_codeSegment);
    } catch (const std::out_of_range& e) {
        return m_output << "\n\nAssembler Runtime Error: Unknown Command " 
                        << a_codeSegment.Get() 
                        << " Given.\n\nExecution Terminated.\n";
    } catch (const fsl::safe_stack_error& e) {
        return m_output << "\n\nAssembler Runtime Error: Stack Rules Broken. " 
                        << e.what()
                        << "\n\nExecution Terminated.\n";
    } catch (const code_segment_error& e) {
        return m_output << "\n\nAssembler Runtime Error: code_segment_error: " 
                        << e.what()
                        << "\n\nExecution Terminated.\n";
    } catch (const fsl::memory_error& e) {
        return m_output << "\n\nAssembler Runtime Error: memory_error: " 
                        << e.what()
                        << "\n\nExecution Terminated.\n";
    }
    return m_output;
}

} // svm
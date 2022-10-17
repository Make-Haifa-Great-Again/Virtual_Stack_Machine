#ifndef FSL_MEMORY_HPP
#define FSL_MEMORY_HPP

#include <exception>

namespace fsl {

class memory_error: public std::exception {
public:
    memory_error(const std::string& a_error);
    virtual const char* what() const throw();

private:
    std::string m_what;
};

template<typename T>
class Memory {
public:
    typedef T unit;
 
    Memory(size_t a_size = 1024);
    Memory(const Memory& a_other) = delete;
    Memory& operator=(const Memory& a_other) = delete;
    ~Memory();

    unit& at(size_t a_memoryAddress);

private:
    unit* m_ram;
    size_t m_size;
};

} // fsl

#include "fsl_memory.hxx"

#endif /* FSL_MEMORY_HPP */
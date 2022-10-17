#ifndef FSL_MEMORY_HXX
#define FSL_MEMORY_HXX

namespace fsl {

inline memory_error::memory_error(const std::string& a_error)
: m_what(a_error)
{}

inline const char* memory_error::what() const throw()
{
    return m_what.c_str();
}

template<typename T>
Memory<T>::Memory(size_t a_size)
: m_ram(new T[a_size])
, m_size(a_size)
{}

template<typename T>
Memory<T>::~Memory()
{
    delete[] m_ram;
}

template<typename T>
typename Memory<T>::unit& Memory<T>::at(size_t a_memoryAddress)
{
    if (a_memoryAddress >= m_size) {
        throw memory_error("Attempt to access an out-of-bound segment in simulated memory detected.");
    }
    return m_ram[a_memoryAddress];
}

} // fsl

#endif /* FSL_MEMORY_HXX */

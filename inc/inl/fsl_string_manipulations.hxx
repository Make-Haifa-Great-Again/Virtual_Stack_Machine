#ifndef FSL_STRING_MANIPULATIONS_HXX
#define FSL_STRING_MANIPULATIONS_HXX

#include <string>
#include <sstream>

namespace fsl {

inline bool IsNumeric(const std::string& a_string)
{
    std::string::const_iterator read = a_string.cbegin();
    std::string::const_iterator stopAt = a_string.cend();
    while (read != stopAt) {
        if (*read < '0' || *read > '9') {
            return false;
        }
        ++read;
    }
    return true;
}

inline bool IsNumeric(char a_char)
{
    if (a_char < '0' || a_char > '9') {
        return false;
    }
    return true;
}

template<typename T>
inline T NumFromString(const std::string& a_string)
{
    std::stringstream str_ss{a_string};
    T result;
    str_ss >> result;
    return result;
}

} // fsl

#endif /* FSL_STRING_MANIPULATIONS_HXX */

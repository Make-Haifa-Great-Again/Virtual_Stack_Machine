#ifndef FSL_STRING_MANIPULATIONS_HPP
#define FSL_STRING_MANIPULATIONS_HPP

#include <string>

namespace fsl {

bool IsNumeric(const std::string& a_string);

bool IsNumeric(char a_char);

template<typename T>
T NumFromString(const std::string& a_string);

} // fsl

#include "fsl_string_manipulations.hxx"

#endif /* FSL_STRING_MANIPULATIONS_HPP */

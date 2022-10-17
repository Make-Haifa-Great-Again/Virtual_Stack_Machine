#ifndef FSL_PARSER_HPP
#define FSL_PARSER_HPP

#include <vector>
#include <string>
#include <istream>

namespace fsl {

typedef std::vector<std::string> CleanCode;

class Parser {
public:
    Parser() = default;
    Parser(const Parser& a_other) = default;
    Parser& operator=(const Parser& a_other) = default;
    ~Parser() = default;

    CleanCode Parse(std::istream& a_input, const char* a_commentDelim = "#") const;
};

} // fsl

#include "fsl_parser.hxx"

#endif /* FSL_PARSER_HPP */
#ifndef FSL_PARSER_HXX
#define FSL_PARSER_HXX

#include <vector>
#include <string>
#include <istream>
#include <sstream>
#include <cstring>

namespace fsl {

inline CleanCode Parser::Parse(std::istream& a_input, const char* a_commentDelim) const
{
    CleanCode parsed;
    std::string input;
    getline(a_input, input, static_cast<char>(EOF));
    std::stringstream input_ss{input};
    std::string line;
    std::string word;
    size_t commentDelimLen = strlen(a_commentDelim);
    while (input_ss.good()) {
        getline(input_ss, line, '\n');
        std::stringstream line_ss{line};
        while (line_ss.good()) {
            word.clear();
            getline(line_ss, word, ' ');
            if (!word.empty()) {
                if (!memcmp(a_commentDelim, word.c_str(), commentDelimLen)) {
                    break;
                }
                parsed.push_back(word);
            }
        }
        line.clear();
    }
    return parsed;
}

} // fsl


#endif /* FSL_PARSER_HXX */
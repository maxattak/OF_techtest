#ifndef OF_TECHTEST_STRINGUTIL_H
#define OF_TECHTEST_STRINGUTIL_H

#include <vector>
#include <regex>

namespace StringUtil
{
    /**
     * Split a string given a delimiter. The delimiter can be a regex.
     * @param input_ the string to split
     * @param delim_ the delimiter to use. Can be a regex.
     * @return a vector containing the split string
     */
    static std::vector<std::string> split(const std::string& input_, const std::string& delim_)
    {
        std::regex re(delim_);
        return std::vector<std::string> (std::sregex_token_iterator(input_.begin(), input_.end(), re, -1),
                                         std::sregex_token_iterator());
    }
}

#endif //OF_TECHTEST_STRINGUTIL_H

//
// Created by Max on 2019-12-01.
//
#ifndef OF_TECHTEST_STRINGUTIL_H
#define OF_TECHTEST_STRINGUTIL_H

#include <vector>
#include <regex>

namespace StringUtil
{
    static std::vector<std::string> split(const std::string& input_, const std::string& delim_)
    {
        std::regex re(delim_);
        return std::vector<std::string> (std::sregex_token_iterator(input_.begin(), input_.end(), re, -1),
                                         std::sregex_token_iterator());
    }
}

#endif //OF_TECHTEST_STRINGUTIL_H

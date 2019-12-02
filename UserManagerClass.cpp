#include <fstream>
#include <iostream>
#include "StringUtil.h"
#include "UserManagerClass.h"

const std::string UserManagerClass::USER_ACCESS_CONF_FILEPATH("../etc/authorized_user.conf");

UserManagerClass::UserManagerClass()
{
    std::ifstream confFile(USER_ACCESS_CONF_FILEPATH);
    std::string line;

    while (std::getline(confFile, line))
    {
        if(!line.empty())
        {
            try
            {
                auto splitLine = StringUtil::split(line, ",");

                if (splitLine.size() != 2)
                {
                    throw std::invalid_argument("Invalid number of fields, expected (ID,access type)");
                }

                uint64_t userId = std::stoull(splitLine[0]);
                UserAccessType accessType = UserAccessType::INVALID;

                if (splitLine[1] == "EMPLOYEE")
                {
                    accessType = UserAccessType::EMPLOYEE;
                }
                else if (splitLine[1] == "TECHNICIAN")
                {
                    accessType = UserAccessType::TECHNICIAN;
                }
                else
                {
                    std::cerr << "Unrecognized employee type `" << splitLine[1] << "`. Setting ID as INVALID."
                              << std::endl;
                }

                _userMap.emplace(userId, accessType);
            }
            catch (const std::exception& ex_)
            {
                std::cerr << "ERROR: skipping the entry `" << line << "`: " << ex_.what() << std::endl;
            }
        }
    }
}

UserManagerClass::~UserManagerClass()
{
    _userMap.clear();
}

UserManagerClass::UserAccessType UserManagerClass::getUserAccess(uint64_t userId_) const
{
    try
    {
        return _userMap.at(userId_);
    }
    catch (const std::out_of_range&)
    {
        return UserAccessType::INVALID;
    }

}

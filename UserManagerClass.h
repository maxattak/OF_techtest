#ifndef OPENFLEET_TECHTEST_USERMANAGERCLASS_H
#define OPENFLEET_TECHTEST_USERMANAGERCLASS_H


#include <unordered_map>

class UserManagerClass
{
public:
    UserManagerClass();
    ~UserManagerClass();

    enum class UserAccessType
    {
        EMPLOYEE,
        TECHNICIAN,
        INVALID
    };

    static const std::string USER_ACCESS_CONF_FILEPATH;

    UserAccessType getUserAccess(uint64_t userId_) const;

private:
    std::unordered_map<uint64_t, UserAccessType> _userMap;
};


#endif //OPENFLEET_TECHTEST_USERMANAGERCLASS_H

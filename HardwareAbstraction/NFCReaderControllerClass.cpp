#include <iostream>
#include <fstream>
#include "../UserManagerClass.h"

#include "NFCReaderControllerClass.h"

uint64_t NFCReaderControllerClass::readCard() const
{
    uint64_t userId = 0;

    while (userId == 0)
    {
        std::cout << "Authorized users: " << std::endl;

        std::ifstream confFile(UserManagerClass::USER_ACCESS_CONF_FILEPATH);

        std::string line;
        while (std::getline(confFile, line))
        {
            std::cout << "  " << line << std::endl;
        }
        std::cout << "Enter user ID: >";

        std::string rawInput;
        std::cin >> userId;
    }
}

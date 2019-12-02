#include <iostream>
#include <unistd.h>

#include "VendingMachineOperatorClass.h"

namespace
{
    void fakeProcessingLog(const std::string& log)
    {
        std::cout << log;
        for (int i = 0; i < 3; ++i)
        {
            usleep(500 * 1000);
            std::cout << ".";
        }

        std::cout << std::endl;
    }
}

void VendingMachineOperatorClass::run()
{
    while (1)
    {
        if (_isItemSaleEnable) _inventoryManager->printInventory();
        printf("\n"
               "  R - Read NFC Card\n"
               "  X - Cancel\n");

        std::string selection;
        std::cout << "Enter selection: >";
        std::cin >> selection;

        if (selection == "x" || selection == "X")
        {
            break;
        }
        else if (selection == "r" || selection == "R")
        {
            uint64_t cardId = _nfcReaderController->readCard();

            auto userAccess = _userManager->getUserAccess(cardId);

            switch(userAccess)
            {
                case UserManagerClass::UserAccessType::EMPLOYEE:
                    brewCoffee();
                    break;
                case UserManagerClass::UserAccessType::TECHNICIAN:
                    startMaintenanceMode(cardId);
                    break;
                case UserManagerClass::UserAccessType::INVALID:
                default:
                    std::cerr << "Invalid card ID: " << cardId;
                    break;
            }
            continue;
        }
        else if (_isItemSaleEnable)
        {
            int priceToPay = _inventoryManager->getItemPrice(selection);
            if (priceToPay != 0)
            {
                std::cout << "Insert coin to buy " << _inventoryManager->getItemDescription(selection) << std::endl;

                while (priceToPay > 0)
                {
                    std::cout << (priceToPay / 100.0) << " left to pay" << std::endl;
                    int coinValue = _coinAcceptor->readCoin();

                    if (coinValue < 0)
                    {
                        std::cout << "Transaction cancelled" << std::endl;
                        break;
                    }

                    priceToPay -= coinValue;
                }

                if (priceToPay <= 0)
                {
                    std::cout << "Thank you, don't forget you snack." << std::endl;
                }
            } else
            {
                std::cout << "Product not in the inventory" << std::endl;
            }
        }
    }

    std::cout << "Exiting main logic" << std::endl;
}

void VendingMachineOperatorClass::brewCoffee() const
{
    fakeProcessingLog("Brewing coffee");
}

void VendingMachineOperatorClass::startMaintenanceMode(uint64_t techId_)
{
    std::cout << "Tech ID " << techId_ << " entered maintenance mode" << std::endl;
    fakeProcessingLog("Running diagnose tests");

    bool exit = false;
    while (!exit)
    {
        std::cout << "Select action to perform:\n"
                  << "  I - " << (_isItemSaleEnable ? "Dis" : "En") << "able item sale\n"
                  << "  S - Reset machine\n\n"
                  << "  R - Read card\n\n"
                  << "Your selection: >";

        char input;
        std::cin >> input;

        if (std::toupper(input) == 'I')
        {
            _isItemSaleEnable = !_isItemSaleEnable;
        }
        else if (std::toupper(input) == 'S')
        {
            fakeProcessingLog("Resetting the machine");
        }
        else if (std::toupper(input) == 'R')
        {
            exit = (techId_ == _nfcReaderController->readCard());
        }
    }
}

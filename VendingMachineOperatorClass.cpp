#include <iostream>
#include <thread>
#include <unistd.h>
#include "VendingMachineOperatorClass.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
void VendingMachineOperatorClass::run()
{
    while (1)
    {
        _inventoryManager->printInventory();
        printf("\n"
               "  R - Read NFC Card\n"
               "  X - Cancel\n");

        std::string selection;
        std::cout << "Enter selection: ";
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
#pragma clang diagnostic pop

void VendingMachineOperatorClass::brewCoffee() const
{
    std::cout << "Brewing coffee";

    for (int i = 0; i < 3; ++i)
    {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
        usleep(500 * 1000);
#pragma clang diagnostic pop
        std::cout << ".";
    }
}

void VendingMachineOperatorClass::startMaintenanceMode(uint64_t techId_)
{
    std::cout << "Tech ID " << techId_ << " entered maintenance mode" << std::endl;
}

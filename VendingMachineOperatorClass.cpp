//
// Created by Max on 2019-12-01.
//

#include <iostream>
#include "VendingMachineOperatorClass.h"

void VendingMachineOperatorClass::run()
{
    while (1)
    {
        _inventoryManager->printInventory();

        std::string selection;
        std::cout << "Enter selection: ";
        std::cin >> selection;

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

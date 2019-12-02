#include <iostream>
#include <cctype>

#include "InventoryManagerClass.h"
#include "HardwareAbstraction/CoinAcceptorFactoryClass.h"
#include "VendingMachineOperatorClass.h"

int readModel();

int main() {
    int model = readModel();

    std::cout << "Model is " << (model == 1 ? "NA" : "EU") << std::endl;
    CoinAcceptorCurrencyEnum coinAcceptorCurrency =
         (model == 1) ? CoinAcceptorCurrencyEnum::Dollar : CoinAcceptorCurrencyEnum::Euro;

    auto coinAcceptor = CoinAcceptorFactoryClass::createCoinAcceptor(coinAcceptorCurrency);
    std::shared_ptr<InventoryManagerClass> inventoryManager = std::make_shared<InventoryManagerClass>();

    VendingMachineOperatorClass vendingMachineOperator(coinAcceptor, inventoryManager);

    vendingMachineOperator.run();

    return 0;
}

int readModel() {
    int model = 0;

    while (model != 1 && model != 2)
    {
        printf("Select machine model: \n"
               "  1 - NA\n"
               "  2 - EU\n");
        std::cin >> model;
    }
    return model;
}

#include <iostream>

#include "InventoryManagerClass.h"
#include "HardwareAbstraction/CoinAcceptorFactoryClass.h"
#include "HardwareAbstraction/NFCReaderControllerClass.h"
#include "UserManagerClass.h"
#include "VendingMachineOperatorClass.h"

int readModel();

int main() {
    int model = readModel();

    std::cout << "Model is " << (model == 1 ? "NA" : "EU") << std::endl;

    CoinAcceptorCurrencyEnum coinAcceptorCurrency =
         (model == 1) ? CoinAcceptorCurrencyEnum::Dollar : CoinAcceptorCurrencyEnum::Euro;

    auto coinAcceptor = CoinAcceptorFactoryClass::getInstance().createCoinAcceptor(coinAcceptorCurrency);
    std::shared_ptr<InventoryManagerClass> inventoryManager = std::make_shared<InventoryManagerClass>();
    std::shared_ptr<UserManagerClass> userManager = std::make_shared<UserManagerClass>();
    std::shared_ptr<NFCReaderControllerClass> nfcReader = std::make_shared<NFCReaderControllerClass>();

    if (!coinAcceptor || !inventoryManager || !userManager || !nfcReader)
    {
        std::cerr << "Initialization failed!" << std::endl;
        return -1;
    }

    VendingMachineOperatorClass vendingMachineOperator(coinAcceptor, inventoryManager, userManager, nfcReader);

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

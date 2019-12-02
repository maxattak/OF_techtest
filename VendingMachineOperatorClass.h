//
// Created by Max on 2019-12-01.
//
#ifndef OPENFLEET_TECHTEST_VENDINGMACHINEOPERATORCLASS_H
#define OPENFLEET_TECHTEST_VENDINGMACHINEOPERATORCLASS_H

#include <memory>
#include "InventoryManagerClass.h"
#include "HardwareAbstraction/CoinAcceptorInterface.h"

class VendingMachineOperatorClass
{
public:
    VendingMachineOperatorClass(const std::shared_ptr<CoinAcceptorInterface>& coinAcceptor_,
            const std::shared_ptr<InventoryManagerClass>& inventoryManager_) :
            _coinAcceptor(coinAcceptor_),
            _inventoryManager(inventoryManager_)
    {}

    void run();

private:
    std::shared_ptr<CoinAcceptorInterface> _coinAcceptor;
    std::shared_ptr<InventoryManagerClass> _inventoryManager;
};


#endif //OPENFLEET_TECHTEST_VENDINGMACHINEOPERATORCLASS_H

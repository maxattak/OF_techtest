#ifndef OPENFLEET_TECHTEST_VENDINGMACHINEOPERATORCLASS_H
#define OPENFLEET_TECHTEST_VENDINGMACHINEOPERATORCLASS_H

#include <memory>
#include "InventoryManagerClass.h"
#include "HardwareAbstraction/CoinAcceptorInterface.h"
#include "HardwareAbstraction/NFCReaderControllerClass.h"
#include "UserManagerClass.h"

class VendingMachineOperatorClass
{
public:
    VendingMachineOperatorClass(const std::shared_ptr<CoinAcceptorInterface>& coinAcceptor_,
            const std::shared_ptr<InventoryManagerClass>& inventoryManager_,
            const std::shared_ptr<UserManagerClass>& userManager_,
            const std::shared_ptr<NFCReaderControllerClass>& nfcReaderController_):
            _coinAcceptor(coinAcceptor_),
            _inventoryManager(inventoryManager_),
            _userManager(userManager_),
            _nfcReaderController(nfcReaderController_),
            _isItemSaleEnable(true) {}

    void run();

private:
    void brewCoffee() const;

    void startMaintenanceMode(uint64_t techId_);

    bool _isItemSaleEnable;

    std::shared_ptr<CoinAcceptorInterface> _coinAcceptor;
    std::shared_ptr<InventoryManagerClass> _inventoryManager;
    std::shared_ptr<UserManagerClass> _userManager;
    std::shared_ptr<NFCReaderControllerClass> _nfcReaderController;
};


#endif //OPENFLEET_TECHTEST_VENDINGMACHINEOPERATORCLASS_H

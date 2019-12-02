#ifndef OF_TECHTEST_NFCREADERCONTROLLERCLASS_H
#define OF_TECHTEST_NFCREADERCONTROLLERCLASS_H


#include <cstdint>

class NFCReaderControllerClass
{
public:
    NFCReaderControllerClass() = default;

    /**
     * Read and return the card ID associtated to the read card. An invalid card does not return any value.
     * @return the card ID of the read card
     */
    uint64_t readCard() const;
};


#endif //OF_TECHTEST_NFCREADERCONTROLLERCLASS_H

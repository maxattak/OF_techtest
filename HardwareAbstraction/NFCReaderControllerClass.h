#ifndef OPENFLEET_TECHTEST_NFCREADERCONTROLLERCLASS_H
#define OPENFLEET_TECHTEST_NFCREADERCONTROLLERCLASS_H


#include <cstdint>

class NFCReaderControllerClass
{
public:
    NFCReaderControllerClass() = default;

    uint64_t readCard() const;
};


#endif //OPENFLEET_TECHTEST_NFCREADERCONTROLLERCLASS_H

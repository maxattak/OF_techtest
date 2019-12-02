#ifndef OF_TECHTEST_COINACCEPTORDOLLARCLASS_H
#define OF_TECHTEST_COINACCEPTORDOLLARCLASS_H

#include "CoinAcceptorInterface.h"

/*
 * This class might seem useless, in a real scenario it would be intended to
 * interpret the signal coming directly from the coin acceptor and returning a value (in cents)
 */
class CoinAcceptorDollarClass : public CoinAcceptorInterface
{
public:
    CoinAcceptorDollarClass() = default;
    ~CoinAcceptorDollarClass() override = default;

    /**
     * Returns the value of the coin in cents
     * Test purpose: Returns a negative value to cancel
     * @return the value of the inserted coin in cents
     */
    int readCoin() override;
};


#endif //OF_TECHTEST_COINACCEPTORDOLLARCLASS_H

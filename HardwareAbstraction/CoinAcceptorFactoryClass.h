#ifndef OF_TECHTEST_COINACCEPTORFACTORYCLASS_H
#define OF_TECHTEST_COINACCEPTORFACTORYCLASS_H

#include <memory>
#include "CoinAcceptorInterface.h"

enum class CoinAcceptorCurrencyEnum
{
    Dollar,
    Euro
};

class CoinAcceptorFactoryClass
{
public:
    CoinAcceptorFactoryClass(CoinAcceptorFactoryClass& origin) = delete;
    CoinAcceptorFactoryClass(CoinAcceptorFactoryClass&& origin) = delete;

    static CoinAcceptorFactoryClass& getInstance()
    {
        static CoinAcceptorFactoryClass instance;
        return instance;
    }

    /**
     * Create the correct driver class for the coin acceptor depending on the currency to use
     * @param currency The currency to use
     * @return The driver class for the coin acceptor. Might return a null pointer if the currency is invalid
     */
    std::shared_ptr<CoinAcceptorInterface> createCoinAcceptor(CoinAcceptorCurrencyEnum currency);

private:
    CoinAcceptorFactoryClass() = default;
};


#endif //OF_TECHTEST_COINACCEPTORFACTORYCLASS_H

#include "CoinAcceptorDollarClass.h"
#include "CoinAcceptorEuroClass.h"

#include "CoinAcceptorFactoryClass.h"

std::shared_ptr<CoinAcceptorInterface> CoinAcceptorFactoryClass::createCoinAcceptor(CoinAcceptorCurrencyEnum currency)
{
    std::shared_ptr<CoinAcceptorInterface> coinAcceptor;

    switch (currency)
    {
        case CoinAcceptorCurrencyEnum::Dollar:
            coinAcceptor = std::make_shared<CoinAcceptorDollarClass>();
            break;
        case CoinAcceptorCurrencyEnum::Euro:
            coinAcceptor = std::make_shared<CoinAcceptorEuroClass>();
            break;
        default:
            break;
    }

    return coinAcceptor;
}

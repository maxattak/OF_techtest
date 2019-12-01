//
// Created by Max on 2019-12-01.
//
#ifndef OPENFLEET_TECHTEST_COINACCEPTORFACTORYCLASS_H
#define OPENFLEET_TECHTEST_COINACCEPTORFACTORYCLASS_H

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
    CoinAcceptorFactoryClass() = delete;
    CoinAcceptorFactoryClass(CoinAcceptorFactoryClass& origin) = delete;

    static std::shared_ptr<CoinAcceptorInterface> createCoinAcceptor(CoinAcceptorCurrencyEnum currency);
};


#endif //OPENFLEET_TECHTEST_COINACCEPTORFACTORYCLASS_H

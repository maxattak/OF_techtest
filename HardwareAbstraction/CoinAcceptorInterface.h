//
// Created by Max on 2019-12-01.
//
#ifndef OF_TECHTEST_COINACCEPTORINSTANCE_H
#define OF_TECHTEST_COINACCEPTORINSTANCE_H

class CoinAcceptorInterface
{
public:
    virtual ~CoinAcceptorInterface() = default;

    virtual int readCoin() = 0;
};

#endif //OF_TECHTEST_COINACCEPTORINSTANCE_H

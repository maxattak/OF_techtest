//
// Created by Max on 2019-12-01.
//
#include <cstdio>
#include <iostream>

#include "CoinAcceptorDollarClass.h"

int CoinAcceptorDollarClass::readCoin() {
    char input = '\0';
    int coinValue = 0;

    while (coinValue == 0)
    {
        printf("Insert coin:\n"
               "  1 - 5c\n"
               "  2 - 10c\n"
               "  3 - 25c\n"
               "  4 - 1$\n"
               "  5 - 2$\n\n"
               "  X - Cancel\n");

        std::cin >> input;
        switch (input)
        {
            case '1':
                coinValue = 5;
                break;
            case '2':
                coinValue = 10;
                break;
            case '3':
                coinValue = 25;
                break;
            case '4':
                coinValue = 100;
                break;
            case '5':
                coinValue = 200;
                break;
            case 'X':
            case 'x':
                coinValue = -1;
                break;
            default:
                break;
        }
    }

    return coinValue;
}

#include <cstdio>
#include <iostream>

#include "CoinAcceptorEuroClass.h"

int CoinAcceptorEuroClass::readCoin() {
    char input = '\0';
    int coinValue = 0;

    while (coinValue == 0)
    {
        printf("Insert coin:\n"
               "  1 - 1c\n"
               "  2 - 2c\n"
               "  3 - 5c\n"
               "  4 - 10c\n"
               "  5 - 20c\n"
               "  6 - 50c\n"
               "  7 - 1e\n"
               "  8 - 2e\n\n"
               "  X - Cancel\n");

        std::cin >> input;
        switch (input)
        {
            case '1':
                coinValue = 1;
                break;
            case '2':
                coinValue = 2;
                break;
            case '3':
                coinValue = 5;
                break;
            case '4':
                coinValue = 10;
                break;
            case '5':
                coinValue = 20;
                break;
            case '6':
                coinValue = 50;
                break;
            case '7':
                coinValue = 100;
                break;
            case '8':
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

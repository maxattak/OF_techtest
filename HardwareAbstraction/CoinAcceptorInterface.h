#ifndef OF_TECHTEST_COINACCEPTORINSTANCE_H
#define OF_TECHTEST_COINACCEPTORINSTANCE_H

/**
 * Interface to allow the use of multiple models of coin acceptors
 */
class CoinAcceptorInterface
{
public:
    virtual ~CoinAcceptorInterface() = default;

    /**
     * Read and return the value of the inserted coin in cents
     * An invalid coin won't return any value
     * @return The value of the coin in cents
     */
    virtual int readCoin() = 0;
};

#endif //OF_TECHTEST_COINACCEPTORINSTANCE_H

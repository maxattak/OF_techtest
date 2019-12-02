#ifndef OPENFLEET_TECHTEST_INVENTORYMANAGERCLASS_H
#define OPENFLEET_TECHTEST_INVENTORYMANAGERCLASS_H


#include <string>
#include <map>

struct Item
{
    Item(std::string &description_, int price_) :
        _description(description_),
        _price(price_)
    {
        /* No logic body */
    }
    std::string _description;
    int _price;
};

class InventoryManagerClass
{
public:
    InventoryManagerClass();
    ~InventoryManagerClass();

    static const std::string INVENTORY_CONF_FILEPATH;

    std::string getItemDescription(const std::string& itemId_) const;
    int getItemPrice(const std::string& itemId_) const;

    /**
     * For test purpose, prints the content of the inventory
     */
    void printInventory();

private:
    std::map<std::string, Item> _inventoryMap;
};

#endif //OPENFLEET_TECHTEST_INVENTORYMANAGERCLASS_H

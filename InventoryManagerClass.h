#ifndef OF_TECHTEST_INVENTORYMANAGERCLASS_H
#define OF_TECHTEST_INVENTORYMANAGERCLASS_H


#include <string>
#include <map>

struct Item
{
    Item(std::string &description_, int price_) :
        _description(description_),
        _price(price_) {}

    std::string _description;
    int _price;
};

class InventoryManagerClass
{
public:
    InventoryManagerClass();
    ~InventoryManagerClass();

    static const std::string INVENTORY_CONF_FILEPATH;

    /**
     * Get the description of an item given its ID. An invalid ID gives an empty description
     * @param itemId_ The ID of the item
     * @return The description of the item. Empty string if invalid
     */
    std::string getItemDescription(const std::string& itemId_) const;

    /**
     * Get the price of an item given its ID. An invalid ID gives a null price
     * @param itemId_ The ID of the item
     * @return The price of the Item. A null price if invalid
     */
    int getItemPrice(const std::string& itemId_) const;

    /**
     * For test purpose, prints the content of the inventory
     */
    void printInventory();

private:
    std::map<std::string, Item> _inventoryMap;
};

#endif //OF_TECHTEST_INVENTORYMANAGERCLASS_H

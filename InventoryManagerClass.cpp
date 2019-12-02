//
// Created by Max on 2019-12-01.
//

#include <fstream>
#include <iostream>
#include "StringUtil.h"
#include "InventoryManagerClass.h"

const std::string InventoryManagerClass::INVENTORY_CONF_FILEPATH("../etc/inventory.conf");

InventoryManagerClass::InventoryManagerClass()
{
    std::fstream confFile(INVENTORY_CONF_FILEPATH);
    std::string line;
    while(std::getline(confFile, line))
    {
        if (!line.empty())
        {
            try
            {
                auto splitLine = StringUtil::split(line, ",");

                std::string description = splitLine[1];
                description.erase(std::remove(description.begin(), description.end(), '"'), description.end());

                int price = int(std::stof(splitLine[2]) * 100.0);

                Item item(description, price);
                _inventoryMap.emplace(splitLine[0], item);
            }
            catch (const std::exception& ex_)
            {
                std::cerr << "ERROR: skipping the entry `" << line << "`: " << ex_.what() << std::endl;
            }
        }
    }
}

InventoryManagerClass::~InventoryManagerClass()
{
    _inventoryMap.clear();
}

std::string InventoryManagerClass::getItemDescription(const std::string& itemId_) const
{
    try
    {
        return _inventoryMap.at(itemId_)._description;
    }
    catch (const std::out_of_range&)
    {
        return std::string();
    }
}

int InventoryManagerClass::getItemPrice(const std::string &itemId_) const
{
    try
    {
        return _inventoryMap.at(itemId_)._price;
    }
    catch (const std::out_of_range&)
    {
        return 0;
    }
}

void InventoryManagerClass::printInventory()
{
    std::cout << "This vending machine offers the following items:" << std::endl;
    for (const auto& item : _inventoryMap)
    {
        std::cout << "  " << item.first << " - " << item.second._description << ": "
                  << item.second._price / 100.0 << std::endl;
    }
}

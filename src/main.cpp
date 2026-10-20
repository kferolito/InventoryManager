#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
#include <algorithm>
#include "../include/Item.h"

#define MAX_MENU_INPUT 10

std::vector<Item> g_inventory;

void PrintMenu()
{
    std::cout << "|====InventoryManager====|\n";
    std::cout << "1. Add item\n";
    std::cout << "2. Remove item\n";
    std::cout << "3. Search for item\n";
    std::cout << "4. Display inventory\n";
    std::cout << "5. Exit\n";
}

void PrintInvalidInput()
{
    std::cout << "Invalid input!\n";
}

void AddItem(std::vector<Item>& inventory)
{
    Item item;
    std::string name;
    uint8_t category;
    uint32_t quantity;
    float price;

    std::cout << "Item name: ";
    std::getline(std::cin >> std::ws, name);

    std::cout << std::endl;

    std::cout << "Item type:\n";
    std::cout << "1. Food\n";
    std::cout << "2. Equipment\n";
    std::cout << "3. Materials\n";
    std::cout << "4. Misc\n";
    std::cin >> category;

    std::cout << std::endl;

    std::cout << "Item quantity: ";
    std::cin >> quantity;

    std::cout << std::endl;

    std::cout << "Item price: ";
    std::cin >> price;

    item.name = name;
    item.category = static_cast<ItemCategory>(category);
    item.quantity = quantity;
    item.price = price;

    inventory.push_back(item);
}

void RemoveItem(std::vector<Item>& inventory)
{
    std::string name;
    std::cout << "Item name: ";
    std::getline(std::cin >> std::ws, name);

    std::cout << std::endl;

    auto it = std::find_if(inventory.begin(), inventory.end(), 
    [&](const Item& item){
        return item.name == name;
    });

    if(it != inventory.end())
    {
        inventory.erase(it);
        std::cout << "Item removed successfully.\n";
    }
    else
    {
        std::cout << "Item not found.\n";
    }

    std::cout << std::endl;
}

bool ChooseMenuOption(int choice)
{
    switch(choice)
    {
        case 1:
            AddItem(g_inventory);
            return false;
        case 2:
            RemoveItem(g_inventory);
            return false;
        case 5:
            return true;
        default:
            return false;
    }
}

int main()
{
    bool shouldClose = false;

    while(!shouldClose)
    {
        PrintMenu();

        int menuChoice = 0;
        std::cin >> menuChoice;

        if(menuChoice < 1 || menuChoice > MAX_MENU_INPUT)
        {
            PrintInvalidInput();
        }
        else
        {
            shouldClose = ChooseMenuOption(menuChoice);
        }
    }

    return 0;
}
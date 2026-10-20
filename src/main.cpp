#include <iostream>
#include "../include/Item.h"

#define MAX_MENU_INPUT 10

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

bool ChooseMenuOption(int choice)
{
    switch(choice)
    {
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
#pragma once

#include <cstdint>
#include <string>

enum class ItemCategory : std::uint8_t
{
    Default = 0,
    Food,
    Equipment,
    Materials,
    Misc
};

struct Item
{
    std::string name;
    ItemCategory category;
    std::uint32_t quantity;
    float price;
};
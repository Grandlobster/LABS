#include <iostream>
#include <vector>
#include <algorithm>

struct Item
{
    std::string code;
    std::string name;
    float cost;
    int quantity;
};

void displayItem(const Item &item)
{
    std::cout << "Code: " << item.code << "\nName: " << item.name
              << "\nCost: " << item.cost << "\nQuantity: " << item.quantity
              << "\n --- --- ---" << std::endl;
}

bool compareItems(const Item &item1, const Item &item2)
{
    return item1.code < item2.code;
}

int main()
{
    std::vector<Item> itemRecords;

    Item item1 = {"B001", "Item1", 10.5, 20};
    Item item2 = {"A002", "Item4", 11.5, 15};
    Item item3 = {"C003", "Item2", 2.0, 30};

    itemRecords.push_back(item1);
    itemRecords.push_back(item2);
    itemRecords.push_back(item3);

    std::cout << "Original Item Records:"
              << "\n --- --- ---" << std::endl;
    for (const auto &item : itemRecords)
    {
        displayItem(item);
    }

    std::sort(itemRecords.begin(), itemRecords.end(), compareItems);

    std::cout << "\n\nSorted Item Records based on Item Code:"
              << "\n --- --- ---" << std::endl;
    for (const auto &item : itemRecords)
    {
        displayItem(item);
    }

    std::string searchCode;
    std::cout << "\nEnter Item Code to search: ";
    std::cin >> searchCode;

    auto result = std::find_if(itemRecords.begin(), itemRecords.end(),
                               [searchCode](const Item &item)
                               { return item.code == searchCode; });

    if (result != itemRecords.end())
    {
        std::cout << "Item found:" << std::endl;
        displayItem(*result);
    }
    else
    {
        std::cout << "Item with code " << searchCode << " not found." << std::endl;
    }

    return 0;
}

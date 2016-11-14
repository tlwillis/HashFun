#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cstdlib>
#include <string>

class hash{

private:
    static const int tableSize = 40;
    struct item
    {
        std::string name;
        std::string drink;
        item* next;
    };
    item* HashTable[tableSize];
    
public:
    hash();
    int Hash(std::string key);
    void AddItem(std::string name, std::string drink);
    int NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemsInIndex(int index);
    std::string FindDrink(std::string name);
    void RemoveItem(std::string name);
};

#endif /* HASH_H */


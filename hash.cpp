#include "hash.h"

hash::hash()
{
    for(int i = 0; i < tableSize; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->name = "NULL";
        HashTable[i]->drink = "NULL";
        HashTable[i]->next = NULL;
    }
}
int hash::Hash(std::string key)
{
    int hash = 0;
    
    for(int i = 0; i < key.length(); i++)
    {
        hash = (hash + (int)key[i]) *  17;
    }
    return (hash % tableSize);
}

void hash::AddItem(std::string name, std::string drink)
{
    int index = Hash(name);
    if(HashTable[index]->name == "NULL")
    {
    HashTable[index]->name = name;
    HashTable[index]->drink = drink;
    }
    else
    {
        item* ptr = HashTable[index];
        item* newp = new item;
        newp->name = name;
        newp->drink = drink;
        newp->next = NULL;
        
        while(ptr->next != NULL)
        {
        ptr = ptr->next;
        }
        ptr->next = newp;
    }
}

int hash::NumberOfItemsInIndex(int index)
{
    int count = 0;
    if(HashTable[index]->name == "NULL")
    {
        return 0;
    }
    else
    {
        count++;
        item* ptr = HashTable[index];
        while(ptr->next != NULL)
        {
        ptr = ptr->next;
        count++;
        }
        return count;
    }
}

void hash::PrintTable()
{
    int num;
    for(int i = 0; i < tableSize; i++)
    {
        num = NumberOfItemsInIndex(i);
        std::cout << "|-----------------------|\n";
        std::cout << "Index = " << i << std::endl;
        std::cout << HashTable[i]->name << std::endl;
        std::cout << HashTable[i]->drink << std::endl;
        std::cout << "Number of items is " << num << std::endl;
    }
}

void hash::PrintItemsInIndex(int index)
{
    item* ptr = HashTable[index];
    if(ptr->name == "NULL")
    {
        std::cout << "Index is empty\n";
    }
    else
    {
        while(ptr != NULL)
        {
            std::cout << "|-----------------------|\n";
            std::cout << ptr->name << " likes " << ptr->drink << std::endl;
            ptr = ptr->next;
        }
    }
}
std::string hash::FindDrink(std::string name)
{
    int index = Hash(name);
    bool foundName = false;
    std::string drink = "Name not found\n";
    item* ptr = HashTable[index];
    
    while((ptr != NULL) && (foundName == false))
    {
        if(ptr->name == name)
        {
            foundName = true;
            drink = ptr->drink;
        }
        ptr = ptr->next;
    }
    return drink;
}

void hash::RemoveItem(std::string name)
{
    int index = Hash(name);
    bool foundName = false;
    item* ptr1 = HashTable[index];
    item* delptr;
    item* ptr2;
    
    //Case 0, index is empty
    if(ptr1->name == "NULL")
    {
        std::cout << "Empty index";
    }
    //Case 1 - Only 1 item in index, matching name
    else if((ptr1->name == name) && (ptr1->next == NULL))
    {
        ptr1->name = "NULL";
        ptr1->drink = "NULL";
        std::cout << "Removed name, case 1\n";
    }    
    //Case 2 - Match found in first index, exists more items
    else if((ptr1->name == name) && (ptr1->next != NULL))
    {
        HashTable[index] = HashTable[index]->next;
        delete ptr1;
        std::cout << "Removed name, case 2\n";
    }
    //Case 3 - First item in index not match
    //Case 3.1 - Looked through all items, no match
    //Case 3.2 - Found item in further iterations
    else
    {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
        while((ptr1 != NULL) && (ptr1->name != name))
        {
            
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if(ptr1 == NULL)
        {
            std::cout << "Name not found, case 3.1\n";
        }
        else
        {
            delptr = ptr1;
            ptr1 = ptr1->next;
            ptr2->next = ptr1;
            delete delptr;
            std::cout << "Removed name, case 3.2\n";
        }
    }
}
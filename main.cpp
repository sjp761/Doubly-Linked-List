#include <iostream>
#include "DoublyLinkedList.h"

void PrintListWithInfo(std::string name, const DoublyLinkedList &list)
{
    std::cout << name << ": " << list;
    std::cout << std::endl;
}

int main() 
{    
    DoublyLinkedList list;

    for (int i = 0; i < 10; i++) 
    {
        list.push_front(i);
    }

    PrintListWithInfo("List after pushing front", list);
    list.insert(10, 1000000);
    PrintListWithInfo("List after inserting at end", list);
    list.erase (2);
    PrintListWithInfo("List after erasing index 2", list);
}
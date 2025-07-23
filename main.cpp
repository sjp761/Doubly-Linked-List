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

    PrintListWithInfo("List after pushing 10 elements", list);
    list.insert(100, 0);
    PrintListWithInfo("List after inserting 100 at index 0", list);
    list.insert(100, list.size());
    PrintListWithInfo("List after inserting 100 at index 10", list);
    list.insert(50, list.size() - 1);
    PrintListWithInfo("List after inserting 50 before last element", list);
}
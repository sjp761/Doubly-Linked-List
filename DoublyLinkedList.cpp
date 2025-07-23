#include "DoublyLinkedList.h"
#include <limits>


//Note: Index starts at 0

DoublyLinkedList::DoublyLinkedList()
    : head(nullptr)
{
    //blank
}

DoublyLinkedList::~DoublyLinkedList()
{
    while (head != nullptr)
    {
        pop_front();
    }
}

bool DoublyLinkedList::empty()
{
    return head == nullptr;
}

int DoublyLinkedList::size()
{
    int count = 0;
    LLNode *current = head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

void DoublyLinkedList::push_front(short value)
{
    if (empty())
    {
        head = new LLNode(value);
    }
    else
    {
        LLNode *newNode = new LLNode(value, nullptr , head);
        head->prev = newNode; //Set the previous of the unchanged head to the new node
        head = newNode; //New node is now the head. next points to the old one
    }
    
}

void DoublyLinkedList::pop_front()
{
    if (!empty())
    {
        LLNode *temp = head;
        head = head->next;
        delete temp;
    }
}

void DoublyLinkedList::insert(short value, int index)
{
    if (index < 0 || index > size()) //Check if index is valid
    {
        throw std::out_of_range("Index out of range");
    }

    if (size() <= 1 || index == 0) //Always insert if index is 0 or size is 1 or less (If the size is 1, then we dont need to do anything special to insert it)
    {
        push_front(value);
    }
    else if (index >= size() - 1) //Add to the end
    {
        LLNode *current = head; //Iterate through the list
        while (current->next != nullptr) //Stop at the last node
        {
            current = current->next;
        }
        LLNode *newNode = new LLNode(value, current, nullptr); //Create a new node with the last node as previous and nullptr as next
        current->next = newNode; //Set the next of the last node to the new node
    }

    else //Insert in the middle
    {
        LLNode *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        LLNode *newNode = new LLNode(value, current->prev, current);
        current->prev->next = newNode; //Go to the previous node and set its next to the new node
        current->prev = newNode; //We no longer need to reference the old previous node, so we set the current node's previous to the new node
    }
}

void DoublyLinkedList::erase(int index)
{
    if (index < 0 || index >= size()) //Check if index is valid
    {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        LLNode *current = head->next;
        for (int i = 1; i < index; i++) //Start at 1 since 0 is erased
        {
            current = current->next;
        }
        
        current->prev->next = current->next; //There will always be a previous node since we start at index 1
        
        if (current->next != nullptr)
        {
            current->next->prev = current->prev;
        }
        delete current;
    }
}

int DoublyLinkedList::find(short value)
{
    LLNode *current = head;
    int index = 0;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1; 
}

short DoublyLinkedList::operator[](int index)
{
    if (index < 0 || index >= size()) 
    {
        throw std::out_of_range("Index out of range"); 
    }
    LLNode* current = head;
    for (int i = 0; i < index; i++) 
    {
        current = current->next;
    }
    return current->data;
}

std::ostream &operator<<(std::ostream &os, const DoublyLinkedList &list)
{
    LLNode *current = list.head;
    while (current != nullptr)
    {
        os << current->data << " ";
        current = current->next;
    }
    return os;
}

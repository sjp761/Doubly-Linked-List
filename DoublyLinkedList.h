#include <ostream>

struct LLNode
{
    short data;
    LLNode *next;
    LLNode *prev;
    LLNode(short value, LLNode *prevNode = nullptr, LLNode *nextNode = nullptr)
        : data(value), prev(prevNode) ,next(nextNode)
        {
            //blank
        };
        
};


class DoublyLinkedList
{
    private:
        LLNode *head;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        bool empty();
        int size();
        void push_front(short value);
        void pop_front();
        void insert(short value, int index);
        void erase(int index);
        int find(short value);
        friend std::ostream& operator<<(std::ostream &os, const DoublyLinkedList &list);
        short operator[](int index);
        

    

};



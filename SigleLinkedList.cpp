#include <iostream>
using namespace std;

class SingleLinkedList
{
    private:
        struct node
        {
            int data;
            node* next;
        }* head;

        int size;
    
    public:
        SingleLinkedList()
        {
            head = NULL;
            size = 0;
        }

        
};

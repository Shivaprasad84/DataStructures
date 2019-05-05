#include <iostream>
using namespace std;

class SingleLinkedList
{
private:
    struct node
    {
        int data;
        node *next;
    } * head;

    int size;

    node *create_node(int x)
    {
        size++;
        node *newNode = new node;
        newNode->data = x;
        newNode->next = NULL;
        return newNode;
    }

public:
    SingleLinkedList()
    {
        head = NULL;
        size = 0;
    }

    void push_front(int x)
    {
        node *newNode = create_node(x);
        if (head != NULL)
        {
            newNode->next = head;
        }
        head = newNode;
    }

    void push_back(int x)
    {
        node *newNode = create_node(x);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            node *trav = head;
            while (trav->next != NULL)
            {
                trav = trav->next;
            }
            trav->next = newNode;
        }
    }

    int at(int index)
    {
        node *trav = head;
        for (int i = 0; i < index; i++)
        {
            trav = trav->next;
        }
        return trav->data;
    }

    void insert_at(int pos, int x)
    {
        node *newNode = create_node(x);
        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        node *trav = head;
        for (int i = 0; i < pos - 1; i++)
        {
            trav = trav->next;
        }
        newNode->next = trav->next;
        trav->next = newNode;
    }

    int operator[](int index)
    {
        return this->at(index);
    }

    void display()
    {
        node *trav = head;
        for (int i = 0; i < size; i++)
        {
            cout << trav->data << ", ";
            trav = trav->next;
        }
    }
};

int main()
{
    SingleLinkedList L1;
    for (int i = 0; i < 20; i++)
    {
        L1.push_back(i);
    }

    L1.insert_at(0, 100);
    L1.display();
}

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
    bool deleted;

public:
    SingleLinkedList()
    {
        head = NULL;
        size = 0;
        deleted = false;
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

    void replace_at(int pos, int x)
    {
        if(pos == 0)
        {
            head->data = x;
            return;
        }
        node* trav = head;
        for(int i = 0; i < pos-1; i++)
        {
            trav = trav->next;
        }
        (trav->next)->data = x;
    }


    int operator[](int index)
    {
        return this->at(index);
    }

    void delete_at(int pos)
    {
        size--;
        if(pos == 0)
        {
            node* temp = head;
            head = temp->next;
            delete temp;
            return;
        }
        node* trav = head;
        for(int i = 0; i < pos - 1; i++)
        {
            trav = trav->next;
        }
        node* temp = trav->next;
        trav->next = (trav->next)->next;
        delete temp;
    }

    void display() const
    {
        if(size == 0)
        {
            cout << "No Elements in List" << endl;
            return;
        }
        node *trav = head;
        for (int i = 0; i < size; i++)
        {
            cout << trav->data << ", ";
            trav = trav->next;
        }
        cout << endl;
    }

    const int getSize() const
    {
        return this->size;
    }

    void reverse()
    {
       for(int i = size-1; i >= size/2; i--)
       {
           int temp = this->at((size-1) - i); // get first element
           this->replace_at((size-1) - i, this->at(i)); // replace first element with last
           this->replace_at(i, temp); // replace last element with first
       }
    }

    void del_list()
    {
        node* trav = head;
        node* temp;
        while(trav->next != NULL)
        {
            temp = trav;
            trav = trav->next;
            delete temp;
            size--;
        }
        delete trav;
        size--; 
        deleted = true;  
    }

    ~SingleLinkedList()
    {
        if(!deleted)
        {
            this->del_list();
        }
        cout << "List deleted: Releasing memory..." << endl;
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
    L1.reverse();
    L1.display();
    L1.delete_at(0);
    L1.display();
    L1.replace_at(3, 999);
    L1.display();
    
    cout << "Length: " << L1.getSize() << endl;

    L1.del_list();

    L1.display();

}

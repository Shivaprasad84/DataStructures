#include <iostream>
using namespace std;

class queue
{
private:
    struct node
    {
        string data;
        node *next;
    } * first, *last;
    int size;

public:
    queue()
    {
        size = 0;
        first = NULL;
        last = NULL;
    }

    node *create_node(const string &data)
    {
        ++size;
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
        return temp;
    }

    void Enqueue(const string &data)
    {
        node *temp = create_node(data);
        if (first == NULL)
        {
            first = last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }

    string Dequeue()
    {
        if (!is_empty())
        {
            --size;
            node *temp = first;
            first = first->next;
            string Data = temp->data;
            delete temp;
            return Data;
        }
        else
        {
            cerr << " Queue is empty." << endl;
            return "";
        }
    }

    bool is_empty()
    {
        return (size == 0);
    }
};

int main()
{
    queue q;
    q.Enqueue("Person 1");
    q.Enqueue("Person 2");
    q.Enqueue("Person 3");
    q.Enqueue("Person 4");

    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
}
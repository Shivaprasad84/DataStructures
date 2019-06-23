#include <iostream>
using namespace std;

class Stack
{
private:
    struct node
    {
        char data;
        node *next;
    } * stack_top;
    int size;

public:
    Stack()
    {
        size = 0;
        stack_top = NULL;
    }

    node *create_node(char data)
    {
        ++size;
        node *newNode = new node;
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }

    void push(char data)
    {
        node *newNode = create_node(data);
        if (stack_top != NULL)
        {
            newNode->next = stack_top;
        }
        stack_top = newNode;
    }

    char top()
    {
        if(!this->is_empty())
        {
            return stack_top->data;
        }
        else
        {
            cerr << "Stack is empty." << endl;
        }
    }

    void pop()
    {
        if (!this->is_empty())
        {
            --size;
            node *temp = stack_top;
            stack_top = stack_top->next;
            delete temp;
        }
        else
        {
            cerr << "Stack is empty." << endl;
        }
    }

    bool is_empty()
    {
        return (size == 0);
    }
};

int main()
{
    Stack s;
    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}
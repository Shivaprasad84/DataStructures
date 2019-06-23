#include <iostream>
#include <queue>
using namespace std;

class Tree
{
private:
    struct node
    {
        int data;
        node *left_child;
        node *right_child;
    } * root;
    int size;

    node *create_node(int data)
    {
        ++size;
        node *temp = new node;
        temp->data = data;
        temp->left_child = NULL;
        temp->right_child = NULL;
        return temp;
    }

    int getHeight(node *Node)
    {
        if (Node == NULL)
        {
            return 0;
        }
        else
        {
            return 1 + Max(getHeight(Node->left_child), getHeight(Node->right_child));
        }
    }

    // Inorder Traversal
    void inorder(node *r)
    {
        if (r != NULL)
        {
            inorder(r->left_child);
            cout << r->data << " ";
            inorder(r->right_child);
        }
    }

    // Preorder Traversal
    void preorder(node *r)
    {
        if (r != NULL)
        {
            preorder(r->left_child);
            preorder(r->right_child);
            cout << r->data << " ";
        }
    }

    // Postorder Traversal
    void postorder(node *r)
    {
        if (r != NULL)
        {
            cout << r->data << " ";
            postorder(r->left_child);
            postorder(r->right_child);
        }
    }

    // Level order Traversal
    void bfs_level_order(node *r)
    {
        node *temp = NULL;
        queue<node *> q;
        q.push(r);
        while (!q.empty())
        {
            temp = q.front();
            cout << temp->data << " ";
            q.pop();
            if (temp->left_child != NULL)
                q.push(temp->left_child);
            if (temp->right_child != NULL)
                q.push(temp->right_child);
        }
    }

    int Max(int x, int y)
    {
        return (x > y) ? x : y;
    }

public:
    Tree()
    {
        size = 0;
        root = NULL;
    }

    void insert(int data)
    {
        node *temp = create_node(data);
        node *trail = root;
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            node *current = root;
            while (current != NULL)
            {
                trail = current;
                if (data == current->data)
                {
                    cout << "Cannot insert duplicate items" << endl;
                    return;
                }
                if (data < current->data)
                    current = current->left_child;
                else
                    current = current->right_child;
            }

            if (data > trail->data)
                trail->right_child = temp;
            else
                trail->left_child = temp;
        }
    }

    bool is_present(int data)
    {
        node *current = root;
        bool found = false;
        if (current == NULL)
        {
            return false;
        }
        else
        {
            while (current != NULL && !found)
            {
                if (data == current->data)
                {
                    found = true;
                }
                else if (data > current->data)
                {
                    current = current->right_child;
                }
                else
                {
                    current = current->left_child;
                }
            }
        }
        return found;
    }

    node *search(int data)
    {
        node *current = root;
        node *found = NULL;
        if (current == NULL)
        {
            return NULL;
        }
        else
        {
            while (current != NULL && !found)
            {
                if (data == current->data)
                {
                    found = current;
                }
                else if (data > current->data)
                {
                    current = current->right_child;
                }
                else
                {
                    current = current->left_child;
                }
            }
        }
        return found;
    }

    // Traversals

    // 1. Depth First Traversal

    // 1.1) Inorder
    void InorderTrav()
    {
        inorder(root);
    }

    // 1.2) Preorder
    void PreorderTrav()
    {
        preorder(root);
    }

    // 1.3) Postorder
    void PostorderTrav()
    {
        postorder(root);
    }

    // 2. Breadth First Traversal

    // 2.1) Level Order Traversal

    void LevelorderTrav()
    {
        bfs_level_order(root);
    }

    int getSize()
    {
        return size;
    }

    int Height(int data)
    {
        return getHeight(this->search(data));
    }
};

int main()
{
    Tree t;
    t.insert(12); // Root
    t.insert(1);
    t.insert(9);
    t.insert(13);
    t.insert(11);
    t.insert(21);
    t.insert(19);
    t.insert(5);
    t.insert(0);
    t.insert(17);

    cout << "Height of the tree: " << t.Height(12) << endl;

    cout << "Size: " << t.getSize() << endl;

    cout << "In order traversal: " << endl;
    t.InorderTrav();
    cout << endl;

    cout << "Level Order: " << endl;
    t.LevelorderTrav();
    cout << endl;

    if (t.is_present(13))
    {
        cout << "13 is present in the tree" << endl;
    }
    else
    {
        cout << "13 is not present in the tree" << endl;
    }

}

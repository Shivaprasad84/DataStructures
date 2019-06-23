#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Array
{
private:
    T *arr;
    int size, capacity;

public:
    Array()
    {
        size = 0;
        capacity = 1;
        arr = new T[capacity];
    }

    Array(int capacity) : capacity(capacity)
    {
        size = 0;
        arr = new T[capacity];
    }

    void set(int index, T data)
    {
        if (index >= 0 && index < capacity)
        {
            ++size;
            arr[index] = data;
        }
        else
        {
            cout << "Error: index out of range" << endl;
        }
    }

    T get(int index)
    {
        if (index >= 0 && index < capacity)
        {
            return arr[index];
        }
        else
        {
            cout << "Error: index out of range" << endl;
        }
    }

    void push_back(T data)
    {
        if (size == capacity)
        {
            capacity = capacity * 2;
            T *newArr = new T[capacity];
            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[i];
            }
            delete arr;
            arr = newArr;
        }
        arr[size] = data;
        ++size;
    }

    int getSize() const
    {
        return size;
    }

    int getCapacity() const
    {
        return capacity;
    }

    void Remove(int index)
    {
        if (index >= 0 && index < capacity)
        {
            for (int i = index; i < size - 1; i++)
            {
                arr[i] = arr[i+1];
            }
            --size;
        }
        else
        {
            cout << "Error: index out of range" << endl;
        }
    }

    T operator[] (int index)
    {
        return this->arr[index];
    }
};


int main()
{
    Array<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    for (int i = 0; i < a.getSize(); i++)
    {
        cout << a.get(i) << " ";
    }
    cout << endl;
    cout << a.getCapacity() << endl;
    cout << a.getSize() << endl;

    a.Remove(0);
    for (int i = 0; i < a.getSize(); i++)
    {
        cout << a.get(i) << " ";
    }
    cout << endl;
    Array<char> Ch_array;
    Ch_array.push_back('A');
    Ch_array.push_back('B');
    Ch_array.push_back('C');

    for(int i = 0; i < Ch_array.getSize(); i++)
    {
        cout << Ch_array[i] << " ";
    }
    cout << endl;
}
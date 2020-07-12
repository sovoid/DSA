#ifndef DATA_STRUCTURES_STACK_
#define DATA_STRUCTURES_STACK_

#include <cassert>
#include <iostream>

template <class Type>
struct node
{
    Type data;
    node<Type> *next;
};

template <class Type>
class stack
{
private:
    node<Type> *top;
    int size;

public:
    stack()
    {
        top = nullptr;
        size = 0;
    }

    explicit stack(const stack<Type> &otherStack)
    {
        if (top)
        {
            top = nullptr;
        }
        if (!otherStack.top)
        {
            top = nullptr;
        }
        else
        {
            node<Type> *current, *last, *newNode;
            current = otherStack.top;
            top = new node<Type>;
            top->data = current->data;
            top->next = nullptr;
            last = top;
            current = current->next;
            while (current)
            {
                newNode = new node<Type>;
                newNode->data = current->data;
                newNode->next = nullptr;
                last->next = newNode;
                last = newNode;
                current = current->next;
            }
        }
        size = otherStack.size;
        return *this;
    }

    ~stack() {}

    void push(Type item)
    {
        node<Type> *newNode = new node<Type>;
        newNode->data = item;
        newNode->next = top;
        top = newNode;
        size++;
    }

    Type peek()
    {
        assert(top != nullptr);
        return top->data;
    }

    Type pop()
    {
        if (!empty())
        {
            node<Type> *temp = top;
            top = top->next;
            delete temp;
            size--;
        }
        else
        {
            cout << "Stack is empty !" << endl;
        }
    }

    void clear()
    {
        node<Type> *temp;
        while (top)
        {
            temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool empty()
    {
        return (top != nullptr);
    }

    stack<Type> &operator=(const stack<Type> &otherStack)
    {
        node<Type> *newNode, *current, *last;

        if (top != nullptr)
        {
            top = nullptr;
        }
        if (otherStack.top == nullptr)
        {
            top = nullptr;
        }
        else
        {
            current = otherStack.top;
            top = new node<Type>;
            top->data = current->data;
            top->next = nullptr;
            last = top;
            current = current->next;

            while (current != nullptr)
            {
                newNode = new node<Type>;
                newNode->data = current->data;
                newNode->next = nullptr;
                last->next = newNode;
                last = newNode;
                current = current->next;
            }
        }
        size = otherStack.size;
        return *this;
    }
};

#endif
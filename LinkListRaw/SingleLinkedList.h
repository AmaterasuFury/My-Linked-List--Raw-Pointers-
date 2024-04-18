#pragma once
#include <iostream>

struct MyList
{
private:
    struct Node;
    
    int Size = 0;
    Node * FirstElement = nullptr;
    
public:
    void Add(int InValue);
    void RemoveOnIndex (int InIndex);
    void RemoveFirstElement();
    void RemoveLastElement();
    void RemoveValue(int InValue);
    int * Get (int InIndex);
    ~MyList();

    
    
    struct Node
    {
        int value;
        Node* Next = nullptr;
    };
};



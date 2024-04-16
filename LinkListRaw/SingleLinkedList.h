#pragma once
#include <iostream>

struct List
{
private:
    struct Node;
    //List();
    ~List();
    int Size = 0;
    Node * FirstElement = nullptr;
    
public:
    void Add(int InValue);
    void RemoveOnIndex (int InIndex);
    void RemoveFirstElement();
    void RemoveLastElement();
    void RemoveValue(int InValue);
    int * Get (int InIndex);
    
    
    
    struct Node
    {
        int value;
        Node* Next = nullptr;
    };
};



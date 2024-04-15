#pragma once
#include <stdlib.h>

struct List
{
    List();
    ~List();
    struct Node;
    
    int Size = 0;
    Node * FirstElement = nullptr;
    void Add(int Value);
    void Remove (int Index);
    void RemoveValue(int Value);
    int * Get (int Index);
    
    
    struct Node
    {
        int value;
        Node* Next;
    };
};

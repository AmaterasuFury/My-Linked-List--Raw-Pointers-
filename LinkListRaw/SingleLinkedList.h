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
    void RemoveByValue (int InValue);
    int FindElementOnIndex(int InIndex);    // Check the naming for all of the functions names
    int GetIndexByValue(int InValue);
    bool Contains (int InValue);
    void PushBack(int InValue);
    void PushFront(int InValue);
    void AddElementOnIndex (int InValue, int InIndex);
    void Clear();
    int  GetSizeOfList();
    ~MyList();
    
    struct Node
    {
        int value;
        Node* Next = nullptr;
    };
};



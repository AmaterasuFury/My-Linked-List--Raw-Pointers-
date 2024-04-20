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
    int FindElementByValue(int InValue);
    bool CheckIfValueExists (int InValue);
    void AddElementToTheEnd(int InValue);
    void AddElementToTheBeginning(int InValue);
    void AddElementOnIndex (int InValue, int InIndex);
    void ClearTheList();
    int  GetSizeOfList();
    ~MyList();
    
    struct Node
    {
        int value;
        Node* Next = nullptr;
    };
};



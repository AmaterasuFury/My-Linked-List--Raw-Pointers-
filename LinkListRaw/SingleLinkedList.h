#pragma once
#include <iostream>

struct MyList
{
private:

    struct Node
    {
        int value = 0;
        Node* Next = nullptr;
    };

    int Size = 0;
    Node * FirstElement = nullptr;
    
public:
    void Add(int InValue);
    void RemoveOnIndex (int InIndex);
    void RemoveFirstElement();
    void RemoveLastElement();
    void RemoveByValue (int InValue);
    int FindOnIndex(int InIndex);    // Check the naming for all of the functions names
    int GetIndexByValue(int InValue);
    bool Contains (int InValue);
    void PushBack(int InValue);
    void PushFront(int InValue);
    void AddElementOnIndex (int InValue, int InIndex);
    void Clear();
    int  GetSizeOfList();
    void MyList::SerializeToFile(const std::string InFileName, bool ClearListAfter = false);
    void MyList::DeserealizeFromFile(const std::string InFileName);
    ~MyList();
    
};



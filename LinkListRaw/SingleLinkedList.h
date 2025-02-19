#pragma once
#include <iostream>
#include <vector>

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

template <typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
    os << v.size() << ' ';
    for (const T& x : v)
    {
        os << x << ' ';
    }

    return os;
}

template <typename T> 
std::istream& operator >> (std::istream& is, std::vector<T>& v)
{
    size_t size;
    is >> size;

    v.clear();
    v.reserve(size)

    for (size_t i = 0; i < size; ++i)
    {
        T x;
        is >> x;
        v.push_back(x);
    }
    return is;
}



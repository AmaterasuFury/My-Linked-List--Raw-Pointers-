#include "SingleLinkedList.h"
#include <algorithm>


//List::List(){}

MyList::~MyList()
{
    Node * TempPtr = FirstElement;
    bool TempBool = false;
    while (!TempBool)
    {
        TempPtr = FirstElement->Next;
        delete FirstElement;
        FirstElement = TempPtr; 
        if (FirstElement->Next == nullptr)
        {
            TempBool = true;
        }
    }
    delete FirstElement;
    delete TempPtr;
    FirstElement = nullptr;
    TempPtr = nullptr;
}
  
void MyList::Add(int InValue)
{
    
    Node * TempPtr = FirstElement;

    if(Size == 0)
    {
        FirstElement = new Node;
        FirstElement->value = InValue;
        Size++;
        return;
    }
    else
    {
        while (TempPtr->Next != nullptr)
        {
            TempPtr = TempPtr->Next;
        }
        TempPtr->Next = new Node;
        TempPtr->Next->value = InValue;
    }
    if(TempPtr != nullptr)
    {
        TempPtr = nullptr;
    }
    Size++;
}

void MyList::RemoveOnIndex(int InIndex)
{
    if(Size ==0 || Size == 1)
    {
        RemoveFirstElement();
        return;
    }
    else
    {
        Node * TempPtrToRemove = FirstElement;
        Node * TempPtrToMoveThePtrToNext = nullptr;
        for (int i = 0; i <= InIndex; ++i)
        {
            
            if (i == InIndex-1)
            {
                TempPtrToMoveThePtrToNext = TempPtrToRemove;
            }
            TempPtrToRemove = TempPtrToRemove->Next;
        }
        TempPtrToMoveThePtrToNext->Next = TempPtrToRemove->Next;
        delete TempPtrToRemove;
        TempPtrToRemove = nullptr;
        TempPtrToMoveThePtrToNext = nullptr;
        Size --;
    }
    
}

void MyList::RemoveFirstElement()
{
    Node * TempPtr =nullptr;
    if (Size > 1)
    {
        TempPtr = FirstElement;
        FirstElement = FirstElement->Next;
        delete TempPtr;
        TempPtr = nullptr;
    }
    else if (Size == 1)
    {
        delete FirstElement;
        FirstElement = nullptr;
    }
    else
    {
       std::cout <<  "Impossible to delete the first element, as the list is already empty \n";
    }  
    if(TempPtr != nullptr)
    {
        TempPtr = nullptr;
    }
    if(Size>=1)
    {
        Size--;
    }
}

void MyList::RemoveLastElement()
{
    if (Size >1)
    {
        Node * TempPtr = FirstElement;
        bool IsLast = false;
        while (!IsLast)
        {
            TempPtr = TempPtr->Next;
            if (TempPtr->Next == nullptr)
            {
                IsLast = true;
            }
        }
        delete TempPtr;
        TempPtr = nullptr;
    }
    else if (Size == 1)
    {
        RemoveFirstElement();
    }
    else
    {
        std:: cout<< "It is impossible to delete the last element as the lise is already empty \n";
    }
}




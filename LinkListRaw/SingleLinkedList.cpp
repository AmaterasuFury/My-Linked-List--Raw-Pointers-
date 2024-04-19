#include "SingleLinkedList.h"
#include <algorithm>



MyList::~MyList()
{
    Node * TempPtr = nullptr;
    /*
    if(FirstElement->Next == nullptr)
    {
        delete FirstElement;
        FirstElement = nullptr;
    }
    while (FirstElement->Next != nullptr)  // Why it goes here even on the las element?
    {
        TempPtr = FirstElement->Next;
        delete FirstElement;
        FirstElement = TempPtr;
    }
    */

    for (int i = 0; i < Size; ++i)
    {
        if (i != Size -1)
        {
            TempPtr = FirstElement->Next;
        }
        
        delete FirstElement;
        FirstElement = TempPtr;
    }
    
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
        TempPtr->Next = nullptr;
        delete TempPtr;
        TempPtr = nullptr;
    }
    else if (Size == 1)
    {
        delete FirstElement;
        FirstElement = nullptr;
    }
    else if (Size == 0)
    {
       std::cout <<  "Impossible to delete the first element, as the list is already empty \n";
        return;
    }  
        Size--;
}

void MyList::RemoveLastElement()
{
    if (Size >1)
    {
        Node * TempPtr = FirstElement;
        Node * TempPtrToPrevios = FirstElement;
        int CounterI = 0;
        while (TempPtr->Next != nullptr)
        {
            if (CounterI != 0)
            {
                TempPtrToPrevios = TempPtrToPrevios->Next;
            }
            CounterI++;
            TempPtr = TempPtr->Next;
        }
        TempPtrToPrevios->Next = nullptr;
        TempPtrToPrevios = nullptr;
        delete TempPtr;
        TempPtr = nullptr;
        Size--;
        return;
    }
    else if (Size == 1)
    {
        RemoveFirstElement();
        return;
    }
    else
    {
        std:: cout<< "It is impossible to delete the last element as the list is already empty \n";
    }
}

void MyList::RemoveByValue(int InValue)
{
    if (Size == 0)
    {
        std:: cout << "Error, the list is empty \n";
    }
    if (FirstElement->value == InValue)
    {
        RemoveFirstElement();
        return;
    }
    Node * TempPtrToPrevious = FirstElement;
    Node * TempPtrToRemove = FirstElement;
    
    for (int i = 0; i < Size; ++i)
    {
        if (i != 0)
        {
            TempPtrToPrevious = TempPtrToPrevious->Next;
        }
        TempPtrToRemove = TempPtrToRemove->Next;
        if (TempPtrToRemove->value == InValue)
        {
            if (TempPtrToRemove->Next != nullptr)
            {
                TempPtrToPrevious->Next = TempPtrToRemove->Next;
                delete TempPtrToRemove;
                TempPtrToRemove = nullptr;
                TempPtrToPrevious = nullptr;
                return;
            }
            else
            {
                delete TempPtrToRemove;
                TempPtrToRemove = nullptr;
                TempPtrToPrevious->Next = nullptr;
                TempPtrToPrevious = nullptr;
                Size--;
                return;
            }
        }
    }
}




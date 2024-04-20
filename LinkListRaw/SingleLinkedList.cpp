#include "SingleLinkedList.h"
#include <algorithm>
#include <tuple>


MyList::~MyList()
{
    Node * TempPtr = nullptr;

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
    if (Size <= InIndex)
    {
        std::cout<< "Impossible to delete the element on index: " << InIndex << ", as the size of the list is: " << Size << "\n";
        return;
    }
    if(Size == 0 || Size == 1)
    {
        RemoveFirstElement();
        return;
    }
    if (Size-1 == InIndex)
    {
        RemoveLastElement();
    }
    else
    {
        Node * TempPtrToRemove = FirstElement;
        Node * TempPtrToMoveThePtrToNext = FirstElement;
        for (int i = 0; i < InIndex; ++i)
        {
            
            if (i != 0)
            {
                TempPtrToMoveThePtrToNext = TempPtrToMoveThePtrToNext->Next;
            }
            TempPtrToRemove = TempPtrToRemove->Next;
        }
        
        TempPtrToMoveThePtrToNext->Next = TempPtrToRemove->Next;
        TempPtrToRemove->Next = nullptr;
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
/*
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
*/

void MyList::RemoveByValue(int InValue)
{
    if (Size == 0)
    {
        std:: cout << "Error, the list is empty \n";
    }
    else
    {
        Node * TempPtrToRemove = FirstElement;
        Node * TempPtrToPrevious = FirstElement;
        for (int i = 0; i < Size; ++i)
        {
            
            if (TempPtrToRemove->value == InValue)
            {
                if (i == 0)
                {
                    RemoveFirstElement();
                    TempPtrToRemove = nullptr;
                    TempPtrToPrevious = nullptr;
                    return;
                }
                if (i == Size-1)
                {
                    Size--;
                    TempPtrToPrevious->Next = nullptr;
                    TempPtrToRemove->Next = nullptr;
                    delete TempPtrToRemove;
                    return;
                }
                TempPtrToPrevious->Next = TempPtrToRemove->Next;
                TempPtrToRemove->Next = nullptr;
                delete TempPtrToRemove;
                TempPtrToRemove = nullptr;
                TempPtrToPrevious = nullptr;
                Size --;
                return;
            }
            if (i != 0)
            {
                TempPtrToPrevious = TempPtrToPrevious->Next;
            }
            TempPtrToRemove = TempPtrToRemove->Next;
        }
    }
}

int MyList::FindElementOnIndex(int InIndex)
{
    if (InIndex > Size-1)
    {
        std::cout<< "The element on index: " << InIndex << " is impossible to get as the size is: "<< Size << "\n";
        return -666;
    }
    else
    {
        const Node * TempPtr = FirstElement;
        for (int i = 0; i < Size; ++i)
        {
            if (i == InIndex)
            {
                return TempPtr->value;
            }
            TempPtr = TempPtr->Next;
        }
        TempPtr = nullptr;
        return -666;
    }
    
}








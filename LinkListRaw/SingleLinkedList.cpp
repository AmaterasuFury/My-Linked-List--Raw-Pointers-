#include "SingleLinkedList.h"



//List::List(){}
List::~List()
{
    if(FirstElement->Next == nullptr)
    {
        delete FirstElement;
        FirstElement = nullptr;
    }
    else
    {
        // make a logic to delete all of the elements; ??? or not?
    }
}



void List::Add(int InValue)
{
    bool Added = false;
    Node * TempPtr = FirstElement;

    if(Size == 0)
    {
        FirstElement = new Node;
        FirstElement->value = InValue;
        return;
    }
    else
    {
        while (TempPtr->Next != nullptr)
        {
            TempPtr = TempPtr->Next;
        }
        TempPtr->value = InValue;
    }
    if(TempPtr != nullptr)
    {
        TempPtr = nullptr;
    }
    Size++;
}

void List::RemoveOnIndex(int InIndex)
{
    Node * TempPtr = FirstElement;

    for (int i = 0; i == InIndex; ++i)
    {
        
    }
    
}

void List::RemoveFirstElement()
{
    Node * TempPtr = FirstElement;

    if(TempPtr != nullptr)
    {
        TempPtr = nullptr;
    }
    Size--;
}



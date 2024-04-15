#include "SingleLinkedList.h"



List::List()
{
    Node * Node_Ptr = new Node;
}

List::~List()
{
    if(FirstElement->Next == nullptr)
    {
        delete FirstElement;
    }
    else
    {
        // make a logic to delete all of the elements; ??? or not?
    }
    
}

void List::Add(int Value)
{
    Node NodePtr;
}

#include "SingleLinkedList.h"
#include <algorithm>
#include <tuple>
#include <fstream>

void MyList::Clear()
{
    MyList::~MyList();
}

int MyList::GetSizeOfList()
{
    return Size;
}

void MyList::SerializeToFile(const std::string InFileName, bool ClearListAfter)
{
    if (Size == 0)
    {
        std::cout << "Cannot Serialize To File, the list size is 0" << std::endl;
        return;
    }
    std::ofstream outFile(InFileName);
    if (outFile.is_open())
    {
        for (size_t i = 0; i < Size; i++)
        {
            outFile << FindOnIndex(i) << " ";
        }
    }
    else
    {
        std::cerr << "Failed to create the file \"" << InFileName << "\" for the serealization." << std::endl;
    }
    if (ClearListAfter)
    {
        Clear();
    }
}

void MyList::DeserealizeFromFile(const std::string InFileName)
{
    std::ifstream inFile(InFileName); 
    if (!inFile.is_open())
    {
        std::cerr << "Failed to open the file \"" << InFileName << "\" for deserialization." << std::endl;
        return;
    }

    Clear();

    int value = -666666666;
    while (inFile >> value)
    {
        Add(value); 
    }

    if (inFile.eof()) 
    {
        std::cout << "Deserialization completed successfully." << std::endl;
    }
    else
    {
        std::cerr << "Error occurred while reading the file during deserialization." << std::endl;
    }

    inFile.close();
}



MyList::~MyList()
{
    Node* TempPtr = nullptr;

    while (FirstElement != nullptr)
    {
        TempPtr = FirstElement->Next;
        delete FirstElement;
        FirstElement = TempPtr;
    }


    Size = 0;
    FirstElement = nullptr;
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

int MyList::FindOnIndex(int InIndex)
{
    if (InIndex > Size-1)
    {
        std::cout<< "The element on index: " << InIndex << " is impossible to get as the size is: "<< Size << "\n";
        return -666666666;
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
        return -666666666;
    }
    
}

int MyList::GetIndexByValue(int InValue)
{
    const Node * TempPtr = FirstElement;
    for (int i = 0; i < Size; ++i)
    {
        if (TempPtr->value == InValue)
        {
            TempPtr =  nullptr;
           return i; 
        }
        TempPtr = TempPtr->Next;
    }
    TempPtr = nullptr;
    std::cout<< "The entered value: " << InValue << " was not found in the list, please check it \n";
    return -666666666;
}

bool MyList::Contains(int InValue)
{
    const Node * TempPtr = FirstElement;
    for (int i = 0; i < Size; ++i)
    {
        if (TempPtr->value == InValue)
        {
            TempPtr =  nullptr;
            return true; 
        }
        TempPtr = TempPtr->Next;
    }
    TempPtr =  nullptr;
    return false;
}

void MyList::PushBack(int InValue)
{
    Node * TempPtr = FirstElement;
    for (int i = 0; i < Size; ++i)
    {
        if (i != 0)
        {
            TempPtr = TempPtr->Next;
        }
    }
    Node * NewNode = new Node;
    TempPtr->Next = NewNode;
    NewNode->value = InValue;
    TempPtr = nullptr;
    Size++;
}

void MyList::PushFront(int InValue)
{
    if (FirstElement != nullptr)
    {
        Node * TempPtr = new Node;
        TempPtr->value = InValue;
        TempPtr->Next = FirstElement;
        FirstElement = TempPtr;
        Size++;
    }
    else
    {
        FirstElement = new Node;
        FirstElement->value = InValue;
        Size++;
    }
}

void MyList::AddElementOnIndex(int InValue, int InIndex)
{
    if (InIndex == 0)
    {
        PushFront(InValue);
        return;
    }
    if (InIndex == Size)
    {
        PushBack(InValue);
        return;
    }
    if (InIndex > Size)
    {
        std:: cout<< " Cannot add the value on the index: " << InIndex << ", as the size of the list is: " << Size << "\n";
        return;
    }
    else
    {
        Node * TempPtr = FirstElement;
        Node * TempPtrToPrevious = FirstElement;

        for (int i = 0; i < InIndex; ++i)
        {
            if (i != 0)
            {
                TempPtrToPrevious = TempPtrToPrevious->Next;
            }
            TempPtr = TempPtr->Next;
        }
        Node * NodeToAdd = new Node;
        NodeToAdd->value = InValue;
        NodeToAdd->Next = TempPtr;
        TempPtrToPrevious->Next = NodeToAdd;
        TempPtr = nullptr;
        TempPtrToPrevious = nullptr;
        Size++;
    }
}








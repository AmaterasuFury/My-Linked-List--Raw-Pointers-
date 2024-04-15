#pragma once
#include <stdlib.h>

struct List
{
    int Size = 0;
    Node * FirstElement = nullptr;
    
    struct Node
    {
        int value;
        Node* Next;
    };
};

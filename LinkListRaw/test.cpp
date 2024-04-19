#include <iostream>
#include "SingleLinkedList.h"

int main()
{
  //List::List * List_Ptr = new List::List;
    MyList List;
  //List_Ptr->Add(3);
    List.Add(1);
    List.Add(2);
    List.Add(34);
    
    
    List.RemoveLastElement();
    List.RemoveFirstElement();
    List.RemoveOnIndex(0);

  
  
  // delete List_Ptr;
  return 0;
}

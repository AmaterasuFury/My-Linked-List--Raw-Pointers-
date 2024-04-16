#include <iostream>
#include "SingleLinkedList.h"

int main()
{
  //List::List * List_Ptr = new List::List;
   MyList List;
  //List_Ptr->Add(3);
  List.Add(1);
    List.Add(4);
    List.RemoveFirstElement();
    List.RemoveFirstElement();

  // delete List_Ptr;
  return 0;
}

#include <iostream>
#include "SingleLinkedList.h"

int main()
{
    
    MyList List;
    
    List.Add(1);
    List.Add(2);
    List.Add(3);
    List.AddElementOnIndex(0,4);
    std::cout<< "The element on index 0 is: " << List.FindElementOnIndex(0) << "\n"; 
    std::cout<< "The element on index 1 is: " << List.FindElementOnIndex(1) << "\n";
    std::cout<< "The element on index 2 is: " << List.FindElementOnIndex(2) << "\n";
    std::cout<< "The element on index 3 is: " << List.FindElementOnIndex(3) << "\n";
    List.AddElementOnIndex(0,3);
    std::cout<< "The element on index 3 is: " << List.FindElementOnIndex(3) << "\n";
    // List.Add(34);
    
    List.AddElementToTheEnd(56);
    std::cout<< List.FindElementOnIndex(3)<< "\n";
    List.FindElementOnIndex(4);
    std::cout<< "The size of the list is: " << List.GetSizeOfList();
    List.AddElementToTheBeginning(3336);
    std::cout<< "The element on index: 0 is " << List.FindElementOnIndex(0) << "\n";
    std::cout<< "The size of the list is: " << List.GetSizeOfList();
    List.ClearTheList();
    //List.RemoveByValue(3);
    //List.RemoveByValue(0);
    bool kol = false;
    std::cout<< List.FindElementOnIndex(0)<< "\n";
    std::cout<< List.FindElementOnIndex(1)<< "\n";
    std::cout<< List.FindElementByValue(1)<< "\n";
    std::cout << List.CheckIfValueExists(5)<< "\n";
    std::cout << List.CheckIfValueExists(1)<< "\n";
    std::cout << List.CheckIfValueExists(3)<< "\n";
    
    std::cout<< List.FindElementOnIndex(3)<< "\n";
   
  return 0;
}

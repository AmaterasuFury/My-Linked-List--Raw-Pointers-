#include <iostream>
#include "SingleLinkedList.h"

int main()
{
    
    MyList List;

    List.Add(0123);
    List.Add(11);
    List.Add(22);
    List.Add(333);
   //List.AddElementOnIndex(0,4);
   //std::cout<< "The element on index 0 is: " << List.FindOnIndex(0) << "\n"; 
   //std::cout<< "The element on index 1 is: " << List.FindOnIndex(1) << "\n";
   //std::cout<< "The element on index 2 is: " << List.FindOnIndex(2) << "\n";
   //std::cout<< "The element on index 3 is: " << List.FindOnIndex(3) << "\n";
   //List.AddElementOnIndex(0,3);
   //std::cout<< "The element on index 3 is: " << List.FindOnIndex(3) << "\n";
   //// List.Add(34);
   //
   //List.PushBack(56);
   //std::cout<< List.FindOnIndex(3)<< "\n";
   //List.FindOnIndex(4);
   //std::cout<< "The size of the list is: " << List.GetSizeOfList() << "\n";;
   //List.PushFront(3336);
   //std::cout<< "The element on index: 0 is " << List.FindOnIndex(0) << "\n";
   //std::cout<< "The size of the list is: " << List.GetSizeOfList() << "\n";;
   //List.Clear();
   ////List.RemoveByValue(3);
   ////List.RemoveByValue(0);
   //bool kol = false;
   //std::cout<< List.FindOnIndex(0)<< "\n";
   //std::cout<< List.FindOnIndex(1)<< "\n";
   //std::cout<< List.GetIndexByValue(1)<< "\n";
   //std::cout << List.Contains(5)<< "\n";
   //std::cout << List.Contains(1)<< "\n";
   //std::cout << List.Contains(3)<< "\n";
   //
   //std::cout<< List.FindOnIndex(3)<< "\n";
    const std::string SerializedFileName = "SerizalizedTest.txt";
    List.SerializeToFile(SerializedFileName, true);
    List.DeserealizeFromFile(SerializedFileName);

    std::cout << "The element on index 0 is: " << List.FindOnIndex(0) << "\n";
    std::cout << "The element on index 1 is: " << List.FindOnIndex(1) << "\n";
    std::cout << "The element on index 2 is: " << List.FindOnIndex(2) << "\n";
    std::cout << "The element on index 3 is: " << List.FindOnIndex(3) << "\n";
   
  return 0;
}

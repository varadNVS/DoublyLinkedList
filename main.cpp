#include<iostream>
#include"doubLinkList.h"

int main()
{
    doubLinkList myList;
    std::cout << "is the list empty now: ? " << myList.isEmpty() << std::endl;
    std::cout << "--------------------------" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        myList.addDataBack(i);
        myList.addDataFront(i + 10);
    }
    std::cout << "is the list empty now: ? " << myList.isEmpty() << std::endl;
    std::cout << "------print------" << std::endl;
    myList.RemovalForPos(7);
    myList.RemovalForData(18);
    myList.Display();
    std::cout << myList.SearchData(14) << std::endl;
    std::cout << "data for 17 :" << myList.SearchPosition(17) << std::endl;
    
    
    myList.DisplayHeadAndTail();
    return 0;
}

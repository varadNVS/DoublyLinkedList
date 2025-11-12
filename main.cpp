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
    myList.RemovalForPos(1);
    myList.RemovalForData(13);
    myList.Display();
    std::cout << "data position for 14: " << myList.SearchData(14) << std::endl;
    std::cout << "data on Pos 17 :" << myList.SearchPosition(17) << std::endl;


    
    std::cout << "Clear Check:---------------------------- " << std::endl;
    myList.ClearAll();
    myList.Display();
    std::cout << "code Completed without Crash" << std::endl;
    return 0;
}

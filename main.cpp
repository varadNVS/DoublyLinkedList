#include<iostream>
#include"doubLinkList.h"
using namespace std;

int main()
{
    doubLinkList myList;
    cout << "is the list empty now: ? " << myList.isEmpty() << endl;
    cout << "--------------------------" << endl;

    for (int i = 0; i < 10; i++)
    {
        myList.addData(i);
        
    }

    for (int i = 0; i < 10; i++)
    {
        myList.addDataFront(i * 10);
    }
    

    cout << "is the list empty now: ? " << myList.isEmpty() << endl;
    cout << "------print------" << endl;
    myList.Display();

    cout << "position of data 20: " << myList.SearchData(20) << endl;

    return 0;
}
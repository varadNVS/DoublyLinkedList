// this is the code to create double linked list.
// author: varad shirodkar
// in this we create a node structure for the nodes and then dll(doubly linked list). for integration of those nodes.

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>

class node{
    private:
        int data;
        node *next;
        node *prev;
    public:
        node(int data, node *next, node *prev){
            this->data = data;
            this->next = next;
            this->prev = prev;
        }

        ~node(){
            delete next;
            delete prev;
            next = nullptr;
            prev = nullptr;
        }
        

        int getData(){
            return data;
        }
        void setData(int data){
            this->data = data;
        }


        node* getNext(){
            return next;
        }

        node* setNext(node* next){
            this->next = next;
            return 0;
        }
        

        node* getPrevious(){
            return prev;
        }
        node* setPrevious(node* prev){
            this->prev = prev;
            return 0;
        }
        node* DeleteNode(node* DeletableNodeAddress){
            DeletableNodeAddress->next = nullptr;
            DeletableNodeAddress->prev = nullptr;
            return 0;
        }

};


class doubLinkList
{
private:
    int dllDataNumber;
    node* dllHead;
    node* dllTail;
public:

    doubLinkList(){
        dllDataNumber = 0;
        dllHead = nullptr;
        dllTail = nullptr;
    }


    void addData(int dataAdded,bool direction){
        if (isEmpty())
        {
            
            node *newNode = new node(dataAdded,dllTail,dllHead);
            dllHead = newNode;
            dllTail = newNode;
            dllDataNumber++;
            std::cout << "dlldataNumber: " << dllDataNumber << std::endl;
            
        }
        else if (!isEmpty())
        {
            if (!direction) //Front
            {
                node *newNode = new node(dataAdded,dllHead,nullptr);
                dllHead->setPrevious(newNode);
                dllHead = newNode;
            } else { //back
                node *newNode = new node(dataAdded,nullptr,dllTail);
                dllTail->setNext(newNode);
                dllTail = newNode;
                
            }
            dllDataNumber++;
            std::cout << "dlldataNumber: " << dllDataNumber << std::endl;
        } 
    }
    void addDataBack(int dataAdded){
        addData(dataAdded,true);
    }
    void addDataFront(int dataAdded){
        addData(dataAdded,false);
    }


    void Display(){
        if (isEmpty())
        {
            std::cerr << "list is Empty" << std::endl;
        }
        else if (!isEmpty())
        {
            int values = 1;
            node *printValue = dllHead;
            while (values <= dllDataNumber)
            {
                std::cout << printValue->getData() << std::endl;
                printValue = printValue->getNext();
                values++;
            }
            printValue = nullptr;
        }
    }

    void DisplayHeadAndTail(){ // for testing if display doesnt work.
        std::cout << dllHead->getData()
        << "*" << SearchData(dllHead->getData()) << " --"<< dllDataNumber <<"-- " << dllTail->getData() << "*" << SearchData(dllTail->getData()) << std::endl;
    }


    int SearchData(int data){
        return SearchDataHidden(data,-1,false);
    }
    int SearchPosition(int position){
        if(position < 1 || position > dllDataNumber){
            std::cout << "position out of bounds" << std::endl;
            return -1;
        }
        return SearchDataHidden(-1,position,true);
    }
    int SearchDataHidden(int dataSearch,int positionSearch,bool DataOrPos){
        int result;
        if (isEmpty())
        {
            std::cerr << "list is Empty" << std::endl;
            return -1;
        }
            int position = 1;
            node *printValue = dllHead;
            while (position <= dllDataNumber)
            {
                if (DataOrPos)
                {
                    if(positionSearch == position){
                    result = printValue->getData();
                    break;
                    }
                    else if(position == dllDataNumber)
                    {
                        std::cerr << "data does not exist!!" << std::endl;
                        return -1;
                    }
                }
                else{
                    if(printValue->getData() == dataSearch){
                    result = position;
                    break;
                    }
                    else if(position == dllDataNumber)
                    {
                        std::cerr << "data does not exist!!" << std::endl;
                        return -1;
                    }
                }
                printValue = printValue->getNext();
                position++;
            }
            printValue = nullptr;
        return result;
    }


void RemovalForPos(int position){
    RemovalForBoth(position,-1);
}
void RemovalForData(int data){
    RemovalForBoth(-1,data);
}
void ClearAll(){
    while(!isEmpty())
    {
        RemovalForPos(1);
    }
}
void RemovalForBoth(int positionToDelete,int dataSearch){
        int position = 1;
    if(isEmpty()){
        std::cerr << "list is Empty" << std::endl;
        return;
    }
    else if(positionToDelete > dllDataNumber || positionToDelete == 0){
        std::cerr << "element out of scope" << std::endl;
        return;
    }
    if (dllDataNumber == 1)
    {
        position = 0;
    }
    
node *printValue = dllHead;  
while (position < dllDataNumber){
        if((position == positionToDelete && (positionToDelete != 1 && positionToDelete != dllDataNumber)) || (printValue->getData() == dataSearch && (printValue != dllHead && printValue != dllTail))){
            node *prevNode = printValue->getPrevious();
            node *nextNode = printValue->getNext();
            
            prevNode->setNext(nextNode);
            nextNode->setPrevious(prevNode);

            printValue->DeleteNode(printValue);
            delete printValue; 
            dllDataNumber--;
            break;
        }
        else if((position == positionToDelete && (positionToDelete == 1 && dllDataNumber != 1 )) || (printValue->getData() == dataSearch && printValue == dllHead))
        {
            node *nextNode = printValue->getNext();
            nextNode->setPrevious(nullptr);
            dllHead = nextNode;

            printValue->DeleteNode(printValue);
            delete printValue; 
            dllDataNumber--;
            break;   
        }
        else if((position == positionToDelete && (positionToDelete == dllDataNumber && dllDataNumber != 1)) || ((printValue->getData() == dataSearch && printValue == dllTail))){
            node *prevNode = printValue->getPrevious();
            prevNode->setNext(nullptr);
            dllTail = prevNode;
            printValue->DeleteNode(printValue);
            dllDataNumber--;
            break; 
        }
        else if (positionToDelete == dllDataNumber && dllDataNumber == 1)
        {
            printValue->DeleteNode(printValue);
            dllDataNumber--;
            break;
        }
        
    printValue = printValue->getNext();
    position++;
    }
}


    bool isEmpty(){
        return dllDataNumber == 0;
    }

};

#endif


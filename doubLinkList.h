// this is the code to create double linked list.
// author: varad shirodkar
// in this we create a node structure for the nodes and then dll(doubly linked list). for integration of those nodes.

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>

//---------------Class NODE-----------------------------
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
        
        //____________data ____________________
        int getData(){
            return data;
        }
        void setData(int data){
            this->data = data;
        }
        //____________next__________________
        node* getNext(){
            return next;
        }

        node* setNext(node* next){
            this->next = next;
            return 0;
        }
        //____________previous____________________
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


//-------------class for doubly linked list-------------------------
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
//______________Adding the data__________________

    void addData(int dataAdded,bool direction){
        if (isEmpty())
        {
            node *newNode = new node(dataAdded,dllTail,dllHead);
            dllHead = newNode;
            dllTail = newNode;
            dllDataNumber++;
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
        } 
    }

    void addDataBack(int dataAdded){
        addData(dataAdded,true);
    }

    void addDataFront(int dataAdded){
        addData(dataAdded,false);
    }
//---------Data Display------------------------------------
    void Display(){
        if (isEmpty())
        {
            std::cerr << "list is Empty" << std::endl;
        }
        else if (!isEmpty())
        {
            int values = 0;
            node *printValue = dllHead;
            while (values < dllDataNumber)
            {
                std::cout << printValue->getData() << std::endl;
                printValue = printValue->getNext();
                values++;
            }
            printValue = nullptr;
        }
    }

    void DisplayHeadAndTail(){ // for testing if display doesnt work.
        std::cout << dllHead->getData() << " ---- " << dllTail->getData() << std::endl;
    }
//-----------------Search Functions-----------------------------------
    int SearchData(int dataSearch){
        int result;
        if (isEmpty())
        {
            std::cerr << "list is Empty" << std::endl;
            return -1;
        }
            int position = 0;
            node *printValue = dllHead;
            while (position < dllDataNumber)
            {
                if(printValue->getData() == dataSearch){
                    result = position;
                    break;
                }
                else if(position == dllDataNumber - 1)
                {
                    return -1;
                }
                printValue = printValue->getNext();
                position++;
            }
            printValue = nullptr;
        return result;
    }
//-----------------Remove--------------------------------------

// void RemoveByPosition(int positionToDelete){
//     int position = 0;
//     if(isEmpty()){
//         std::cerr << "list is Empty" << std::endl;
//         return;
//     }
//     else if(positionToDelete >= dllDataNumber){
//         std::cerr << "element out of scope" << std::endl;
//         return;
//     }
// node *printValue = dllHead;  
// while (position < dllDataNumber){
//         std::cout << printValue->getData() << std::endl;
//         if(position == positionToDelete && (positionToDelete != 0 && positionToDelete > dllDataNumber - 1)){
//             node *prevNode = printValue->getPrevious();
//             node *nextNode = printValue->getNext();
            
//             prevNode->setNext(nextNode);
//             nextNode->setPrevious(prevNode);

//             printValue->DeleteNode(printValue);
//             delete printValue; 
//             dllDataNumber--;
//             break;
//         }
//         else if(position == positionToDelete && positionToDelete == 0)
//         {
//             node *nextNode = printValue->getNext();
//             nextNode->setPrevious(nullptr);
//             dllHead = nextNode;

//             printValue->DeleteNode(printValue);
//             delete printValue; 
//             dllDataNumber--;
//             break;   
//         }
//         else if(position == positionToDelete && positionToDelete == dllDataNumber - 1){
//             node *prevNode = printValue->getPrevious();
//             prevNode->setNext(nullptr);
//             dllTail = prevNode;
//             printValue->DeleteNode(printValue);
//             dllDataNumber--;
//             break; 
//         }
//     printValue = printValue->getNext();
//     position++;
//     }
// }


// void RemovalNode(int dataSearch){
//         if (isEmpty())
//         {
//             std::cerr << "list is Empty" << std::endl;
//         }
//         else if (!isEmpty())
//         {
//             int position = 0;
//             node *printValue = dllHead;
//             while (position < dllDataNumber)
//             {
//                 if(printValue->getData() == dataSearch && (printValue != dllHead && printValue != dllTail)){
//                     node *prevNode = printValue->getPrevious();
//                     node *nextNode = printValue->getNext();
                    
//                     prevNode->setNext(nextNode);
//                     nextNode->setPrevious(prevNode);

//                     printValue->DeleteNode(printValue);
//                     delete printValue; 
//                     dllDataNumber--;
//                     break;
//                 }
//                 else if(printValue->getData() == dataSearch && printValue == dllHead)
//                 {
//                     node *nextNode = printValue->getNext();
//                     nextNode->setPrevious(nullptr);
//                     dllHead = nextNode;

//                     printValue->DeleteNode(printValue);
//                     delete printValue; 
//                     dllDataNumber--;
//                     break;   
//                 }
//                 else if(printValue->getData() == dataSearch && printValue == dllTail){
//                     node *prevNode = printValue->getPrevious();
//                     prevNode->setNext(nullptr);
//                     dllTail = prevNode;

//                     printValue->DeleteNode(printValue);
//                     delete printValue; 
//                     dllDataNumber--;
//                     break; 
//                 }
//                 else if(position == dllDataNumber - 1)
//                 {
//                     std::cout << "data not available" << std::endl;
//                 }
//                 printValue = printValue->getNext();
//                 position++;
//             }
//             printValue = nullptr;
//         }
// }
void RemovalForPosTrial(int position){
    RemovalForBoth(position,-1);
}
void RemovalForDataTrial(int data){
    RemovalForBoth(-1,data);
}
void RemovalForBoth(int positionToDelete,int dataSearch){
        int position = 0;
    if(isEmpty()){
        std::cerr << "list is Empty" << std::endl;
        return;
    }
    else if(positionToDelete >= dllDataNumber){
        std::cerr << "element out of scope" << std::endl;
        return;
    }
node *printValue = dllHead;  
while (position < dllDataNumber){
        if((position == positionToDelete && (positionToDelete != 0 && positionToDelete != dllDataNumber - 1)) || (printValue->getData() == dataSearch && (printValue != dllHead && printValue != dllTail))){
            node *prevNode = printValue->getPrevious();
            node *nextNode = printValue->getNext();
            
            prevNode->setNext(nextNode);
            nextNode->setPrevious(prevNode);

            printValue->DeleteNode(printValue);
            delete printValue; 
            dllDataNumber--;
            break;
        }
        else if((position == positionToDelete && positionToDelete == 0) || (printValue->getData() == dataSearch && printValue == dllHead))
        {
            node *nextNode = printValue->getNext();
            nextNode->setPrevious(nullptr);
            dllHead = nextNode;

            printValue->DeleteNode(printValue);
            delete printValue; 
            dllDataNumber--;
            break;   
        }
        else if((position == positionToDelete && positionToDelete == dllDataNumber - 1) || ((printValue->getData() == dataSearch && printValue == dllTail))){
            node *prevNode = printValue->getPrevious();
            prevNode->setNext(nullptr);
            dllTail = prevNode;
            printValue->DeleteNode(printValue);
            dllDataNumber--;
            break; 
        }
    printValue = printValue->getNext();
    position++;
    }

}

//--------------------------------------------------------------------
    bool isEmpty(){
        return dllDataNumber == 0;
    }

};

#endif


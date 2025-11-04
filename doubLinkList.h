// this is the code to create double linked list.
// author: varad shirodkar
// in this we create a node structure for the nodes and then dll(doubly linked list). for integration of those nodes.

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>

using namespace std;

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
            next = nullptr;
            prev = nullptr;
            delete next;
            delete prev;
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
            return next;
        }

        node* setPrevious(node* prev){
            this->prev = prev;
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
    ~doubLinkList(){
        dllHead = nullptr;
        delete dllHead;
        dllTail = nullptr;
        delete dllTail;
    }
//______________Adding the data__________________
    //adds data at the back of the node
    void addData(int dataAdded){
        if (isEmpty())
        {
            node *newNode = new node(dataAdded,dllTail,dllHead);
            dllHead = newNode;
            dllTail = newNode;

            // --|next = null| data |prev = null| && tail & head (data node)

            dllDataNumber++;
            newNode = nullptr;
            delete newNode;
        }
        else if (!isEmpty())
        {
            node *newNode = new node(dataAdded,nullptr,dllTail);
            dllTail->setNext(newNode);
            dllTail = newNode;
            dllDataNumber++;
            newNode = nullptr;
            delete newNode;
        } 
    }

    // adds the data at front of the node.
    void addDataFront(int dataAdded){
        if (isEmpty())
        {
            node *newNode = new node(dataAdded,dllTail,dllHead);
            dllHead = newNode;
            dllTail = newNode;

            // --|next = null| data |prev = null| && tail & head (data node)

            dllDataNumber++;
            newNode = nullptr;
            delete newNode;
        }
        else if (!isEmpty())
        {
            node *newNode = new node(dataAdded,dllHead,nullptr);
            dllHead->setPrevious(newNode);
            dllTail = dllHead;
            dllHead = newNode;

            //3) dllhead = newNode | 2) dlltail = dllhead | 1) dllheads prev -> newNode. follow numbers to follow process

            dllDataNumber++;
            newNode = nullptr;
            delete newNode;
        } 
    }
//---------Data Display------------------------------------
    void Display(){
        if (isEmpty())
        {
            cout << "list is Empty" << endl;
        }
        else if (!isEmpty())
        {
            int values = 0;
            node *printValue = dllHead;
            while (values < dllDataNumber)
            {
                cout << printValue->getData() << endl;
                printValue = printValue->getNext();
                values++;
            }
            printValue = nullptr;
            delete printValue;
        }
    }

    void DisplayHeadAndTail(){ // for testing if display doesnt work.
        cout << dllHead->getData() << " ---- " << dllTail->getData() << endl;
    }
//-----------------Search Functions-----------------------------------
    int SearchData(int dataSearch){
        int result;
        if (isEmpty())
        {
            cout << "list is Empty" << endl;
        }
        else if (!isEmpty())
        {
            int position = 0;
            node *printValue = dllHead;
            while (position < dllDataNumber)
            {
                if(printValue->getData() == dataSearch){
                    result = position;
                    break;
                }
                printValue = printValue->getNext();
                position++;
            }
            printValue = nullptr;
            delete printValue;
        }
        return result;
    }
//--------------------------------------------------------------------
    bool isEmpty(){
        return dllDataNumber == 0;
    }

};

#endif


#ifndef NODE_STRUCT_H
#define NODE_STRUCT_H

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

#endif

#ifndef _linkedSTACK_H_
#define _linkedSTACK_H_

#include <iostream>
#include "StackInterface.h"

using namespace std;


template <class ItemType>
class linkedStack{
    public:
        linkedStack():top(0) {} //prototype
        void push (const ItemType& object); // adds element top of the stack
        ItemType pop(); // returns top element of stack and remove it.
        const ItemType& topElement(); //returs top element of stack without remove it.
        bool isEmpty(); //returns true is stack is empty.
        int numSpaces(string line); //returns spaces in a line.

    private:
        struct StackNode {              
            ItemType data;                
            StackNode *next;
            StackNode(const ItemType& newData, StackNode *nextNode):data(newData),next(nextNode){}
        }; //struct Node
        linkedStack(const linkedStack& lhs) {}
        StackNode *top; //stack top pointer
};


template <class ItemType>
void linkedStack<ItemType>::push(const ItemType& obj) {
    top = new StackNode(obj, top);
}

template <class ItemType>
ItemType linkedStack<ItemType>::pop() {
    if ( !isEmpty() ) {
        StackNode *topNode = top;
        top = top->next;
        ItemType data = topNode->data;
        delete topNode;
        return data;
 }
}

template <class ItemType>
const ItemType& linkedStack<ItemType>::topElement() {
    if ( !isEmpty() ) {
        return top->data;
    }
	else
	{
    	cout << "";
	}
}

template <class ItemType>
bool linkedStack<ItemType>::isEmpty() {
    if (top == 0) {
        return true;
    }
    else {
        return false;
    }
}

int numSpaces(string line){
	int i=0;
	int num=0;
	while(line[i]){
			if(isspace(line[i])){
				num++;
			}
			i++;
		}
		
	return num;
}

#endif 

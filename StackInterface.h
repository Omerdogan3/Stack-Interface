// file: StackInterface.h
#ifndef STACK_INTERFACE_
#define STACK_INTERFACE_

template<class ItemType>
class StackInterface
{
public:
   // input: none
   // output: return true if the stack is empty; else false 
   virtual bool isEmpty() const = 0;
   
   // input: item to be added to stack
   // output: returns true if item is added; else false
   virtual bool push(const ItemType& newEntry) = 0;
   
   // input: none
   // output: returns true if top of stack has been removed; 
   // else false
   virtual bool pop() = 0;
   
   // precondition: stack is not empty
   // input: none
   // output: returns a copy of the top item on the stack
   virtual ItemType peek() const = 0;
   
   // destructor
   virtual ~StackInterface() { }
};
#endif
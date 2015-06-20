
/*  stack_3358_LL.h
  CS 3358 Spring 2011
  
  a very simple linked list Stack ADT
  
*/

#ifndef STACK_3358_H
#define STACK_3358_H
#include "list_3358_pointers.h"
#include <cassert>

using namespace std;	


int MAX_SIZE = 25;
	    	struct coor
{
	int row;
	int col;
		
}; 
    



		
template<class ItemType>    ///  typedef and templates go together(meaning, templete is an empty datatype that can receive
							/// any data type. for example typdef list3358<ItemType> *Node; Node head is creating an instance of the object. Node is like 
							//The middle man, who does the job. (he is just a pointer, and ItemType is the type )
							//  int temp is same as list3358<ItemType> temp; 
							//*** WHen using a class as a datatype , we need to define the type.
class Stack_3358 {
 public:
            
  //  Stack_3358();
    
    //Copy constructor
  //  Stack_3358(const Stack_3358 & src);
    
    void makeEmpty();
/****************************  
makeEmpty
  
Function: Removes all the items from the stack. 
Preconditions: Stack has been initialized 
Postconditions: All the items have been removed
*****************************/        
    //void makeEmpty();
    
/****************************  
isEmpty
  
Function: Checks to see if there are any items on the stack. 
Preconditions: Stack has been initialized
Postconditions: Returns true if there are no items on the stack, else false.
*****************************/        
 //   bool isEmpty() const;
    
/****************************  
isFull
  
Function: Determines if you have any more room to add items to the stack
Preconditions: Stack has been initialized
Postconditions: Returns true if there is no more room to add items, else false
*****************************/        
 //   bool isFull() const;

/****************************  
push
  
Function: Adds newItem to the top of the stack. 
Preconditions: Stack has been initialized and is not full.
Postconditions: newItem is at the top of the stack.
*****************************/    
 	void push(const ItemType &);
 	
/****************************  
pop
  
Function: Removes topItem from stack and returns it.
Preconditions: Stack has been initialized and is not empty.
Postconditions: Top element has been removed from stack and item is a copy of the removed element. 
*****************************/  	
ItemType pop();

   bool isEmpty();
    
    
 private:

  // typedef List_3358<ItemType> *Node; // typedef - is flexible to recieve any data types from the driver.
	// there fore there's the <ItemType>
  // Node head;  		//

    List_3358<ItemType> list;
	  
}; 


template<class ItemType>
bool Stack_3358 <ItemType>::isEmpty()
{ 
	if(list.isEmpty())
	{
		//cout << "IS empty is returning true" << endl; 
			return true;
	}

	else
	{
		//cout << "Is empty is returning false " << endl; 
	 return false;
		
	}
	
}

/*******************************
/ Function implementations
********************************/
/*
template<class ItemType>
Stack_3358<ItemType>::Stack_3358 ()
{
   head = NULL;  
}

template<class ItemType>
Stack_3358<ItemType>::Stack_3358(const Stack_3358 & src)
{
         if (src.head == NULL)
         {
            head = NULL;
         }
         else
         {
            Node temp;
            Node prev = NULL;

            for (Node p = src.head; p != NULL; p=p->next)
            {
               temp = new Node;
               temp->value = p->value;
               temp->next = NULL;
         
               if (prev == NULL)
                  prev = temp;
               else
               {
                  prev->next = temp;
                  prev = temp;
               }
 
               if (p == src.head)
                  head = temp;
            }
         }
}
*/

template<class ItemType>
void Stack_3358 <ItemType>::makeEmpty()
{
while(!list.isEmpty())
{
		list.remove();
 
		}        
		
		
		// Node p = head;

         //while (head != NULL)
         //{
           // head = head->next;
          //  delete p;
          //  p = head;
        // }
   
}
/*
template<class ItemType>
bool Stack_3358 <ItemType>::isEmpty() const
{  
   return head == NULL;   
}

template<class ItemType>
bool Stack_3358 <ItemType>::isFull() const
{
   return false; //temporary (could use the try/catch memory allocation)    
}
*/

template<class ItemType>
void Stack_3358 <ItemType>::push(const ItemType& newItem)
{
   assert(!list.isFull());
 
 list.reset();
 list.insert(newItem);
 
//	Node p = new List_3358<ItemType>;
 //  Node *p = new Node;   ---- do not need
  // p->value = newItem;
  // p->next = head;
  // head = p;

}


template<class ItemType>
ItemType Stack_3358 <ItemType>::pop()
{
   assert(!list.isEmpty());
    list.reset();
    ItemType temp = list.getCurrent();
   list.remove();

  // ItemType temp = head->value;

   //Node p = head;
   //head = head->next;
  // delete p;

   return temp;
   
}

#endif



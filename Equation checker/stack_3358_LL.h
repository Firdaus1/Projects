
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
  
/*push
  
Function: Adds newItem to the top of the stack. 
Preconditions: Stack has been initialized and is not full.
Postconditions: newItem is at the top of the stack.
*****************************/    
 	void push(const ItemType &);
 	
 	
ItemType pop();

   bool isEmpty();
    
    
 private:
 
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


template<class ItemType>
void Stack_3358 <ItemType>::makeEmpty()
{
while(!list.isEmpty())
{
		list.remove();
 
		}
	}        
		
		

template<class ItemType>

void Stack_3358 <ItemType>::push(const ItemType& newItem)
{
   assert(!list.isFull());
 
 list.reset();
 list.insert(newItem);
  

}


template<class ItemType>
ItemType Stack_3358 <ItemType>::pop()
{
   assert(!list.isEmpty());
    list.reset();
    ItemType temp = list.getCurrent();
   list.remove();

    return temp;
   
}

#endif



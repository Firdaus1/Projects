
#ifndef LIST_3358_H
#define LIST_3358_H

using namespace std;

 



 template<class ItemType> 
 class List_3358 
 {
   public:
   	 typedef ItemType value_type;
    
//Constructor/Destructor
      //Preconditions: None.
      //Postconditions: Creates an empty list capable of holding Item type data items. 
      //Current position is at BOL. 
      //The List has a capacity of at most MAX_ITEMS items.
      
      List_3358 ( );

      //Preconditions: None
      //Postconditions: Creates a new List which is a deep copy of the passed src List. 
      //Implement the copy constructor last, after the rest of the implementation has been debugged.
      
      List_3358 ( const List_3358 & src );

      //Preconditions: None.
      //Postconditions: Destroys the list, cleaning up all resources associated with the object.
      
      ~List_3358 ( );

      
      //************************************
      //Mutator(s)
      
      //Preconditions: List is not full (i.e. the number of items currently in the list is less than its capacity).
      //Postconditions: The item has been inserted by copying into the list. 
      //Location of the insert occurs at the current position (the item previously at the current position
      // is moved to the next position in the list). 
      //After an insert, the current position remains the same.
      //If the current position is at the end of the list, the current position will remain 
      //at the end of the list after the insert.
      
      void insert ( const value_type & item );


      //Preconditions: Current position is not EOL and list is not empty.
      //Postconditions: The item at the current position is removed from the list. 
      //The current position becomes that of the item's successor, 
      //or EOL if the removed item were the last in the list.  
      
      void remove ( );


      //Preconditions: None.
      //Postconditions: Resets the current position to the beginning of the list BOL. 
      //If the list is empty, then the position is set to EOL. 
      
      void reset ( );


      //Preconditions: None.
      //Postconditions: Advances the current position to the next item in the list. 
      //Advancing from EOL leaves the current position at EOL. 
      //If the position following the advance is not EOL, the result of the function is TRUE, 
      //and if the position following the advance is EOL, the result of the function is FALSE. 
      
      bool advance ( );

      

      //*******************
      // Accessor(s)
      
      //Preconditions: None.
      //Postconditions: Return value is true if the list contains no items, and false otherwise.
      
      bool isEmpty ( ) const;


      //Preconditions: None.
      //Postconditions: Return value is true if the current position is logically at EOL, 
      //and false otherwise.
      
      bool atEOL ( ) const;


      //Preconditions: None.
      //Postconditions: Return value is true if the list contains its capacity of items, 
      //and false otherwise.
      
      bool isFull ( ) const;



      //Preconditions: Current position is not EOL or at BOL.
      //Postconditions: Return value is a copy of the item at the current position. 
      //The list is unaffected. 
       
       value_type getCurrent ( ) const;
       
       
       
       
         private:
      struct Node {
         value_type value;
         Node* next;
      };
      
      Node* head;
      Node* tail;
      Node* cursor;
      
   //	ItemType value;
   //	List_3358 *next;
//
//	List_3358()
//	{
//		value = 0;
//		next = NULL;
//	}
};
template<class ItemType>
 List_3358<ItemType>::List_3358 ( ) {
     
         head = NULL;
         tail = NULL;
         cursor = NULL;      
      }
      
      template<class ItemType>
      List_3358<ItemType>::List_3358 ( const List_3358 & src ) {

         if (src.head == NULL)
         {
            head = NULL;
            tail = NULL;
            cursor = NULL;
         }
         else
         {
            Node *temp;
            Node *prev = NULL;

            for (Node *p = src.head; p != NULL; p=p->next)
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
               if (p == src.cursor)
                  cursor = temp;
               if (p == src.tail)
                  tail = temp;
            }
         }
            
      }
      
      template<class ItemType>
      List_3358<ItemType>::~List_3358 ( ) {

         Node *p = head;

         while (head != NULL)
         {
            head = head->next;
            delete p;
            p = head;
         }
 
      }

      //************************************
      //Mutator(s)
      template<class ItemType>
      void List_3358<ItemType>::insert (const value_type & item) {
 
         if (!isFull())
         {
            Node *temp = new Node;
            temp->value = item;
            temp->next = NULL;

            if (isEmpty())
            {
               head = temp;
               tail = temp;
            }
            else if (atEOL())
            {
               tail->next = temp;
               tail = temp;
            }
            else
            {
               if (cursor == head) //inserting at head
               {
                  temp->next = head;
                  head = temp;
               }
               else
               {
                  Node *p = head;
                  while (p->next != cursor)
                     p = p->next;

                  p->next = temp;
                  temp->next = cursor;
               }
            }
         }
      }        
            
         
      template<class ItemType>
      void List_3358<ItemType>::remove() {
      
         Node *p = head;

         if (!atEOL() && !isEmpty())
         {
            if (cursor == head)
            {
               head = head->next;
               delete p;
               cursor = head;
 
               if (head == NULL)
                  tail = NULL;  //deleted only item in list
            }
            else
            {
               while (p->next != cursor)
                  p = p->next;

               p->next = cursor->next;

               if (cursor == tail)
               {
                  delete cursor;
                  tail = p;
                  cursor = NULL;
               }
               else
               {
                  delete cursor;
                  cursor = p->next;
               }
            }   
         }      
            
               
   
      }

      template<class ItemType>
      void List_3358<ItemType>::reset ( ) {
         
         cursor = head;
  
      }


      template<class ItemType>
      bool List_3358<ItemType>::advance ( ) {

         if (!atEOL())
            cursor = cursor->next;

         return (!atEOL()); 
      }

      

      //*******************
      // Accessor(s)
      
	  template<class ItemType>
      bool List_3358<ItemType>::isEmpty ( ) const {
      
         return (head == NULL);
         
      }


      template<class ItemType>
      bool List_3358<ItemType>::atEOL ( ) const {
      
         return (cursor==NULL); 
        
      }
      
      template<class ItemType>
      bool List_3358<ItemType>::isFull ( ) const {
      	return false; 
         
      }


       template<class ItemType>
     ItemType List_3358<ItemType>:: List_3358::getCurrent ( ) const {

         if (!atEOL())
            return cursor->value;   
      
      }


#endif
         
         
   

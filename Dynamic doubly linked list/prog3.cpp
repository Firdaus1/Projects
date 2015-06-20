#include "list_3358_pointers.h"
#include <iostream>

using namespace std;
using namespace cs3358_LL;

 List_3358::List_3358 ( )
{
    head = NULL;
    tail = NULL;
    cursor = NULL;
}
      //Preconditions: None
      //Postconditions: Creates a new List which is a deep copy of the passed src List.
      //Implement the copy constructor last, after the rest of the implementation has been debugged.

     List_3358::List_3358 ( const List_3358 & src )
     {


        if(src.head == NULL)
        {
             head = NULL;
             tail = NULL;
             cursor = NULL;
        }
        else
        {
         Node *temp;
         Node *cursor;


            for ( Node *p =src.head ; p != NULL; p = p->next)
            {


            temp = new Node;
            temp->value = p->value;
        if (p->previous == NULL)
        {
        	temp->previous = NULL;
        	head = temp;
        	cursor = temp;
        }
        else
        {
        	temp->previous = cursor;
        	cursor->next =temp;
        	cursor=temp;
        }





     }}}
      //Preconditions: None.
      //Postconditions: Destroys the list, cleaning up all resources associated with the object.

      List_3358::~List_3358 ( )
{
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

      //Preconditions: List is not full (i.e. the number of items currently in the list is less than its capacity).
      //Postconditions: The item has been inserted by copying into the list.
      //Location of the insert occurs at the current position (the item previously at the current position
      // is moved to the next position in the list).
      //After an insert, the current position remains the same.
      //If the current position is at the end of the list, the current position will remain
      //at the end of the list after the insert.

      void List_3358::insert ( const value_type & item )
      {
          if (!isFull())
          {
            Node *temp = new Node;
            temp->value = item;
            temp->next = NULL;
            temp->previous = NULL;

                if(isEmpty())
                {

                    head = temp;
                    tail = temp;
                }
                else if(atEOL())
                {
                	tail->next = temp;
                	temp->previous =tail;
                	tail= temp;

                }


                else {if (cursor == head)
                {
					temp->next = cursor;
                	cursor->previous = temp;
					head = temp;

                }
                else
                {



                	Node *p = head;
					while(p->next != cursor)
						{
							p=p->next;
						}

				  p->next = temp;

				  temp->previous = p;
				  temp->next = cursor;
				  cursor->previous = temp;


				}}


            }

      }


      //Preconditions: Current position is not EOL and list is not empty.
      //Postconditions: The item at the current position is removed from the list.
      //The current position becomes that of the item's successor,
      //or EOL if the removed item were the last in the list.

     void List_3358::remove ( )
     {
		 if(atEOL())
		 {
		 cursor = tail;

		 }


         if (!isEmpty())
			{
				Node *p = head;

             if(cursor == head)
             {
				 cursor = head->next;
				 delete p;
				 head = cursor;
				// head ->previous = NULL;

                 if(head == NULL)
                    tail = NULL;  ///If there's only 1 item in the list
             }



			 else
			 {
				 while(p->next != cursor)
						{
							p=p->next;
						}


				  p->next = cursor->next;

				 if (cursor == tail)
				{

				delete cursor;
				 tail = p;
				cursor = tail;



				// delete tail;
				//	tail = cursor;
                 }
				 else
                {


					delete cursor;
					cursor = p->next;
					cursor->previous = p;




                }

			  }



            }
	 }


      //Preconditions: None.
      //Postconditions: Resets the current position to the beginning of the list BOL.
      //If the list is empty, then the position is set to EOL.

     void List_3358::reset ( )
     {
         cursor = head;
     }


      //Preconditions: None.
      //Postconditions: Advances the current position to the next item in the list.
      //Advancing from EOL leaves the current position at EOL.
      //If the position following the advance is not EOL, the result of the function is TRUE,
      //and if the position following the advance is EOL, the result of the function is FALSE.

    bool List_3358::advance ( )
    {
	if(!atEOL())
        cursor = cursor->next;

        return (!atEOL());
    }



      //*******************
      // Accessor(s)

      //Preconditions: None.
      //Postconditions: Return value is true if the list contains no items, and false otherwise.

      bool List_3358::isEmpty ( ) const
      {
          return (head == NULL);
      }


      //Preconditions: None.
      //Postconditions: Return value is true if the current position is logically at EOL,
      //and false otherwise.


    bool List_3358::atEOL ( ) const
      {
          return(cursor == NULL);
      }


      //Preconditions: None.
      //Postconditions: Return value is true if the list contains its capacity of items,
      //and false otherwise.

      bool List_3358::isFull ( ) const
      {
	return false;
      }



      //Preconditions: Current position is not EOL or at BOL.
      //Postconditions: Return value is a copy of the item at the current position.
      //The list is unaffected.

       List_3358::value_type List_3358::getCurrent() const
       {
           if(!atEOL())
            return(cursor->value);
       }

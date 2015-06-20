//list_3358.cpp
//By:Firdaus Botirzoda
//implementation of a very simple curssor-based List ADT
//This is a simple array implementation

#include "list_3358_arrays.h"
#include <iostream>


using namespace std;
using namespace cs3358;

     List_3358::List_3358 ( ) {
         currentSize = 0;
         cursor = 0;
         head = -1;
         tail = -1;

      }


      List_3358::List_3358 ( const List_3358 & src ) {

         currentSize = src.currentSize;
         cursor = src.cursor;
         head = src.head;
         tail = src.tail;
         for (int i = 0 ; i < currentSize; i++)
           {

            values[i] = src.values[i];
            next[i] = src.next[i];
            previous[i] = src.previous[i];

           }
      }


      List_3358::~List_3358 ( ) {

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

      void List_3358::insert (const value_type & item) {



         if (!isFull())
         {


             if(isEmpty() && !isFull())
          {

         next[currentSize] = -1;

          previous[currentSize] = -1;
          values[currentSize] =item;
          head = currentSize;
          tail = currentSize;

          currentSize++;
         cursor++;


          }

          else  if (atEOL())
               {
              //  cout << "(IMPL) inserting atEOL" << endl;


             next[tail]= currentSize;

             previous[currentSize]= tail;
            next[currentSize] = -1;
            tail = currentSize;
            cursor++;


              currentSize++;

                          }
            else if (cursor == head)

            {
               // cout << "(IMPL) inserting at cursor==head" << endl;


                values[currentSize] = item;
                previous[head] = currentSize;
                next[currentSize] = head;
                previous[currentSize] = -1;
                head = currentSize;
                currentSize++;

            }


                else    ///Inserting at the middle
            {
             //   cout << "(IMPL) inserting at the middle" << endl ;


              values[currentSize] = item;
              int t = previous[cursor];
              next[t] = currentSize;
              previous[currentSize] = t;
              previous [cursor] = currentSize;
              next[currentSize] = cursor;
              currentSize++;

            }
          }

     }



      void List_3358::remove() {

         if (!atEOL() && !isEmpty())
         {
            for (int i = cursor; i < currentSize - 1; i++)
               values[i] = values[i+1];

            currentSize--;
         }

      }


      void List_3358::reset ( ) {

         cursor = head;

      }



      bool List_3358::advance ( ) {

         if (atEOL())
         {

            return false;
         }
         else
         {
            cursor = next[cursor];
         }

         return (!atEOL());

      }



      //*******************
      // Accessor(s)


      bool List_3358::isEmpty ( ) const {

         return (currentSize == 0);

      }



      bool List_3358::atEOL ( ) const {
    if(cursor == currentSize || cursor == -1 )
   {
       return true;
   }

        else
        return false;
      }


      bool List_3358::isFull ( ) const {

         return (currentSize == MAX_ITEMS);
      }



      List_3358::value_type List_3358::getCurrent ( ) const {
        // if(!atEOL())
            return values[cursor];
      }





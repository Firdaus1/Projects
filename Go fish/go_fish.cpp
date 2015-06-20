// FILE: card_demo.cpp
//this is a demo program to show how the card is used
//Author: John Hooper and Firdaus Botirzoda

//Created on February 12nd, 2015
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <ctime>
#include <vector>
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

int main( )
{
   Card tempRemoveCard1, tempRemoveCard2;
   Card temp1; 
   Card temp2;
   Card temp3;
   int duh;
   bool turn = true;
   srand((unsigned)time(NULL));
   Deck d;
   d.shuffle();
   Player p1("joe"), p2("Lisa");
   
   p1.addCard(d.dealCard());
   p2.addCard(d.dealCard());

  for (int i = 0; i < 7; i++)
  {
	temp1 = d.dealCard();

	
	temp2 = d.dealCard();


	if(p1.cardInHand(temp1))
	{
	p1.bookCards(temp1, p1.removeCardFromHand(temp1));
	}
	    else
	    {
		p1.addCard(temp1);
	    }
	
    if(p2.rankInHand(temp2))
	{
    p2.bookCards(temp2,p2.removeCardFromHand(temp2) );
	}
		else
		{
		p2.addCard(temp2);
		}
	}
  
  while (d.size() > 0 || p1.getHandSize() > 0)
  {

    while (turn)
    {
			tempRemoveCard1 = p1.chooseCardFromHand();
        
        cout << p1.getName() << " asks "  << " do you have a " << tempRemoveCard1 << "?\n";
	
        if(!p2.sameRankInHand(tempRemoveCard1))
        {
			cout << "Go Fish\n";
        
			if( d.size() > 0)
			{
				temp3 = d.dealCard();
				if(p1.cardInHand(temp3))
				{
					p1.bookCards(temp3, p1.removeCardFromHand(temp3));
					if(p1.getHandSize() == 0)
					{
						p1.addCard(d.dealCard());
					}
				}
		
				else
				{
					p1.addCard(temp3);
				}
			}

			turn = false;
        }
        
		else
        {
			cout << p2.getName() << " says - Yes. I do have a " << tempRemoveCard1 << endl;
		
			p1.bookCards(p2.removeCardFromHand(tempRemoveCard1),p1.removeCardFromHand(tempRemoveCard1));
			if(p1.getHandSize() == 0 && d.size() > 0)
			{
				p1.addCard(d.dealCard());
			}
			if(p2.getHandSize() == 0 && d.size() > 0)
			{
				p2.addCard(d.dealCard());
			}
			cout << p1.getName() << " books the " << tempRemoveCard1 << endl;
        }
		if(d.size() == 0 && p1.getHandSize() == 0 && p2.getHandSize() == 0)
		  break;
    }

      while (!turn)
      {
		     
			tempRemoveCard1 = p2.chooseCardFromHand();

			cout << p2.getName() << " asks "  << " do you have a " << tempRemoveCard1 << "?\n";
			 if(!p1.sameRankInHand(tempRemoveCard1))
			 {
				cout << "Go Fish\n";

				if( d.size() > 0)
				{
					temp3 = d.dealCard();
					if(p2.cardInHand(temp3))
					{
						p2.bookCards(temp3, p2.removeCardFromHand(temp3));
						if(p2.getHandSize() == 0)
						{
							p2.addCard(d.dealCard());
						}
	
		  
					}
					else
					{
						p2.addCard(temp3);
					}
				}
				turn = true;
			}
			 else
			{
			cout << p1.getName() << " says - Yes. I do have a " << tempRemoveCard1 << endl;
			p2.bookCards(p1.removeCardFromHand(tempRemoveCard1),p2.removeCardFromHand(tempRemoveCard1));
			if(p2.getHandSize() == 0 && d.size() > 0)
			{
				 p2.addCard(d.dealCard());
			}
			if(p1.getHandSize() == 0 && d.size() > 0)
			{
				p1.addCard(d.dealCard());
			}
			cout << p2.getName() << " books the " << tempRemoveCard1 << endl;
			}

	  }
	  if(d.size() == 0 && p1.getHandSize() == 0 && p2.getHandSize() == 0)
		  break;
  }


// choosing the winner

if (p1.getBookSize() > p2.getBookSize())
    {
    cout << p1.getName() << " has " << p1.getBookSize() << " books and is the winner!\n";
	cout << p2.getName() << " has  " << p2.getBookSize() << " books!" << endl;
    }
    else
    {
        cout << p2.getName() << " has " << p2.getBookSize() << " books and is the winner!\n";
		cout << " PLayer 1 has  " << p1.getBookSize() << " books!" << endl;
    }


   return EXIT_SUCCESS;
}









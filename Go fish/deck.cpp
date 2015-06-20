//File:   Cards.cpp
//Author: John Hooper and Firdaus Botirzoda

//Created on February 12nd, 2015

// Deck Logic
#include "card.h"
#include "deck.h"
#include <cstdlib>
#include <ctime>
#include <iostream> 

Deck::Deck(){              // pristine, sorted deck
    int i = 0;			
	while (i < 52){
		if(i < 13){
			Card C((i+1),(Card::Suit)0);
			myCards[i] = C;
			
			i++;
		}
		else if(i < 26){
			Card C((i-12),(Card::Suit)1);
			myCards[i] = C;
			
			i++;
		}
		else if(i < 39){
			Card C((i-25),(Card::Suit)2);
			myCards[i] = C;
			
			i++;
		}
		else if(i < 52){
			Card C((i-38),(Card::Suit)3);
			myCards[i] = C;
			
			i++;
		}
	}
        myIndex=0;
}

//Shuffles the deck of 52 cards
void Deck::shuffle(){        
 srand((unsigned int)time(NULL));
 Card temp, temp2;
 int placeholder, placeholder2;

 int i = 0;
    while (i < SIZE)
    {
     placeholder = ((rand()%52));
     placeholder2 = ((rand()%52));

	if (placeholder !=0 && placeholder2 !=0)
    { 
	  temp = myCards[placeholder];
      temp2 = myCards[placeholder2];

     myCards[placeholder] = temp2;
     myCards[placeholder2] = temp;
	}
	
    i++;
	}
}   

//Gets a card, after 52 are dealt, fails
Card Deck::dealCard(){        
    if(myIndex < SIZE){
        Card temp = myCards[myIndex];
		myIndex++;
		return temp;
	}
    else{
        cout << "Deck is out of cards.\n";
    }
}
 
//Returns number of cards left in the deck
int  Deck::size() const{
return (SIZE - myIndex);
}
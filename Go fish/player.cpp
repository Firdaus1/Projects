//File:   Cards.cpp
//Author: John Hooper and Firdaus Botirzoda
//Created on February 12nd, 2015

//Player Logic
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include "deck.h"
#include "player.h"

    
Player::Player(){
}
//Pre-Condition: Pass data of type Card
//Post-Condition: Adds a card to the hand
void Player::addCard(Card c){   
	myHand.push_back(c);
}

//Pre-Condition: Pass two data of type Card
//Post-Condition: Puts Cards in the vector myBook
void Player::bookCards(Card c1, Card c2){
	myBook.push_back(c2);
    myBook.push_back(c1);
}

//Pre-Condition: Pass data of type Card
//Post-Condition: this function will check a players hand for a pair. 
//If a pair is found, it returns true and populates the two variables
//with the cards tha make the pair.

//Pre-Condition: Pass two data of type Card
//Post-Condition:Returns true if Cards match
bool Player::checkHandForBook(Card &c1, Card &c2){
    if(c1.getRank() == c2.getRank()){
        return true;
    }
    else
        return false;
}
//Pre-Condition: Pass data of type Card
//Post-Condition: Asks the player if they have a card
//with the same rank as c in hand?
bool Player::rankInHand(Card c) const{
	Card temp;
	   for(int i=0; i < myHand.size(); i++){
          temp = myHand [i];
           if(temp.getRank() == c.getRank()){
             return true;
           }
       }
return false;
}

//Pre-Condition: Must have a card in players hand
//Post-Condition: Randomly chooses one card from the player's
//hand so they can say "Do you have this Card?"
Card Player::chooseCardFromHand() const{
    int srand((unsigned)time(NULL));
    int temp = myHand.size();
    int num = (rand() % (temp + 1));				
    return myHand [num];
} 

//Pre-Condition: Pass data of type Card
//Post-Condition: Check the players hand for card c
bool Player::cardInHand(Card c) const{
    Card temp;
	   for(int i=0; i < myHand.size(); i++){
          temp = myHand [i];
            if(temp.getRank() == c.getRank()){
               return true;
       }
    }
    return false;
} 
    
//Pre-Condition: Pass data of type Card and must have checked cardInHand() first
//Post-Condition: Removes the card c from the hand
//and returns it to the caller
Card Player::removeCardFromHand(Card c){
    Card temp;
	for(int i=0; i < myHand.size(); i++){
        temp = myHand[i];
          if(temp.getRank() == c.getRank()){
			  myHand.erase(myHand.begin()+i);
			  return temp;
          }		
    }
}

//Pre-Condition: Must have a Card in Players hand
//Post-Condition: Returns a concatinated list of cards
string Player::showHand() const{
    if(myHand.size() > 0 ){
		string hand = "Cards in hand: ";
		Card temp;
		  for(int i=0; i < myHand.size(); i++){
			temp = myHand [i];
			hand += temp.toString() + " ";
		  }
		return hand;
	}
	string hand2 = "Player " + myName + " has no cards in hand\n";
	return hand2;
}
    
//Pre-Condition: Must have listed books in vector
//Post-Condition: Returns a concatinated list of cards in book
string Player::showBooks() const{
	if(myBook.size() > 0 ){

		string book = "Books: ";
		Card temp;
		  for(int i=0; i < myBook.size(); i++){
			temp = myBook [i];
			book += temp.toString() + " ";
		  }
		return book;
	} 
	string book2 = "Player " + myName + " has no books available\n";
	return book2;
} 

//Pre-Condition: None
//Post-Condition:Returns the size of cards in hand
int Player::getHandSize() const{
    return myHand.size();
}

//Pre-Condition: None
//Post-Condition: Returns the size of booked cards
int Player::getBookSize() const{
    return (myBook.size()/2);
} 

//Pre-Condition: Passes data of type Card for two veriables
//Post-Condition: This function will check a players hand for a pair. 
//If a pair is found, it returns true and populates the two variables
//with the cards that make the pair.
bool Player::checkHandForPair(Card &c1, Card &c2){
    if(c1.getRank() == c2.getRank()){
        
         return true;
    }
    return false;
}

//Pre-Condition: Pass data of type Card
//Post-Condition: Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c
    
bool Player::sameRankInHand(Card c) const{
	  Card temp;
	  int handSize = myHand.size();
	   for(int i=0; i < handSize; i++){
          temp = myHand [i];
            if(temp.getRank() == c.getRank()){
               return true;
       }
    }
    return false;
}
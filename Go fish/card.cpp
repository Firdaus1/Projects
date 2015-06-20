/* 
 * File:   Cards.cpp
 * Author: John Hooper and Firdaus Botirzoda
 *
 * Created on February 2nd, 2015
 */

#include "card.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>    
    
Card::Card(){
    mySuit = spades;     // default, ace of spades
    myRank = 1;
}

Card::Card(int rank, Suit s){
    //string card;
    myRank = rank;
    mySuit = s;
}

string Card::toString() const{ //Post-Condition: return string version e.g. Ac 4h Js
    return rankString(myRank) + suitString(mySuit);
}
  
bool Card::sameSuitAs(const Card& c) const{ //Post-Condition: true if suit same as c    
  return mySuit == c.mySuit;
}

int Card::getRank() const{
  return myRank;
}  // return rank, 1..13
    
string Card::suitString(Suit s) const{  // returns "Spades", "Hearts",...
    switch(s){
        case 0: return "Spades";
        case 1: return "Hearts";
        case 2: return "Diamonds";
        case 3: return "Clubs";
    }
}
    
string Card::rankString(int r)       const{  // return "A", "2", ..."Q"  
		ostringstream temp;
                  temp << r;
				  string s;
                  s = (temp.str()) + " of ";	
				
	switch(r){
        case 1: return "Ace of ";
        case 11: return "Jack of ";
        case 12: return "Queen of ";
        case 13: return "King of ";	
		default: return s;
     		
				 
    }
}
    
bool Card::operator == (const Card& rhs) const{
    if (myRank != rhs.myRank && mySuit != rhs.mySuit){
         return false;
    }
    else return true; 
    }
    
bool Card::operator != (const Card& rhs) const{
    if(myRank != rhs.myRank && mySuit != rhs.mySuit){
        return true;
    }
    else  return false;
}
    
ostream& operator << (ostream& out, const Card& c){
    out << c.toString();
    return out;
}
 
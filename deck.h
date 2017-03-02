#ifndef DECK_H
#define DECK_H
#include "card.h"


class Deck  
{
	public:
		Deck();					//constructor
		~Deck();				//destructor
		void Display ();		//displays the contents of the deck in order
		void Shuffle ();		//randomly shuffles the deck
		Card SendCard ();		//returns a card (used for dealing cards)
		int Get_Position ();	//returns the number of cards that have been used

	private:
		Card cards [52];		//array of 52 cards - a full deck
		int position;			//the number of cards that have been used
};

#endif

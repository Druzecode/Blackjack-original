#include <iostream.h>
#include "Deck.h"
#include "random.h"


Deck::Deck()		//constructor
{
	position = 0;	//beginning of deck
	int y = 0;
	for (int count = 1; count <= 4; count++)	//gives a value to each card in the deck (ordered by suit than rank)
	{
		for (int i = 1; i <= 13; i++)
		{
			cards [y].Set_Rank (i);
			cards [y].Set_Suit (count);
			y++;
		}
	}
}

Deck::~Deck()		//destructor
{

}

void Deck::Shuffle ()	//shuffles the deck
{
	int x , y;			//random numbers
	Card temp;			//temporary card holder
	for (int i = 0; i < 300; i++)
	{
		x = randnum (0, 51);	//places a random card in the temp holder
		temp = cards [x];
		y = randnum (0, 51);	//moves a random card to the original card's place
		cards[x] = cards [y];
		cards [y] = temp;		//places the temp card into the moved cards place
	}
	position = 0;		//resets the pointer to the start of the deck
}

void Deck::Display ()	//displays all of the cards in the deck (not used in the actual game)
{
	for (int i = 0; i < 52; i++)
	{
		cards[i].Display_Card ();	//displays text value for each card (e.g. "nine of hearts")
		cout << endl;
	}
	cout << endl << endl;
}

Card Deck::SendCard ()		//returns the "top" card on the deck
{
	position ++;			//points to next card
	return cards [position - 1];	//returns previous card
	
}

int Deck::Get_Position ()	//returns the position in the deck
{
	return position;
}
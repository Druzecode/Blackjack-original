#ifndef CARD_H
#define CARD_H

class Card
{
	public:
		Card();						//constructor
		enum Suit {Hearts = 1, Diamonds, Clubs, Spades};
		enum Rank {Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
		void Display_Card ();		//displays the value of the card (e.g. "nine of hearts")
		void Draw_Card ();			//calls the appropriate private member function to draw each card
		void Set_Rank (int);		//sets a card's rank
		void Set_Suit (int);		//sets a card's suit
		int Get_Value (bool&);		//returns the number value of a card
		void Draw_Back ();			//draws the back of a card on the screen
		Suit suit;					//the card's suit
		Rank rank;					//the card's rank

	private:
		void Draw_Ace(int);			//functions to draw each card
		void Draw_Two(int);
		void Draw_Three(int);
		void Draw_Four(int);
		void Draw_Five(int);
		void Draw_Six(int);
		void Draw_Seven(int);
		void Draw_Eight(int);
		void Draw_Nine(int);
		void Draw_Ten(int);
		void Draw_Jack(int);
		void Draw_Queen(int);
		void Draw_King(int);
};

#endif
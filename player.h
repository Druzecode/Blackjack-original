#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "deck.h"

class Player
{
	//declared in game.h
	friend void main ();
	friend void Deal (Player& player, Deck& d1);
	friend void Deal_H (Player& house, Deck& d1);
	friend bool Choice (Player& player, Deck& d1, double& bet);
	friend void Hit (Player& player, Deck & d1);
	friend void Split (Player& player, Player& house, Deck& d1, double bet);
	friend void DoubleDown (Player& player, Deck& d1, double& bet);
	friend void H_Play (Player& house, Deck& d1);
	friend void Decision (Player& player, Player& house, Deck& d1, double& bet);
	friend double Bet (Player& player);
	friend void Settle (Player& player, Player& house, double& bet);

	public:
		Player ();			//constructor
		Player (char*);		//constructor
		~Player ();			//destructor
		void GetCard (Deck&);	//Gets the next card from the deck
		void DisplayCards (void);	//displays the player's cards

	private:
		char* name;			//player's name
		int num_of_cards;	//number of cards in the player's hand
		Card hand [5];		//the actual cards in the player's hand
		int total;			//the total value of the cards in the player's hand
		double money;		//the player's amount of money available to bet


};


#endif;
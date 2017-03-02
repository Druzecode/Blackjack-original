/*******************************************************************************
*  Name:			Drew Bryan
*  Class:			CST 136
*  Project:			BlackJack Lab
*  Date Created:	11/25/00
*  Last modified:	11/27/00
*  Files:			main.cpp, card.h, card.cpp, deck.h, deck.cpp,
*					  game.h, game.cpp, player.h, player.cpp,
					  random.h, random.cpp
*
* Overview:
*		This program displays cards to the user in the form of a BlackJack game, 
*	and allows the user to interact, and control the outcome of his/her player.
*
* Input:
*		Input all comes from the user via the keyboard.
*
* Ouput:
*		Output is sent to the screen.  Cards are displayed, totaled, and then
*	the game is decided..
*
********************************************************************************/


#include <iostream.h>
#include "player.h"
#include "deck.h"
#include "card.h"
#include "game.h"

void main (void)  //Controls the basic flow of the game
{
	Intro ();			//displays intro sequence
	char go;			//continues the game if the user chooses to continue after each round
	double bet = 0;		//amount bet each hand
	bool split = false;	//becomes true if the player chooses to split
	Deck d1;			//object deck (used as the only deck in the program
	d1.Shuffle ();		//shuffles the deck
	Player player;		//object player
	Player house ("The House");	//object house
	do							//start of actual game play
	{
		if (d1.Get_Position() > 40) //shuffles the deck so that the cards will never be repeated
			d1.Shuffle ();

		bet += Bet (player);		//prompts the player for a bet, and stores it as a double
		Deal (player, d1);			//deals cards to player
		Deal_H (house, d1);			//deals cards to house

		split = Choice (player, d1, bet);	//controls the route of the game if player chooses to split
		if (split == true)
		{
			Split (player, house, d1, bet);	//split sequence
			split = false;					//resets the flag
		}
		else								//course of game if the player does not split
		{
			H_Play (house, d1);				//makes decisions for the house
			Decision (player, house, d1, bet);	//makes the final game decision after player and house are done
			Settle (player, house, bet);		//resets the bet to 0 after the money was awarded, and resets the players' hands
		}
		go = Go_Play ();			//continues play if user chooses to

	}while ((go == 'y' || go == 'Y') && player.money >= MIN_BET);  //exits game when user has no more money, or user chooses to quit
	
	cout << "Your final total was: $" << player.money <<endl;
	cout << "Thanks for playing\n\n";

}


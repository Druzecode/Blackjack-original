#include "player.h"
#include "deck.h"
#include <iostream.h>
#include <string.h>


Player::Player ()		//constructor
{
	char* temp = new char [256];		//temporary buffer for name
	cout << "Enter your player's name: ";	//prompts user for input
	cin.ignore(cin.rdbuf() -> in_avail());
	cin.getline (temp, 255);			//reads in a name
	cin.ignore (cin.rdbuf() -> in_avail());

	name = new char [sizeof(temp) + 1];		//allocates space for the player's name
	strcpy (name, temp);					
	delete [] temp;				//deletes temporary buffer

	num_of_cards = 0;	//sets initial amount of cards in hand to 0
	money = 100;		//sets intiial amount of money to 100;
	total = 0;			//total value of cards in hand, initially set to 0

}

Player::Player (char* ptr)
{
	name = new char [sizeof(ptr) + 1];
	strcpy (name, ptr);

	num_of_cards = 0;
	money = 100;
	total = 0;
}

Player::~Player ()
{

}

void Player::GetCard (Deck& d1)
{
	hand [num_of_cards] = d1.SendCard (); 
	num_of_cards ++;
}

void Player::DisplayCards (void)
{
	int x = 0;
	while (x < num_of_cards)
	{
		hand [x].Draw_Card ();
		x++;
	}
}

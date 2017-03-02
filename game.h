
#ifndef GAME_H
#define GAME_H

#include <iostream.h>
#include "player.h"
#include "deck.h"
#include "card.h"
#include "game.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MIN_BET 5

void Intro (void);				//displays an intro sequence
void Deal (Player& player, Deck& d1);	//deals the cards to the player
void Deal_H (Player& house, Deck& d1);	//deals the cards to the house
bool Choice (Player& player, Deck& d1, double& bet);	//allows the player to choose what to do
void Hit (Player& player, Deck & d1);	//deals another card when Hit is selected
void Split (Player& player, Player& house, Deck& d1, double bet);	//controls the game upon selection of the split option
void DoubleDown (Player& player, Deck& d1, double& bet);		//doubles the bet and deals one more card to the player upon selection
void H_Play (Player& house, Deck& d1);		//The house's decisions to hit or stand
void Decision (Player& player, Player& house, Deck& d1, double& bet);	//decides who wins the game, and distributes money accordingly
double Bet (Player& player);	//prompts the user for a bet, and stores it as a double
void Settle (Player& player, Player& house, double& bet);	//resets the bet and the players hands after a game
char Go_Play ();	//continues the game after each hand, or quits

#endif

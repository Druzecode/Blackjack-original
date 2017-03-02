#include "game.h"

void Intro ()		//displays intro sequence
{
	char* word = "BLACKJACK";
	cout.setf(ios::unitbuf);

	cout << "\t\t\t\tWelcome To:" << endl << endl; 
	for (unsigned int x = 0; x < strlen(word); x++)
	{
		
		int clock2 = clock();
		while (clock() - clock2 < 150);
		cout << "\t" << word[x];
	}
	cout << endl << endl;
	for (unsigned int i = 0; i < 10; i++)
	{ 
		cout << char (6) << " ";
		int clock3 = clock();
		while (clock() - clock3 < 50);
		cout << char (3) << " ";
		int clock4 = clock();
		while (clock() - clock4 < 50);
		cout << char (4) << " ";
		int clock5 = clock();
		while (clock() - clock5 < 50);
		cout << char (5) << " ";
		int clock6 = clock();
		while (clock() - clock6 < 50);
	}
	cout << endl << endl;
}

double Bet (Player& player)
{
	double bet = 0;
	do
	{
		cout << "You currently have $" << player.money << endl;
		cout << "How much would you like to bet? $";
		cin >> bet;
		cout << endl;
		if (bet > player.money)
			cout << "You do not have that much money!\n\n";
		else if (bet <= 5)
			cout << "You must enter a valid bet (minimum $" << MIN_BET << ")!\n\n";
	}while (bet > player.money || bet < MIN_BET);		//reprompts user if an invalid input is entered
	
	system ("cls");			//clear screen
	return bet;
}

void Deal (Player& player, Deck& d1)		//deals cards to the player's hand
{
	cout << player.name << " has: \n";
	player.hand [player.num_of_cards] = d1.SendCard();	//gets first card
	player.hand [player.num_of_cards].Draw_Card ();		//displays first card
	player.num_of_cards++;					//increments the number of cards in the player's hand

	player.hand [player.num_of_cards] = d1.SendCard();	//gets the second card
	player.hand [player.num_of_cards].Draw_Card ();		//displays the second card
	player.num_of_cards++;					//increments the number of cards in the player's hand
	
	int clock2 = clock();
	while (clock() - clock2 < 3000);	//delays 3 seconds
	system ("cls");						//clears screen
}

void Deal_H (Player& house, Deck& d1)		//deals cards to the house
{
	cout << house.name << " has: \n";
	house.hand [house.num_of_cards] = d1.SendCard();	//gets first card
	house.hand [house.num_of_cards].Draw_Card ();		//displays house's up card
	house.num_of_cards++;					//increments the number of cards in the house's hand

	house.hand [house.num_of_cards] = d1.SendCard();	//gets first card
	house.hand [house.num_of_cards].Draw_Back ();		//displays the back of the house's hold card
	house.num_of_cards++;					//increments the number of cards in the house's hand

	int clock1 = clock();
	while (clock() - clock1 < 3000);	//delays 3 seconds
	system ("cls");						//clears screen
}

bool Choice (Player& player, Deck& d1, double& bet)
{
	bool cont = true;		//continues
	bool split = false;		//becomes true when the split function is chosen
	while (cont == true)
	{
		player.total = 0;	//resets player's total to 0 before it is recalculated
		int choice = 0;		//player's choice (entered later)
		bool flag = false;	//true if cards in hand total over 21
		cont = false;		//resets the continue flag
		int x = 0;			//counting variable
		system ("cls");		//clears screen
		cout << player.name << ", you have the: \n";
		while (x < player.num_of_cards)		//displays player's cards and calculates the player's total
		{
			cout << "\t";
			player.hand [x].Display_Card ();
			cout << endl;
			player.total += player.hand[x].Get_Value(flag);
			x++;
		}
		if (player.total > 21)	//recalculates total if ace must be set to 1 instead of 11
		{
			x = 0;					//resets counting variable
			player.total = 0;		//resets total for new count 
			while (x < player.num_of_cards)
			{
				flag = true;
				player.total += player.hand[x].Get_Value(flag);
				x++;
			}
		}
		if (player.total > 21)	//recalculates total if ace must be set to 1 instead of 11
		{
			x = 0;					//resets counting variable
			player.total = 0;		//resets total for new count 
			while (x < player.num_of_cards)
			{
				flag = true;
				player.total += player.hand[x].Get_Value(flag);
				x++;
			}
		}

		cout << endl;
		cout << "You have a total of: " << player.total;
		cout << endl << endl;
		
		if (player.total <= 21 && player.num_of_cards < 5)	//exits when player is over 21, or over 5 cards
		{
			if (player.hand[0].rank == player.hand[1].rank && player.num_of_cards == 2 && player.money >= (bet * 2))  //allows split and double down options
			{
				if (player.total == 10 || player.total == 11)
				{
					do
					{
						cout << "Would you like to (1)Hit, (2)Stand, (3)Split, or (4)Double Down? ";	//displays options
						cin >> choice;
						cout << endl;
						if (choice < 1 || choice > 4)
							cout << "Please make another selection\n\n";
					}while (choice < 1 || choice > 4);		//continues on invalid selections
				}
				else	//allows split option
				{
					do
					{
						cout << "Would you like to (1)Hit, (2)Stand, or (3)Split? ";			//displays options
						cin >> choice;
						cout << endl;
						if (choice < 1 || choice > 3)
							cout << "Please make another selection\n\n";
					}while (choice < 1 || choice > 3);		//continues on invalid inputs
				}
			}
			else if (player.hand[0].rank != player.hand[1].rank && (player.total == 10 || player.total == 11) && player.num_of_cards == 2)	//allows double down option
			{
				do
				{
					cout << "Would you like to (1)Hit, (2)Stand, or (3)Double Down? ";		//displays options
					cin >> choice;
					cout << endl;
					if (choice < 1 || choice > 3)
						cout << "Please make another selection\n\n";
				}while (choice < 1 || choice > 3);	//continues on invalid selection
				if (choice == 3)
					choice = 4;		//sets proper value to double down selection, to prevent from calling split function
			}
			else
			{
				do
				{
					cout << "Would you like to (1)Hit or (2)Stand? ";		//normal options
					cin >> choice;
					cout << endl;
					if (choice < 1 || choice > 2)
						cout << "Please make another selection\n\n";
				}while (choice < 1 || choice > 2);	//continues on invalid input
			}
		}
		else
			choice = 2;

		if (choice == 1)
		{
			Hit (player, d1);		//calls hit function if selected
			cont = true;
		}
		else if (choice == 3)
		{
			split = true;			//calls split function if chosen
			cont = false;
		}
		else if (choice == 4)
		{
			DoubleDown (player, d1, bet);	//calls double down function if chosen
			cont = false;
		}
	}
	return split;		//returns true if split is selected
}

void Hit (Player& player, Deck& d1)
{
	system ("cls");		//clears screen

	cout << player.name << " received the \n";
	player.hand [player.num_of_cards] = d1.SendCard();	//gets a new card from the deck
	player.hand [player.num_of_cards].Draw_Card ();		//displays new card
	player.num_of_cards++;			//increments number of cards in hand

	int clock1 = clock();
	while (clock() - clock1 < 2000);	//waits 2 seconds
	system ("cls");
}

void Split (Player& player, Player& house, Deck& d1, double bet)
{
	char temp [300];
	strcpy (temp, player.name);
	strcat (temp, "'s second hand");
	Player player2 (temp);		//new object, player's second hand
	player.num_of_cards = 1;
	player2.num_of_cards = 1;
	player2.hand[0] = player.hand[1];	//splits hand
	Hit (player, d1);					//adds a new card to first hand
	Hit (player2, d1);					//adds a new card to second hand
	
	Choice (player, d1, bet);			//plays first hand
	Choice (player2, d1, bet);			//plays second hand

	H_Play (house, d1);					//house plays

	cout << "First Hand:\n";
	Decision (player, house, d1, bet);	//decides if first hand wins
	cout << "Second Hand:\n";
	Decision (player2, house, d1, bet);	//decides if second hand wins
	player.money += (player2.money - 100);

	Settle (player, house, bet);		//resets values from next hand
}

void DoubleDown (Player& player, Deck& d1, double& bet)
{
	bool x = false;
	Hit (player, d1);	//gives the player one more card
	bet *= 2;			//doubles the bet
	if (player.total == 11)
		x = true;

	player.total += player.hand[2].Get_Value(x);	
}

void H_Play (Player& house, Deck& d1)		//house plays its hand
{
	bool cont = true;		//continues until house is finished
	while (cont == true)
	{
		house.total = 0;
		bool flag = false;
		cont = false;
		int x = 0;			//counter variable
		system ("cls");		//clear screen
		cout << house.name << " has the: \n";
		while (x < house.num_of_cards)		//displays house's cards and calculates the total value
		{
			cout << "\t";
			house.hand [x].Display_Card ();		//displays the cards that are in the house's hand
			cout << endl;
			house.total += house.hand[x].Get_Value(flag);		//calculates the total value
			x++;			//increment counter
		}
		if (house.total > 21)		//recounts with ace equal to 1
		{
			x = 0;
			house.total = 0;
			while (x < house.num_of_cards)
			{
				flag = true;
				house.total += house.hand[x].Get_Value(flag);
				x++;
			}
		}

		cout << endl;
		cout << "The House has a total of: " << house.total;
		cout << ", and chooses to ";
		if (house.total < 17)
		{
			cout << "hit\n";
			int clock1 = clock();
			while (clock() - clock1 < 2500);	//wait 2.5 seconds
			Hit (house, d1);					//deals another card to the house
			cont = true;
		}
		else
			cout << "stand\n";
	}
}

void Decision (Player& player, Player& house, Deck& d1, double& bet)
{
	cout << "You have a total of " << player.total << endl << endl;

	int clock1 = clock();
	while (clock() - clock1 < 2000);		//wait 2 seconds

	if (player.total < 21 && player.num_of_cards == 5 && house.num_of_cards != 5)	//if you win five card rule
	{
		cout << "You Win! (five card rule)\n\n";
		player.money += bet;
	}
	else if (house.total < 21 && player.num_of_cards == 5 && player.num_of_cards != 5)	//if you lose five card rule
	{
		cout << "You Lose (five card rule)\n\n";
		player.money -= bet;
	}
	else
	{
		if (player.total == 21 && player.num_of_cards == 2)	//if you have a blackjack
		{
			if (house.total != 21 || house.num_of_cards > 2)	//if you win
			{
				cout << "You have a BlckJack!\nYou Win!\n\n";
				player.money += (bet * 1.5);
			}
			else												//if house has one too
			{
				cout << "Draw\n\n";
			}
		}
		else if (house.total == 21 && house.num_of_cards == 2)	//if house has a blackjack
		{
			cout << "The House has a BlckJack!\nYou Lose\n\n";
			player.money -= bet;
		}
		else
		{
			if (player.total > 21)						//test player for bust
				cout << "You are over!\n";
			if (house.total > 21)						//test house for bust
				cout << "House is over!\n";
			if (player.total > 21 && house.total > 21)	//test both for bust
			{
				cout << "Draw\n\n";
			}
			else if (player.total > 21 && house.total <= 21)	//if player is over
			{
				cout << "You Lose\n\n";
				player.money -= bet;
			}
			else if (house.total > 21 && player.total <= 21)	//if house is over
			{
				cout << "You Win!\n\n";
				player.money += bet;
			}
			else if (house.total <= 21 && player.total <= 21)	//both are under
			{
				if (house.total < player.total)					//if player beats house in points
				{
					cout << "You Win!\n\n";
					player.money += bet;
				}
				else if (house.total > player.total)			//if house beats player in points
				{
					cout << "You Lose\n\n";
					player.money -= bet;
				}
				else											//if tie with points
				{
					if (player.num_of_cards < house.num_of_cards)	//if player has fewer cards than house
					{
						cout << "You Win! (Fewer Cards)\n\n";
						player.money += bet;
					}
					else if (player.num_of_cards > house.num_of_cards)	//if player has more cards than house
					{
						cout << "You Lose (House has fewer cards)\n\n";
						player.money -= bet;
					}
					else												//both are equal (draw)
						cout << "Draw\n\n";
				}
			}
		}
	}
}

void Settle (Player& player, Player& house, double& bet)
{
	player.num_of_cards = 0;		//resets player's hand
	house.num_of_cards = 0;			//resets house's hand
	bet = 0;						//resets bet
}

char Go_Play ()
{
	char go;		//variable to continue
	cout << "Would you like to continue(y/n)? ";
	cin >> go;
	system ("cls");		//clear screen
	return go;			//returns user's input
}
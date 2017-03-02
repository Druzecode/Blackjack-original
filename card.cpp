#include <iostream.h>
#include "card.h"

Card::Card ()		//constructor
{
	rank = Ace;		//default original rank
	suit = Hearts;	//default original suit
}

void Card::Display_Card ()	//displays a card in text
{								//displays rank of card
	if (rank == 1)
		cout << "Ace";
	else if (rank == 2)
		cout << "Two";
	else if (rank == 3)
		cout << "Three";
	else if (rank == 4)
		cout << "Four";
	else if (rank == 5)
		cout << "Five";
	else if (rank == 6)
		cout << "Six";
	else if (rank == 7)
		cout << "Seven";
	else if (rank == 8)
		cout << "Eight";
	else if (rank == 9)
		cout << "Nine";
	else if (rank == 10)
		cout << "Ten";
	else if (rank == 11)
		cout << "Jack";
	else if (rank == 12)
		cout << "Queen";
	else if (rank == 13)
		cout << "King";
	else
		cout << "Error";

	cout << " of ";
								//displays suit of card
	if (suit == 1)
		cout << "Hearts";
	else if (suit == 2)
		cout << "Diamonds";
	else if (suit == 3)
		cout << "Clubs";
	else if (suit == 4)
		cout << "Spades";
	else
		cout << "Error";

}

void Card::Set_Suit (int x)		//sets a card's suit
{
	if (x == 1)
		suit = Hearts;
	else if (x == 2)
		suit = Diamonds;
	else if (x == 3)
		suit = Clubs;
	else if (x == 4)
		suit = Spades;
	else
		cout << "Error" << endl;
}

void Card::Set_Rank (int x)		//sets a card's rank
{
	if (x == 1)
		rank = Ace;
	else if (x == 2)
		rank = Two;
	else if (x == 3)
		rank = Three;
	else if (x == 4)
		rank = Four;
	else if (x == 5)
		rank = Five;
	else if (x == 6)
		rank = Six;
	else if (x == 7)
		rank = Seven;
	else if (x == 8)
		rank = Eight;
	else if (x == 9)
		rank = Nine;
	else if (x == 10)
		rank = Ten;
	else if (x == 11)
		rank = Jack;
	else if (x == 12)
		rank = Queen;
	else if (x == 13)
		rank = King;
	else
		cout << "Error" << endl;
}

int Card::Get_Value(bool& flag)		//returns the value of a card
{
	if (rank == Ace)
		if (flag == true)			//flag is true if total is over 21, and an Ace must be counted as a 1
		{
			return 1;
			flag = false;			//reset flag, to accommodate multiple aces in one hand
		}
		else
			return 11;				//by default, aces are counted as 11 originally
	else if (rank == Two)
		return 2;
	else if (rank == Three)
		return 3;
	else if (rank == Four)
		return 4;
	else if (rank == Five)
		return 5;
	else if (rank == Six)
		return 6;
	else if (rank == Seven)
		return 7;
	else if (rank == Eight)
		return 8;
	else if (rank == Nine)
		return 9;
	else if (rank == Ten)
		return 10;
	else if (rank == Jack)
		return 10;
	else if (rank == Queen)
		return 10;
	else if (rank == King)
		return 10;
	else
		return 0;
}

void Card::Draw_Back()				//draws the back of a card (for hold cards)
{
	cout << "\t" << char(218);

	for (int y = 0; y <= 10; y++)
	{
		cout << char(196);
	}
	cout << char(191) << endl;
	for(int x = 0; x < 9; x++)
	{
		cout << "\t" << char(179) << "***********" << char(179) << endl;
	}
	
	cout << "\t" << char(192); 

	for (y = 0; y <= 10; y++)
	{
		cout << char(196);
	}

	cout << char(217);
	cout << "\t";
	cout << "Hold Card";
	cout << endl;
}

void Card::Draw_Card()			//draws a specific card's picture
{
	int x;

	if(suit == Hearts)
	{
		x = 3;
	}
	else if(suit == Diamonds)
	{
		x = 4;
	}
	else if (suit == Clubs)
	{
		x = 5;
	}
	else
		x = 6;
	
	if(rank == Ace)
	{
		Draw_Ace(x);
	}
	if(rank == Two)
	{
		Draw_Two(x);
	}
	if(rank == Three)
	{
		Draw_Three(x);
	}
	if(rank == Four)
	{
		Draw_Four(x);
	}
	if(rank == Five)
	{
		Draw_Five(x);
	}
	if(rank == Six)
	{
		Draw_Six(x);
	}
	if(rank == Seven)
	{
		Draw_Seven(x);
	}
	if(rank == Eight)
	{
		Draw_Eight(x);
	}
	if(rank == Nine)
	{
		Draw_Nine(x);
	}
	if(rank == Ten)
	{
		Draw_Ten(x);
	}
	if(rank == Jack)
	{
		Draw_Jack(x);
	}
	if(rank == Queen)
	{
		Draw_Queen(x);
	}
	if(rank == King)
	{
		Draw_King(x);
	}
}

void Card::Draw_Ace(int x)
{
	cout << "\t" << char(218);

	for (int y = 0; y <= 10; y++)
	{
		cout << char(196);
	}
	cout << char(191) << endl;
	cout << "\t" << char(179) << " A         " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "     " << char(x) << "     " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "         A " << char(179) << endl;
	cout << "\t" << char(192); 

	for (y = 0; y <= 10; y++)
	{
		cout << char(196);
	}

	cout << char(217);
	cout << "\t";
	this->Display_Card ();
	cout << endl;


}

void Card::Draw_Two(int x)
{
	cout << "\t" << char(218);

	for (int y = 0; y <= 10; y++)
	{
		cout << char(196);
	}
	cout << char(191) << endl;
	cout << "\t" << char(179) << " 2         " << char(179) << endl;
	cout << "\t" << char(179) << "     " << char(x) << "     " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "     " << char(x) << "     " << char(179) << endl;
	cout << "\t" << char(179) << "         2 " << char(179) << endl;
	cout << "\t" << char(192); 

	for (y = 0; y <= 10; y++)
	{
		cout << char(196);
	}

	cout << char(217);
	cout << "\t";
	this->Display_Card ();
	cout << endl;
}

void Card::Draw_Three(int x)
{
	cout << "\t" << char(218);

	for (int y = 0; y <= 10; y++)
	{
		cout << char(196);
	}
	cout << char(191) << endl;
	cout << "\t" << char(179) << " 3         " << char(179) << endl;
	cout << "\t" << char(179) << "     " << char(x) << "     " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "     " << char(x) << "     " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "     " << char(x) << "     " << char(179) << endl;
	cout << "\t" << char(179) << "         3 " << char(179) << endl;
	cout << "\t" << char(192); 

	for (y = 0; y <= 10; y++)
	{
		cout << char(196);
	}

	cout << char(217);
	cout << "\t";
	this->Display_Card ();
	cout << endl;
}

void Card::Draw_Four(int x)
{
	cout << "\t" << char(218);

	for (int y = 0; y <= 10; y++)
	{
		cout << char(196);
	}
	cout << char(191) << endl;
	cout << "\t" << char(179) << " 4         " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   " << char(179) << endl;
	cout << "\t" << char(179) << "         4 " << char(179) << endl;
	cout << "\t" << char(192); 

	for (y = 0; y <= 10; y++)
	{
		cout << char(196);
	}

	cout << char(217);
	cout << "\t";
	this->Display_Card ();
	cout << endl;
}

void Card::Draw_Five(int x)
{
	cout << "\t" << char(218);

	for (int y = 0; y <= 10; y++)
	{
		cout << char(196);
	}
	cout << char(191) << endl;
	cout << "\t" << char(179) << " 5         " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "     " << char(x) << "     " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   " << char(179) << endl;
	cout << "\t" << char(179) << "         5 " << char(179) << endl;
	cout << "\t" << char(192); 

	for (y = 0; y <= 10; y++)
	{
		cout << char(196);
	}

	cout << char(217);
	cout << "\t";
	this->Display_Card ();
	cout << endl;
}

void Card::Draw_Six(int x)
{
	cout << "\t" << char(218);

	for (int y = 0; y <= 10; y++)
	{
		cout << char(196);
	}
	cout << char(191) << endl;
	cout << "\t" << char(179) << " 6         " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   " << char(179) << endl;
	cout << "\t" << char(179) << "         6 " << char(179) << endl;
	cout << "\t" << char(192); 

	for (y = 0; y <= 10; y++)
	{
		cout << char(196);
	}

	cout << char(217);
	cout << "\t";
	this->Display_Card ();
	cout << endl;
}

void Card::Draw_Seven(int x)
{
	cout << "\t" << char(218);

	for (int y = 0; y <= 10; y++)
	{
		cout << char(196);
	}
	cout << char(191) << endl;
	cout << "\t" << char(179) << " 7         " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "     " << char(x) << "     " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   " << char(179) << endl;
	cout << "\t" << char(179) << "         7 " << char(179) << endl;
	cout << "\t" << char(192); 

	for (y = 0; y <= 10; y++)
	{
		cout << char(196);
	}

	cout << char(217);
	cout << "\t";
	this->Display_Card ();
	cout << endl;
}

void Card::Draw_Eight(int x)
{
	cout << "\t" << char(218);

	for (int y = 0; y <= 10; y++)
	{
		cout << char(196);
	}
	cout << char(191) << endl;
	cout << "\t" << char(179) << " 8         " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "     " << char(x) << "     " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   " << char(179) << endl;
	cout << "\t" << char(179) << "     " << char(x) << "     " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   " << char(179) << endl;
	cout << "\t" << char(179) << "         8 " << char(179) << endl;
	cout << "\t" << char(192); 

	for (y = 0; y <= 10; y++)
	{
		cout << char(196);
	}

	cout << char(217);
	cout << "\t";
	this->Display_Card ();
	cout << endl;
}

void Card::Draw_Nine(int x)
{
	cout << "\t" << char(218);

	for (int y = 0; y <= 10; y++)
	{
		cout << char(196);
	}
	cout << char(191) << endl;
	cout << "\t" << char(179) << " 9         " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x)  << "   "<< char(179) << endl;
	cout << "\t" << char(179) << "     " << char(x) << "     " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   "<< char(179) << endl;
	cout << "\t" << char(179) << "         9 " << char(179) << endl;
	cout << "\t" << char(192); 

	for (y = 0; y <= 10; y++)
	{
		cout << char(196);
	}

	cout << char(217);
	cout << "\t";
	this->Display_Card ();
	cout << endl;
}

void Card::Draw_Ten(int x)
{
	cout << "\t" << char(218);

	for (int y = 0; y <= 10; y++)
	{
		cout << char(196);
	}
	cout << char(191) << endl;
	cout << "\t" << char(179) << " 10        " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   " << char(179) << endl;
	cout << "\t" << char(179) << "     " << char(x) << "     " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x)  << "   "<< char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   " << char(179) << endl;
	cout << "\t" << char(179) << "     " << char(x) << "     " << char(179) << endl;
	cout << "\t" << char(179) << "   " << char(x) << "   " << char(x) << "   "<< char(179) << endl;
	cout << "\t" << char(179) << "        10 " << char(179) << endl;
	cout << "\t" << char(192); 

	for (y = 0; y <= 10; y++)
	{
		cout << char(196);
	}

	cout << char(217);
	cout << "\t";
	this->Display_Card ();
	cout << endl;
}

void Card::Draw_Jack(int x)
{
	cout << "\t" << char(218);

	for (int y = 0; y <= 10; y++)
	{
		cout << char(196);
	}
	cout << char(191) << endl;
	cout << "\t" << char(179) << " J" << char(x) << "        " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "     " << char(1) << "     " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "         J" << char(x) << char(179) << endl;
	cout << "\t" << char(192); 

	for (y = 0; y <= 10; y++)
	{
		cout << char(196);
	}

	cout << char(217);
	cout << "\t";
	this->Display_Card ();
	cout << endl;

}

void Card::Draw_Queen(int x)
{
	cout << "\t" << char(218);

	for (int y = 0; y <= 10; y++)
	{
		cout << char(196);
	}
	cout << char(191) << endl;
	cout << "\t" << char(179) << " Q" << char(x) << "        " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "     " << char(12) << "     " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "         Q" << char(x) << char(179) << endl;
	cout << "\t" << char(192); 

	for (y = 0; y <= 10; y++)
	{
		cout << char(196);
	}

	cout << char(217);
	cout << "\t";
	this->Display_Card ();
	cout << endl;
}

void Card::Draw_King(int x)
{
	cout << "\t" << char(218);

	for (int y = 0; y <= 10; y++)
	{
		cout << char(196);
	}
	cout << char(191) << endl;
	cout << "\t" << char(179) << " K" << char(x) << "        " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "     " << char(11) << "     " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "           " << char(179) << endl;
	cout << "\t" << char(179) << "         K" << char(x) << char(179) << endl;
	cout << "\t" << char(192); 

	for (y = 0; y <= 10; y++)
	{
		cout << char(196);
	}

	cout << char(217);
	cout << "\t";
	this->Display_Card ();
	cout << endl;
}
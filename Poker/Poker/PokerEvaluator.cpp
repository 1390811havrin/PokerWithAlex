#include "PokerEvaluator.h"
#include "pch.h"
#include "Card.h"
#include "Deck.h"
#include <string>
#include <iostream>

using namespace std;



PokerEvaluator::PokerEvaluator()
{
	
}

PokerEvaluator::PokerEvaluator(Deck deck)
{
	for (int i = 0; i < 7; i++)
	{
		hand[i] = deck.draw();
		if (hand[i].getSuit() == "Out Of Cards")
		{
			cout << "No more cards in the deck" << endl;
			cout << "Pres any key to exit" << endl;
			cin >> i;
			exit(0);
		}
		if (hand[i].getSuit() == "Spades")
		{
			NumOfSpades++;
		}
		if (hand[i].getSuit() == "Hearts")
		{
			NumOfHearts++;
		}
		if (hand[i].getSuit() == "Clubs")
		{
			NumOfClubs++;
		}
		if (hand[i].getSuit() == "Diamonds")
		{
			NumOfDiamonds++;
		}
	}
}

void PokerEvaluator::DiscardandDrawNew(Deck deck)
{
	NumOfSpades = 0;
	NumOfHearts = 0;
	NumOfClubs = 0;
	NumOfDiamonds = 0;

	for (int i = 0; i < 7; i++)
	{
		hand[i] = deck.draw();
		if (hand[i].getSuit() == "Spades")
		{
			NumOfSpades++;
		}
		if (hand[i].getSuit() == "Hearts")
		{
			NumOfHearts++;
		}
		if (hand[i].getSuit() == "Clubs")
		{
			NumOfClubs++;
		}
		if (hand[i].getSuit() == "Diamonds")
		{
			NumOfDiamonds++;
		}
	}
}

bool PokerEvaluator::IsRoyalFlush(Card hand[])
{
	int lowest = 10;
	string majorsuit = MajoritySuit();
	if (IsFlush(hand) == true)
	{
		for (int i = 0; i < 7; i++)
		{
			if (hand[i].getNum() < lowest && hand[i].getNum != INT_MIN && hand[i].getSuit() == majorsuit)
			{
				return false;
			}
		}
	}
	return true;
}

bool PokerEvaluator::IsStraightFlush(Card hand[])
{
	string majorsuit = MajoritySuit();
	if (IsFlush(hand) == true)
	{
		for (int i = 0; i < 7; i++)
		{

		}

	}
	return false;
}


bool PokerEvaluator::IsFlush(Card hand[])
{
	if (NumOfClubs >= 5 || NumOfDiamonds >= 5 || NumOfHearts >= 5 || NumOfSpades >= 5)
	{
		return true;
	}
	return false;
}

bool PokerEvaluator::IsSequential(Card hand[])
{
	for (int i = 0; i < 7; i++)
	{

	}
	return false;
}

string PokerEvaluator::MajoritySuit()
{
	if (NumOfClubs > NumOfDiamonds && NumOfClubs > NumOfHearts && NumOfClubs > NumOfSpades)
	{
		return "Clubs";
	}
	if (NumOfDiamonds > NumOfClubs && NumOfDiamonds > NumOfHearts && NumOfDiamonds > NumOfSpades)
	{
		return "Diamonds";
	}
	if (NumOfHearts > NumOfClubs && NumOfHearts > NumOfDiamonds && NumOfHearts > NumOfSpades)
	{
		return "Hearts";
	}
	if (NumOfSpades > NumOfClubs && NumOfSpades > NumOfDiamonds && NumOfSpades > NumOfHearts)
	{
		return "Spades";
	}
	
}

int PokerEvaluator::getLowest(Card hand[])
{
	int currentlowest = 0;
	for (int i = 0; i < 7; i++)
	{
		currentlowest = hand[i].getNum();
	}
}

PokerEvaluator::~PokerEvaluator()
{
}


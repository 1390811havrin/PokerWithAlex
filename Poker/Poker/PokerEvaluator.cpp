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

void PokerEvaluator::showHand()
{
	for (int i = 0; i < 7; i++)
	{
		hand[i].Display();
	}

}

int PokerEvaluator::GetNumCardsInMajoritySuit()
{
	int majorNum;
	string majority = MajoritySuit();
	if (majority == "Spades") majorNum = NumOfSpades;
	if (majority == "Clubs") majorNum = NumOfClubs;
	if (majority == "Hearts") majorNum = NumOfHearts;
	if (majority == "Diamonds") majorNum = NumOfDiamonds;
	return majorNum;
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

void PokerEvaluator::SortHand()
{

	sort(hand, hand + 7);
	showHand();
}

bool PokerEvaluator::IsRoyalFlush(Card hand[])
{
	int lowest = 10;
	string majorsuit = MajoritySuit();
	if (IsFlush(hand) == true)
	{
		for (int i = 0; i < 7; i++)
		{
			if (hand[i].getNumFromChar() < lowest && hand[i].getNumFromChar() != INT_MIN && hand[i].getSuit() == majorsuit)
			{
				return false;
			}
		}
	}
	return true;
}

bool PokerEvaluator::IsStraightFlush(Card hand[])
{


	vector<Card> sentHand;
	for (int i = 0; i < 7; i++) sentHand.push_back(hand[i]);
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
	int currentlowest = hand[0].getNumFromChar();
	for (int i = 1; i < 7; i++)
	{
		if (hand[i].getNumFromChar() < currentlowest) currentlowest = hand[i].getNumFromChar();
	}
	return currentlowest;
}

int PokerEvaluator::getLowest(Card hand[], string suit)
{
	int currentlowest = 500;
	for (int i = 0; i < 7; i++)
	{
		if (hand[i].getNumFromChar() < currentlowest && hand[i].getSuit() == suit) currentlowest = hand[i].getNumFromChar();
	}
	return currentlowest;
}

int PokerEvaluator::getLowest(vector<Card> hand, string suit)
{
	int currentlowest = 500;
	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i].getNumFromChar() < currentlowest && hand[i].getSuit() == suit) currentlowest = hand[i].getNumFromChar();
	}
	return currentlowest;
}

PokerEvaluator::~PokerEvaluator()
{
}


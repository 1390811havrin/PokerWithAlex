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

PokerEvaluator::PokerEvaluator(Deck &deck)
{
	for (int i = 0; i < 7; i++)
	{
		hand[i] = deck.draw();
		if (hand[i].getSuit() == "Out Of Cards")
		{
			cout << "No more cards in the deck" << endl;
			cout << "Press any key to exit" << endl;
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

void PokerEvaluator::DiscardandDrawNew(Deck &deck)
{
	NumOfSpades = 0;
	NumOfHearts = 0;
	NumOfClubs = 0;
	NumOfDiamonds = 0;

	for (int i = 0; i < 7; i++)
	{
		hand[i] = deck.draw();
		//cout << deck.size() << endl;
		if ( i == 0 && deck.size() < 7)
		{
			cout << "Out of Cards" << endl;
			cout << "Enter in 1 then hit Enter to exit" << endl;
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

void PokerEvaluator::SortHand()
{

	sort(hand, hand + 7);
	showHand();
}

bool PokerEvaluator::IsRoyalFlush()
{
	int lowest = 10;
	string majorsuit = MajoritySuit();
	int counter = 0;
	//showHand();
		for (int i = 0; i < 7; i++)
		{
			if (this->hand[i].getSuit() == majorsuit && this->hand[i].getNumFromChar() >= 10) counter++;
			//cout << counter << endl;
		}
		if (counter == 5) return true;
	return false;
}

bool PokerEvaluator::IsStraightFlush()
{
	int lowest = 0;
	string majorsuit = MajoritySuit();
	int counter = 0;
	SortHand();
	for (int i = 0; i < 7; i++)
	{
		if (this->hand[i].getSuit() == majorsuit && this->hand[i].getNumFromChar() > lowest) lowest = this->hand[i].getNumFromChar();

		for (int j = i + 1; j < 7; j++)
		{
			if (counter == 5)
			{
				return true;
			}
			if (this->hand[j].getSuit() == majorsuit && this->hand[j].getNumFromChar() == (lowest + counter)) { counter++; }
			else if(this->hand[j].getNumFromChar() == this->hand[j - 1].getNumFromChar())
			{
				 
			}
			else
			{
				if (this->hand[j].getSuit() == majorsuit)
				{
					lowest = hand[j].getNumFromChar();
					counter = 1;
				}
			}
		}

	}
	return false;
}

bool PokerEvaluator::IsFlush()
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


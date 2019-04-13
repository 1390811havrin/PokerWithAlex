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

string PokerEvaluator::evaluateHand()
{
	string result;
	if (IsFlush())
	{
		if (IsRoyalFlush())
		{
			result = "Royal Flush";
			showHand();
			return result;
		}
		else if (IsStraightFlush())
		{
			result = "Straight Flush";
			showHand();
			return result;
		}
	}
	if (IsFourOfAKind())
	{
		result = "Four of a kind";
		showHand();
		return result;
	}
	if (IsFullHouse())
	{
		result = "Full House";
		showHand();
		return result;
	}
	if (IsFlush())
	{
		result = "Flush";
		showHand();
		return result;
	}
	if (IsStraight())
	{
		result = "Straight";
		showHand();
		return result;
	}
	if (IsThreeOfAKind())
	{
		result = "Three of a kind";
		showHand();
		return result;
	}
	if (IsTwoPair())
	{
		result = "Two Pair";
		showHand();
		return result;
	}
	if (IsOnePair())
	{
		result = "One Pair";
		showHand();
		return result;
	}
	else {
		result = "High Card";
		showHand();
		return result;
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
	//showHand();
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

bool PokerEvaluator::IsFourOfAKind()
{
	int counter = 0;
	SortHand();
	for (int i = 1; i < 7; i++)
	{
		if (hand[i].getNumFromChar() == hand[i - 1].getNumFromChar()) counter++;
		if (hand[i].getNumFromChar() != hand[i - 1].getNumFromChar() && counter != 3) counter = 0;
	}
	if (counter == 3) return true;
	return false;
	// 1 1 1 3 4 4 7
	// C: 2
}

bool PokerEvaluator::IsFullHouse()
{
	int counterA = 0;
	int counterB = 0;
	int counterC = 0;
	bool newSeq = false;
	bool newNewSeq = false;
	bool newNewNewSeq = false;
	for (int i = 0; i < 7; i++)
	{
		if (hand[i].getNumFromChar() == hand[i + 1].getNumFromChar())
		{
			//first seq
			if (newSeq == false && newNewSeq == false && newNewNewSeq == false)
			{
				newSeq = true;
			}
			//second seq
			else if (newSeq == false && newNewSeq == true && newNewNewSeq == false)
			{
				newNewNewSeq == true;
			}
			//third seq found
			else if (newSeq == false && newNewSeq == false && newNewNewSeq == true)
			{
				newSeq == true;
				newNewSeq = true;
			}
		}
		if (hand[i].getNumFromChar() != hand[i + 1].getNumFromChar() && newSeq)
		{
			if (newSeq == true)
			{
				newSeq = false;
				newNewSeq = true;
			}
			if (newNewSeq == true)
			{
				newNewSeq = false;
				
			}
			if (newNewNewSeq == true)
			{

				newNewSeq == false;
			}
		}

		if (hand[i].getNumFromChar() == hand[i + 1].getNumFromChar())
		{
			if (newSeq == true && newNewSeq == false && newNewNewSeq == false)
			{
				counterA++;
			}
			else if (newSeq == false && newNewSeq == true && newNewNewSeq == true)
			{
				counterB++;
			}
			else if(newSeq == true && newNewSeq == true && newNewNewSeq == true)
			{
				counterC++;
			}
		}
	}
	if ( counterA >= 1 && counterB >= 2)
		return true;
	if (counterA >= 2 && counterB >= 1)
		return true;
	if (counterA >= 1 && counterC >= 2)
		return true;
	if (counterA >= 2 && counterC >= 1)
		return true;
	if (counterB >= 1 && counterC >= 2)
		return true;
	if (counterB >= 2 && counterC >= 1)
		return true;

	return false;
}

bool PokerEvaluator::IsStraight()
{
	SortHand();
	int count = 0;
	for (int i = 0; i < 7; i++)
	{
		//checks for sequential and counts if so
		if (hand[i].getNumFromChar() == (hand[i + 1].getNumFromChar() - 1)) 
		{
			count++;
		} //if they aren't sequential and instead ar ethe same
		else if (hand[i].getNumFromChar() == hand[i + 1].getNumFromChar())
		{

			//nothing happens
		} //if they aren't sequential and they aren't hte same hten the order resets.
		else
		{
			count = 0;

		}
	}
	if (count == 5) return true; 
	return false;
}

bool PokerEvaluator::IsThreeOfAKind()
{
	int counter = 0;
	SortHand();
	for (int i = 1; i < 7; i++)
	{
		if (hand[i].getNumFromChar() != hand[i - 1].getNumFromChar() && counter < 2)
		{
			counter = 0;
		}
		if (hand[i].getNumFromChar() == hand[i - 1].getNumFromChar()) counter++;
	}
	if (counter == 2) return true;
	return false;
}

bool PokerEvaluator::IsTwoPair()
{
	int counter3 = 0;
	int counter2 = 0;
	SortHand();
	for (int i = 0; i < 7; i++)
	{ //1 2 2 3 4 4
		if (hand[i].getNumFromChar() == hand[i + 1].getNumFromChar() && counter3 <= 1)
		{
			counter3++;

		}
		else if (hand[i].getNumFromChar() == hand[i + 1].getNumFromChar() && counter3 >= 1)
		{
			counter2++;
		}
	}
	if (counter3 >= 1 && counter2 >= 1) return true;

	return false;
}

bool PokerEvaluator::IsOnePair()
{
	int counter3 = 0;
	SortHand();
	for (int i = 0; i < 7; i++)
	{
		if (hand[i].getNumFromChar() == hand[i + 1].getNumFromChar())
		{
			counter3++;
		}
	}
	if (counter3 >= 1) return true; // 3 4 6 7 8 9 j

	return false;
}

void PokerEvaluator::IsNoPairHighCard()
{
	hand[6].Display();
	
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


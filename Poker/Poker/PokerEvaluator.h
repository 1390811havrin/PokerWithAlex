#pragma once
#include "Card.h"
#include "Deck.h"


class PokerEvaluator
{
private:
	Card hand[7];
	Card subHand[5];
	int NumOfSpades = 0;
	int NumOfHearts = 0;
	int NumOfDiamonds = 0;
	int NumOfClubs = 0;
	int Lowest = 0;
public:
	PokerEvaluator();
	PokerEvaluator(Deck deck);
	~PokerEvaluator();
#pragma region checkers
	bool IsRoyalFlush(Card hand[]);
	bool IsStraightFlush(Card hand[]);
	bool IsFourOfAKind(Card hand[]);
	bool IsFullHouse(Card hand[]);
	bool IsFlush(Card hand[]);
	bool IsStraight(Card hand[]);
	bool IsThreeOfAKind(Card hand[]);
	bool IsTwoPair(Card hand[]);
	bool IsOnePair(Card hand[]);
	bool IsNoPairHighCard(Card hand[]);
	bool IsAllSameSuit(Card hand[]);
	bool IsSequential(Card hand[]);
#pragma endregion

#pragma region utility
	void showHand();
	int GetNumCardsInMajoritySuit();
	void DiscardandDrawNew(Deck deck);
	void SortHand();
	string MajoritySuit();
	int getLowest(Card hand[]);
	int getLowest(Card hand[], string suit);
	int getLowest(vector<Card> hand, string suit);
#pragma endregion
};

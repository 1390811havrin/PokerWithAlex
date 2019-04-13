#include "pch.h"
#include "Deck.h"
#include <random>
#include <algorithm>
#include <time.h>
Deck::Deck()
{
	//cout << "Building Deck" << endl;
	string suits[] = {"Spades", "Hearts", "Clubs", "Diamonds"};
	//unrolled loop fills deck with each suit
	for (int i = 0; i < 4; i++)
	{
		Card card1('a', suits[i]);
		Card card2('j', suits[i]);
		Card card3('k', suits[i]);
		Card card4('q', suits[i]);
		Card card5(2, suits[i]);
		Card card6(3, suits[i]);
		Card card7(4, suits[i]);
		Card card8(5, suits[i]);
		Card card9(6, suits[i]);
		Card card10(7, suits[i]);
		Card card11(8, suits[i]);
		Card card12(9, suits[i]);
		Card card13(10, suits[i]);
		deckOCard.push_back(card5);
		deckOCard.push_back(card6);
		deckOCard.push_back(card7);
		deckOCard.push_back(card8);
		deckOCard.push_back(card9);
		deckOCard.push_back(card10);
		deckOCard.push_back(card11);
		deckOCard.push_back(card12);
		deckOCard.push_back(card13);
		deckOCard.push_back(card1);
		deckOCard.push_back(card2);
		deckOCard.push_back(card3);
		deckOCard.push_back(card4);
	}
}


Deck::~Deck()
{
}

void Deck::reshuffle()
{
	//cout << "Shuffling cards" << endl;
	srand(unsigned(time(0)));
	random_shuffle(deckOCard.begin(), deckOCard.end());
}

Card Deck::draw()
{

	if (this->deckOCard.size() >= 1)
	{
		//cout << "Drawing cards" << endl;
		Card drawnCard = this->deckOCard.back();
		this->deckOCard.pop_back();
		return drawnCard;
	}
	return Card('N', "Out Of Cards");
}

int Deck::size()
{
	return this->deckOCard.size();
}

void Deck::SortDeck()
{
	//sort(deckOCard.begin, deckOCard.back);
}





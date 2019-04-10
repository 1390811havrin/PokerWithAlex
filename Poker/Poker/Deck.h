#pragma once
#include "Card.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Deck
{

private:
	vector<Card> deckOCard;

public:

	Deck();
	~Deck();
	void reshuffle();
	Card draw();
	int size();

};


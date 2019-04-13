#include "pch.h"
#include "Card.h"
#include <string>
#include <iostream>

using namespace std;


bool Card::operator==(Card card)
{
	if ((this->c_num == card.c_num) && (this->num == card.num) && (this->suit == card.suit)) return true;
	
	return false;
}

bool Card::operator!=(Card card)
{
	if ((this->c_num == card.c_num) && (this->num == card.num) && (this->suit == card.suit)) return false;

	return true;
}

bool Card::operator>(Card card)
{
	//first check if this card is face
	//second check if incoming card is face
	int card1 = 0;
	int card2 = 0;
	if (this->num == INT_MIN)
	{
		if (this->c_num == 'a') card1 = 14;
		if (this->c_num == 'k') card1 = 13;
		if (this->c_num == 'q') card1 = 12;
		if (this->c_num == 'j') card1 = 11;
	}
	else {
		card1 = this->num;
	}

	if (card.num == INT_MIN)
	{
		if (card.c_num == 'a') card2 = 14;
		if (card.c_num == 'k') card2 = 13;
		if (card.c_num == 'q') card2 = 12;
		if (card.c_num == 'j') card2 = 11;
	}
	else
	{
		card2 = card.num;
	}
	if (card1 > card2) return true;
	if (card1 <= card2) return false;
	
	
}

bool Card::operator<(Card card)
{
	//first check if this card is face
	//second check if incoming card is face
	int card1 = 0;
	int card2 = 0;
	if (this->num == INT_MIN)
	{
		if (this->c_num == 'a') card1 = 14;
		if (this->c_num == 'k') card1 = 13;
		if (this->c_num == 'q') card1 = 12;
		if (this->c_num == 'j') card1 = 11;
	}
	else {
		card1 = this->num;
	}
	if (card.num == INT_MIN)
	{
		if (card.c_num == 'a') card2 = 14;
		if (card.c_num == 'k') card2 = 13;
		if (card.c_num == 'q') card2 = 12;
		if (card.c_num == 'j') card2 = 11;
	}
	else
	{
		card2 = card.num;
	}
	if (card1 < card2) return true;
	if (card1 >= card2) return false;

	
}

Card::Card()
{
	//cout << "Reach default constructor." << endl;
	this->suit = "Spades";
	this->c_num = 'a';
	this->num = INT_MIN;

}

Card::Card(int num, string suit)
{
	//cout << "Reach constructor that takes number and suit." << endl;
	this->suit = suit;
	//this->c_num = 'a';
	this->num = num;
}


Card::Card(char c_num, string suit)
{
	//cout << "Reach constructor that takes character of face card and suit." << endl;
	this->suit = suit;
	this->c_num = c_num;
	this->num = INT_MIN;
}

string Card::getSuit()
{
	return this->suit;
}

void Card::setSuit(string s)
{
	this->suit = s;
}

int Card::getNum()
{
	return this->num;
}

void Card::setNum(int n)
{
	this->num = n;
}

char Card::getc_num()
{
	return this->c_num;
}

void Card::setc_num(char c)
{
	this->c_num = c;
}

void Card::Display()
{
	if (num != INT_MIN)
	{
		cout << this->num << " of " << this->suit << endl;
	}
	else
	{
		cout << this->c_num << " of " << this->suit << endl;
	}
}

int Card::getNumFromChar()
{
	if (this->c_num == 'a') return 14;
	if (this->c_num == 'k') return 13;
	if (this->c_num == 'q') return 12;
	if (this->c_num == 'j') return 11;
	return this->num;
}



Card::~Card()
{
}

#include "pch.h"
#include "Card.h"
#include <string>
#include <iostream>

using namespace std;


Card::Card()
{
	cout << "Reach default constructor." << endl;
	this->suit = "Spades";
	this->c_num = 'a';
	this->num = INT_MIN;

}

Card::Card(int num, string suit)
{
	cout << "Reach constructor that takes number and suit." << endl;
	this->suit = suit;
	//this->c_num = 'a';
	this->num = num;
}


Card::Card(char c_num, string suit)
{
	cout << "Reach constructor that takes character of face card and suit." << endl;
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

Card::~Card()
{
}

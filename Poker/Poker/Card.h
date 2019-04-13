#pragma once
#include <string>

using namespace std;

class Card
{
	
public:
	bool operator==(Card card);
	bool operator!=(Card card);
	bool operator>(Card card);
	bool operator<(Card card);
	Card();
	Card(int num, string suit);
	Card(char c_num, string suit);
	string getSuit();
	void setSuit(string s);
	int getNum();
	void setNum(int n);
	char getc_num();
	void setc_num(char c);
	void Display();
	int getNumFromChar();

	~Card();
 private:
	string suit;
	int num;
	char c_num;
};



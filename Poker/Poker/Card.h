#pragma once
#include <string>

using namespace std;

class Card
{
	
public:
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
	~Card();
 private:
	string suit;
	int num;
	char c_num;
};


#include "pch.h"
#include "Card.h"
#include "Deck.h"
#include <iostream>

using namespace std;

#define CATCH_CONFIG_RUNNER  
#include "catch.hpp"


int main()
{
	std::cout << "Hello World!\n";

	Catch::Session().run();
	int potatoe;
	cin >> potatoe;
	return 0;
}

TEST_CASE("Test Our Cards Class()")
{
	SECTION("Testing Deck Functionality")
	{
		//generate two random decks
		Deck deck = Deck();
		Deck deck2 = Deck();
		deck.reshuffle();
		deck2.reshuffle();
		//catch.hpp doesn't like my overloaded comparators :(
		if (deck.draw() == deck2.draw())
		{
			cout << "aye" << endl;
		}
		else
		{
			cout << "fuck this alex guy" << endl;
		}
		//checks for appropriate number of cards generated
		REQUIRE(deck.size() == 51);
		REQUIRE(deck2.size() == 51);
	



	}
	/*
	SECTION("Test card generation and destruction")
	{
		Card defCard = Card();
		Card c1 = Card('q', "Spades");
		Card c2 = Card( 2, "Spades");
		Card c3 = Card('a', "Diamonds");
		Card c4 = Card(10, "Clubs");
		Card c5 = Card('k', "Hearts");
		Card c6 = Card(5, "Diamonds");
		Card c7 = Card('j', "Clubs");
		Card c8 = Card(7, "Hearts");





		REQUIRE(defCard.getNum() == INT_MIN);
		REQUIRE(defCard.getSuit() == "Spades");
		REQUIRE(defCard.getc_num() == 'a');

		REQUIRE(c1.getNum() == INT_MIN);
		REQUIRE(c1.getSuit() == "Spades");
		REQUIRE(c1.getc_num() == 'q');

		REQUIRE(c3.getNum() == INT_MIN);
		REQUIRE(c3.getSuit() == "Diamonds");
		REQUIRE(c3.getc_num() == 'a');

		REQUIRE(c5.getNum() == INT_MIN);
		REQUIRE(c5.getSuit() == "Hearts");
		REQUIRE(c5.getc_num() == 'k');

		REQUIRE(c7.getNum() == INT_MIN);
		REQUIRE(c7.getSuit() == "Clubs");
		REQUIRE(c7.getc_num() == 'j');

		REQUIRE(c2.getNum() == 2);
		REQUIRE(c2.getSuit() == "Spades");

		REQUIRE(c4.getNum() == 10);
		REQUIRE(c4.getSuit() == "Clubs");

		REQUIRE(c6.getNum() == 5);
		REQUIRE(c6.getSuit() == "Diamonds");

		REQUIRE(c8.getNum() == 7);
		REQUIRE(c8.getSuit() == "Hearts");

		c1.Display();
		c2.Display();
		c3.Display();
		c4.Display();
		c5.Display();
		c6.Display();
		c7.Display();
		c8.Display();
	}
	*/

}

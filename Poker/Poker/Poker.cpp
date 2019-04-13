#include "pch.h"
#include "Card.h"
#include "Deck.h"
#include "PokerEvaluator.h"
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

	SECTION("Testing Poker Evaluator functionality")
	{
			Deck deck = Deck();
			deck.reshuffle();

			PokerEvaluator hand1 = PokerEvaluator(deck);
			string test;
			//hand1.showHand();
			for (int i = 0; i < 8; i++)
			{
				test = hand1.evaluateHand();
				cout << test << endl;
				hand1.DiscardandDrawNew(deck);
				hand1.SortHand();
			}

			REQUIRE(hand1.IsFourOfAKind() == true);
			REQUIRE(hand1.IsRoyalFlush() == true);
			REQUIRE(hand1.IsFlush() == true);
			REQUIRE(hand1.IsStraightFlush() == true);

		/*




		REQUIRE(hand2.IsStraightFlush() == true);

		
		REQUIRE(hand2.IsFourOfAKind() == true);

		REQUIRE(hand1.IsFullHouse() == true);
		REQUIRE(hand2.IsFullHouse() == true);


		REQUIRE(hand2.IsFlush() == true);

		REQUIRE(hand1.IsStraight() == true);
		REQUIRE(hand2.IsStraight() == true);

		REQUIRE(hand1.IsThreeOfAKind() == true);
		REQUIRE(hand2.IsThreeOfAKind() == true);

		REQUIRE(hand1.IsTwoPair() == true);
		REQUIRE(hand2.IsTwoPair() == true);

		REQUIRE(hand1.IsOnePair() == true);
		REQUIRE(hand2.IsOnePair() == true);

		REQUIRE(hand1.IsNoPairHighCard() == true);
		REQUIRE(hand2.IsNoPairHighCard() == true);
		*/


	}

	SECTION("Testing Deck Functionality")
	{
		//generate two random decks
		/*
		Deck deck = Deck();
		Deck deck2 = Deck();
		deck.reshuffle();
		deck2.reshuffle();
		//catch.hpp doesn't like my overloaded comparators :(
		if (deck.draw() == deck2.draw())
		{
			cout << "equal works" << endl;
		}
		else
		{
			cout << "equal don't work" << endl;
		}
		//checks for appropriate number of cards generated
		REQUIRE(deck.size() == 51);
		REQUIRE(deck2.size() == 51);
	

	*/

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

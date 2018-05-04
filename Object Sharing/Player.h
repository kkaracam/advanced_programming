// Poyraz Kývanç Karaçam - 20967

#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
using namespace std;

class Player
{
	public:
		Player();							//Default Constructor

		Player::Player(Board &board, string name)
		: myboard(board), playerName(name)
		{ point = 0; noMove = 0; }; 		// Constructor for player object.

		bool rollDice();					// Simulates dice, until max total point and/or max total moves are reached.
		void display();						// Displays the current information of a player.
		float calculateScore();				// Calculates the final score for a player.

	private:
		Board &myboard;
		string playerName;
		int point;
		int noMove;
};

#endif
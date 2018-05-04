// Poyraz Kývanç Karaçam - 20967

#ifndef BOARD_H
#define BOARD_H

#include <string>
using namespace std;

class Board
{
	public:
		Board();				// Default constructor
		void display();			// Displays the total points and the total number of moves so far in the game.
		int Move();				// Increased by 1 every time a player rolls dice.
		int getPoints(int);		// Increased by number the dice shows.
		int totalMove();		// Shows total moves.
		int totalPoint();		// Shows total points.

	private:
		int totpoints;
		int move;
};

#endif
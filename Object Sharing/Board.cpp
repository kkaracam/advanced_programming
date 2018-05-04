// Poyraz Kývanç Karaçam - 20967

#include "Board.h"
#include <iostream>

using namespace std;

Board::Board()
{
	totpoints = 0;
	move = 0;
}

void Board::display()
{
	cout << "\nTotal moves: " << move << "\nTotal points: " << totpoints << endl;
}

int Board::totalMove()
{
	return move;
}

int Board::totalPoint()
{
	return totpoints;
}

int Board::Move()
{
	return move++;
}

int Board::getPoints(int n)
{
	return totpoints += n;
}
// Poyraz Kývanç Karaçam - 20967

#include "Player.h"
#include <random>
#include <iostream>

using namespace std;

bool Player::rollDice()
{
	random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 6);		//	"dis(gen)" simulates dice, gives a random integer between 1 and 6.
	int num;

	num = dis(gen);								// num stores the generated random number.

	if (myboard.totalMove() < 15 && myboard.totalPoint() < 50)	// If limits are not reached 
	{
		cout << "Dice: " << num << endl;
		point += num;
		noMove++;
		myboard.Move();
		myboard.getPoints(num);
		display();

		return true;
	}
	
	else
	{
		return false;							// Limits are reached, game is over.
	}

}

void Player::display()
{
	cout << "Player Name: " << playerName << endl;
	cout << "Points: " << point << endl;
	cout << "Number of Moves: " << noMove << endl;
}

float Player::calculateScore()
{
	return point*1.0 / noMove;
}